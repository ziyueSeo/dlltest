README



这个库有三个函数，它们实现的功能分别是：
1.`imageToEdge(uchar* imageArray, int height, int width)`函数是实现由彩色图片转化为边缘图片，它有三个参数，`uchar* imageArray`是要被处理的彩色图片数组，`int height`是要得到的边缘图片的高即行数，`int width`是要得到的边缘图片的宽即列数。

2.`uchar*  getResult()`函数是返回边缘图片数组。

3.`int  stopRendering()`函数是为了释放函数中变量的内存。相当于`delete（）`的功能。




