#ifndef DLLFUNCTION_H
#define DLLFUNCTION_H
#define _EXTERN_C_  extern "C"  _declspec(dllexport)
#include "class.h"


#include <opencv2/opencv.hpp>



ImageToEdge *edgeRender;


//_EXTERN_C_ int  startRendering(int showWindow);


_EXTERN_C_ int imageToEdge(uchar* imageArray, int height, int width);


_EXTERN_C_ uchar*  getResult();

_EXTERN_C_ int  stopRendering();

#endif