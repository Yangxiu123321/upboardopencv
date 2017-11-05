//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<vector>
//
//using namespace cv;
//using namespace std;

//int main()
//{
	//首先确定构成轮廓的点集
	/*vector<Point2f> g_vsrcPoints;*/
	//向容器内存储点的坐标
/*	g_vsrcPoints.push_back(Point2f(0, 0));
	g_vsrcPoints.push_back(Point2f(0, 10));
	g_vsrcPoints.push_back(Point2f(1, 10));
	g_vsrcPoints.push_back(Point2f(2, 10));
	g_vsrcPoints.push_back(Point2f(4, 10));
	g_vsrcPoints.push_back(Point2f(0, 0))*/;
	//绘制出轮廓
	////vector<vector<Point2f>> g_vvsrcPoints(1);
	//Mat dstImage = Mat::zeros(Size(600, 600), CV_8UC3);
	//drawContours(dstImage, g_vsrcPoints, 0, Scalar(255), 3, 8);

	////计算轮廓的面积
/*	double g_dsrcArea = contourArea(g_vsrcPoints, false);
	cout << "【原始轮廓的面积为：】" << g_dsrcArea << end*/;

	////利用曲线逼近，计算逼近曲线的面积
	////首先创建一个逼近曲线
	//vector<Point2f> approx;
	//approxPolyDP(g_vsrcPoints, approx, 5, true);
	////接着计算得到的逼近曲线的面积]
	//double g_dapproxArea = contourArea(approx, true);
	//cout << "【逼近曲线围成的轮廓的面积为：】" << g_dapproxArea << endl;

	////绘制的轮廓是无法看出来的
	//imshow("【显示窗口】", dstImage);

	/*waitKey(0);

	return 0;
}*/
//#include "opencv2/opencv.hpp"
//using namespace cv;
//using namespace std;
//int main(int argc,char*argv[]) {
//	Mat srcImage,blurImage,cannyImg,grayImage;
//	srcImage = imread("E:\\opencvstu\\picture\\polygon\\3.png");
//	if (srcImage.empty()) { cout << "Read Error!"; return -1; }
//	imshow("原始图像",srcImage);
//	medianBlur(srcImage,blurImage,11);
//	imshow("滤波图像",blurImage);
//	Canny(srcImage,cannyImg,210,180,3);
//	imshow("Canny检测",cannyImg);
//	vector<Vec2f>lines;
//	HoughLines(cannyImg,lines,1, CV_PI / 180,100);
//	cout << lines.size() << endl;
//	waitKey(0);
//	return 0;
//}
/***********************************************/
#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("E:\\opencvstu\\picture\\polygon\\4.bmp");
	imshow("【原图】", srcImage);

	//首先对图像进行空间的转换
	Mat grayImage;
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);
	//对灰度图进行滤波
	GaussianBlur(grayImage, grayImage, Size(3, 3), 0, 0);
	imshow("【滤波后的图像】", grayImage);

	//为了得到二值图像，对灰度图进行边缘检测
	Mat cannyImage;
	Canny(grayImage, cannyImage, 128, 255, 3);
	//在得到的二值图像中寻找轮廓
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(cannyImage, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));

	//绘制轮廓
	for (int i = 0; i < (int)contours.size(); i++)
	{
		drawContours(cannyImage, contours, i, Scalar(255), 1, 8);
	}
	imshow("【处理后的图像】", cannyImage);

	//计算轮廓的面积
	for (int i = 0; i < (int)contours.size(); i++)
	{
		double g_dConArea = contourArea(contours[i], true);
		double g_dLength = arcLength(contours[i],true);
		cout << "【用轮廓面积计算函数计算出来的第" << i << "个轮廓的面积为：】" << g_dConArea  << endl;
		cout << "【周长为:】" << g_dLength << endl;
	}

	waitKey(0);

	return 0;
} 