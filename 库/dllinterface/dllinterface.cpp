// dllinterface.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include"dllinterface.h"
#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
uchar* ArrayToEdgeImg(uchar* ch, int i, int j)
{
	int t = 0;
	//uchar img_1[];
	for (int a = 0; a<i*j; a++)
		if (ch[a] == 0)t++;
	if (t >= i*j - 10){ cout << "you input a wrong image"; return (uchar*)(-1); }
	Mat img = Mat::zeros(i, j, CV_8UC1);
	for (int a = 0; a<i; a++)
		for (int b = 0; b<j; b++)
			img.at<uchar>(a, b) = ch[a*j + b];
	Canny(img, img, 80, 100);
	//namedWindow("frame", 1);
	//imshow("frame", img);
	for (int a = 0; a<i; a++)
		for (int b = 0; b<j; b++)
			ch[a*j + b]=img.at<uchar>(a, b);
	return ch;
};




