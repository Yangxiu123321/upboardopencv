//#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void main()
{
	Mat srcImage = imread("E:\\opencvstu\\picture\\dog.bmp");
	imshow("��ԭʼͼ��",srcImage);
	Mat element = getStructuringElement(MORPH_RECT,Size(10,10));
	Mat dstImage;
	//��ʴ
	//erode(srcImage,dstImage,element);
	//����
	//dilate(srcImage,dstImage,element);
	//�˲�
	blur(srcImage,dstImage,Size(7,7));
	imshow("����ֵ�˲�ͼ��",dstImage);
	waitKey(0);
}