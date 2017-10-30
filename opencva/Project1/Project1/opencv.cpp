#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	const int num = 200;
	char fileName[250];
	char windowName[250];
	Mat srcImage;

	int64 timeCount = getTickCount();		//int64  typedef long long int64

	for (int i = 1; i <= num; i++)
	{
		sprintf_s(fileName, "E:\\sample\\neg\\n_s%d.png", i);
		sprintf_s(windowName, "NO.%d", i);

		//按照图像名称读取图像
		srcImage = imread(fileName);
		//if (!srcImage.data)
		if (srcImage.empty())
		{
			cout << "文本为空!" << endl;
			exit(EXIT_FAILURE);
		}
		resize(srcImage, srcImage, Size(200, 200));
		namedWindow(windowName);
		imshow(windowName, srcImage);

		cout << "NO. " << i << " " << endl;
	}
	//timeCount = (double)(getTickCount() - timeCount) / (getTickFrequency());
	timeCount = static_cast<int64>((getTickCount() - timeCount) / getTickFrequency());
	cout << "读取200张图片共用时： " << timeCount << " s" << endl;
	waitKey(0);

	return 0;
}