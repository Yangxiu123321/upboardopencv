#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void main()
{
	Mat srcImage = imread("E:\\opencvstu\\picture\\dog.jpg");
	imshow("��ԭʼͼ��",srcImage);
	Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
	Mat dstImage;
	//��ʴ
	erode(srcImage,dstImage,element);
	//����
	//dilate(srcImage,dstImage,element);
	imshow("����ʴͼ��",dstImage);
	waitKey(0);
}