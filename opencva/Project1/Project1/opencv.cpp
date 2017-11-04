#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
using namespace cv;
using namespace std;
int main(int argc, char*argv[])
{
	const int num = 7;
	char filename[50];
	char windowname[30];
	Mat srcImage, grayImage, dstImage, edgeImage;
	for (int i = 0; i < num; i++)
	{
		sprintf_s(filename,100,"E:\\opencvstu\\picture\\number\\%d.jpg",i);
		cout << filename << endl;
		sprintf_s(windowname, 100, "windowname【%d】", i);
		cout << windowname << endl;
		srcImage = imread(filename);
		if (!srcImage.data) { std::cout << "Read Error!" << std::endl; return -1; }
		namedWindow(windowname,1);
		imshow(windowname,srcImage);
	}
	waitKey(0);
}