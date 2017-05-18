#ifndef EDEG_RENDER_H
#define EDEG_RENDER_H
#include <opencv2/opencv.hpp>
using namespace cv;


class ImageToEdge{

private:
	//uchar* result;
	Mat image;
	//int parameter;
public:
	ImageToEdge();
	ImageToEdge(Mat img);
	~ImageToEdge(){};
	Mat edgeImge();

};




#endif