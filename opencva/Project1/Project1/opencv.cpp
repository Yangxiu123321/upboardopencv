#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
using namespace cv;
using namespace std;
int main(int argc, char*argv[])
{
	Mat srcImage, grayImage, dstImage, edgeImage,grad_x,grad_y,abs_grad_x,abs_grad_y;
	srcImage = imread("E:\\opencvstu\\picture\\dog.bmp");
	if (!srcImage.data) { cout << "read Error!\r\n"; return -1; }
	//blur(srcImage,grayImage,Size(10,10));
	Sobel(srcImage,grad_x,CV_16S,1,0,3,1,1,BORDER_DEFAULT);
	convertScaleAbs(grad_x,abs_grad_x);
	imshow("x方向的分量",abs_grad_x);

	Sobel(srcImage, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	imshow("y方向的分量", abs_grad_y);
	/*GaussianBlur(srcImage,grayImage,Size(3,3),0,0);
	cvtColor(grayImage,grayImage,COLOR_BGR2BGRA);
	Canny(grayImage,edgeImage,40,30,3);*/
	/*dstImage = Scalar::all(0);
	imshow("黑色",dstImage);*/
	addWeighted(abs_grad_x,0.5,abs_grad_y,0.5,0,dstImage);
	imshow("合成图像",dstImage);
	waitKey(0);
}