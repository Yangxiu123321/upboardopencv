
//--------------------------------------【程序说明】-------------------------------------------
//		程序说明：《OpenCV3编程入门》OpenCV3版书本配套示例程序49
//		程序描述：漫水填充floodFill函数用法示例
//		开发测试所用操作系统： Windows 7 64bit
//		开发测试所用IDE版本：Visual Studio 2010
//		开发测试所用OpenCV版本：	3.0 beta
//		2014年11月 Created by @浅墨_毛星云
//		2014年12月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------


//---------------------------------【头文件、命名空间包含部分】----------------------------
//		描述：包含程序所使用的头文件和命名空间
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#define WINDOWS_NAME "【效果图】"
using namespace cv;
using namespace std;
int g_SlideV1 = 1;
int g_SlideV2 = 254;
int g_SlideV1Min = 254;
int g_SlideV2Max = 254;
Mat src;
Mat src1, src2;
Rect ccomp;

//-----------------------------------【main( )函数】--------------------------------------------  
//      描述：控制台应用程序的入口函数，我们的程序从这里开始  
//----------------------------------------------------------------------------------------------- 
void on_TrackBar(int ,void *) {
	src = src1.clone();
	floodFill(src, Point(50, 300),/*1*/ Scalar(255, 0, 0), &ccomp, Scalar(g_SlideV1, g_SlideV1, g_SlideV1), Scalar(g_SlideV2, g_SlideV2, g_SlideV2));
	imshow(WINDOWS_NAME, src);
	cout <<"V1 is " <<g_SlideV1 << endl;
	cout <<"V2 is " << g_SlideV2 << endl;

}
int main(int argv,char*argc[])
{
	src = imread("E:\\opencvupboard\\opencva\\Project1\\Project1\\1.jpg");
	src1 = src.clone(); src2 = src.clone();
	imshow("【原始图】", src);
	namedWindow(WINDOWS_NAME,1);
	char g_MinName[100];
	sprintf_s(g_MinName,20,"min:1", g_SlideV1);
	char g_MaxName[100];
	sprintf_s(g_MaxName, 20, "max:1", g_SlideV2);
	createTrackbar(g_MinName, WINDOWS_NAME, &g_SlideV1, g_SlideV1Min, on_TrackBar);
	createTrackbar(g_MaxName, WINDOWS_NAME, &g_SlideV2, g_SlideV2Max, on_TrackBar);
	on_TrackBar(g_SlideV1, 0);
	on_TrackBar(g_SlideV2, 0);
	waitKey(0);
	return 0;
}