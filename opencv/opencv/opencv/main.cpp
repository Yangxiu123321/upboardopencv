//#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void main()
{
	Mat srcImage = imread("E:\\opencvstu\\picture\\dog.bmp");
	imshow("¡¾Ô­Ê¼Í¼¡¿",srcImage);
	Mat element = getStructuringElement(MORPH_RECT,Size(10,10));
	Mat dstImage;
	//¸¯Ê´
	//erode(srcImage,dstImage,element);
	//ÅòÕÍ
	//dilate(srcImage,dstImage,element);
	//ÂË²¨
	blur(srcImage,dstImage,Size(7,7));
	imshow("¡¾¾ùÖµÂË²¨Í¼¡¿",dstImage);
	waitKey(0);
}