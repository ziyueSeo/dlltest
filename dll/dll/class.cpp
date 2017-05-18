#include "stdafx.h"
#include "class.h"

using namespace std;
using namespace cv;
ImageToEdge::ImageToEdge(Mat img){
	image = img;
};
Mat ImageToEdge::edgeImge(){
	cvtColor(image, image, CV_RGB2GRAY);
	Canny(image, image, 0, 30, 3);
	//result = image.data;
	return image;
};