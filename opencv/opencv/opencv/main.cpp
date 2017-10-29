#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void main()
{
	Mat srcImage = imread("E:\\opencvstu\\picture\\dog.jpg");
	imshow("°æ‘≠ ºÕº°ø",srcImage);
	Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
	Mat dstImage;
	//∏Ø ¥
	erode(srcImage,dstImage,element);
	//≈Ú’Õ
	//dilate(srcImage,dstImage,element);
	imshow("°æ∏Ø ¥Õº°ø",dstImage);
	waitKey(0);
}