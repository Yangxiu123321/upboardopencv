#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
using namespace cv;
using namespace std;
int main(int argc, char*argv[])
{
	Mat srcImage, grayImage, imgColor, contoursImage;
	srcImage = imread("E:\\opencvstu\\picture\\dog.jpg",0);
	if (!srcImage.data) { cout << "read Error!\r\n"; return -1; }
	//cvtColor(srcImage,grayImage,COLOR_BGR2GRAY);
	//GaussianBlur(grayImage, grayImage, Size(3, 3), 3, 3);
	////blur(grayImage,grayImage,Size(3,3));
	threshold(srcImage, grayImage,100,255, CV_THRESH_OTSU);
	imshow("1", srcImage);
	//bitwise_not(grayImage,grayImage);//黑白图像反转
	//对图像进行二值化
	imshow("2", grayImage);
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(grayImage,contours, hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_NONE);
	Mat resultImage = Mat::zeros(srcImage.size(), CV_8U);
	drawContours(resultImage, contours, -1, Scalar(255, 0, 255));
	imshow("轮廓图像", resultImage);
	waitKey(0);
}