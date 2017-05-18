// dll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include"function.h"
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
static uchar* result;
int imageToEdge(uchar* imageArray, int height, int width){
	Mat img = Mat::ones(height, width, CV_8UC3);
	uchar* img_1 = img.data;
	if (height == 0 || width == 0)
	{
		cout << "you enter an error high or wide;";
		return -1;
	}
	if (*imageArray == NULL)return -2;
	for (int i = 0; i < height*width * 3; i++)
	{
		*img_1 = *imageArray;
		img_1++;
		imageArray++;
	}
	edgeRender = new ImageToEdge(img);
	//result = new uchar;
	cv::Mat result_image = edgeRender->edgeImge();
	result = result_image.data;
	return 1;
};
uchar*  getResult(){
	return result;
};
int  stopRendering(){
	//delete[] result;
	delete edgeRender;
	return 1;
};


