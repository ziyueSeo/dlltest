// dll_test.cpp : 定义控制台应用程序的入口点。
//
#pragma comment( lib, "opencv_highgui2413.lib" ) 
#pragma comment( lib, "vfw32.lib" )  
#pragma comment( lib, "comctl32.lib" )

#include "stdafx.h"
#include"dllinterface.h"
#include<opencv2/opencv.hpp>
#include<imgproc/imgproc.hpp>
#include<highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/core/core.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int _tmain(int argc, _TCHAR* argv[])
{
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cout << "wrong open the cap." << endl;
		return -1;
	}
	namedWindow("frame", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame;
		uchar img[480 * 480];
		if (frame.empty())
			break;
		resize(frame, frame, Size(480, 480));
		cvtColor(frame, frame, CV_BGR2GRAY);
		for (int i = 0; i < frame.rows; i++)
			for (int j = 0; j < frame.cols; j++)
				img[i*frame.cols + j] = frame.at<uchar>(i, j);
		uchar* img_1 ;
		img_1=ArrayToEdgeImg(img, 480, 480);
		for (int i = 0; i < frame.rows; i++)
			for (int j = 0; j < frame.cols; j++)
				frame.at<uchar>(i, j)=img_1[i*frame.cols + j] ;
		if (waitKey(30) >= 1)
			break;
		imshow("frame", frame);
	}
	return 0;
}

