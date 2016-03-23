#include"stdafx.h"
#include"Parametrs.h"

using namespace cv;
/*void BrightnessImage(int alpha)
{
//Parametrs obj;
IplImage *image = 0;
//int alp = obj.getAlpha();
//cvNamedWindow("яркость", CV_WINDOW_AUTOSIZE);
//cvCreateTrackbar("яркость", "яркость", &alp, obj.getAlphaMax(), myTrackbarBright);
//IplImage* img = cvCloneImage(image);
//cvCvtColor(image, image, CV_BGR2HSV);
for (int y = 0; y < image->height; y++) {
uchar* ptr = (uchar*)(
image->imageData + y * image->widthStep);
for (int x = 0; x < image->width; x++) {
ptr[3 * x + 2] = ptr[3 * x + 2] + alp;
}
}
cvShowImage("original", image);
/*while (true){
cvCopyImage(image, img);
cvShowImage("яркость", img);
char c = cvWaitKey(33);
if (c == 27) {
break;
}
}*/
int Parametrs::_alph = 50;

IplImage* britghtnessImage(IplImage* image)
{
	Parametrs obj;
	Mat dst;
	Mat src;
	dst = image;
	int alp = obj.getAlpha() - 50;
	double betta = obj.getAlpha() / 50.0;
	std::cout << "MyCallbackForBrightness : Contrast=" << alp << " Brightness=" << betta << std::endl;
	dst.convertTo(src, -1, betta, alp);
	imshow("original", dst);
	IplImage img = dst;
	image = &img;
	return image;
}

void mytTrackbarBrightness(int pos)
{
	Parametrs obj;
	obj.setAlpha(pos);
}

void mytTrackbarContrast(int pos)
{
	Parametrs obj;
	obj.setAlpha(pos);
}

void myMouseBrightness(int event, int x, int y, int flags, void* param)
{
	IplImage* image = (IplImage*)param;
	Parametrs obj;
	switch (event)
	{
	case CV_EVENT_MOUSEMOVE:
		image = britghtnessImage(image);
		break;
	}
}
/*void myMouseContrast(int event, int x, int y, int flags, void* param)
{
IplImage* img = (IplImage*)param;
Mat image = img;
Parametrs obj;
switch (event)
{
case CV_EVENT_LBUTTONDOWN:
image = britghtnessImage(image);
img = image;
break;
}
}*/

/*void myTrackbarContrast(int pos, void* userData)
{
	Parametrs obj;
	cv::Mat src = obj.getImage();
	int brightness = *(static_cast<int*>(userData));
	int alp = pos - 50;
	double betta = brightness / 50.0;
	src.convertTo(src, -1, betta, alp);
	obj.setImage(src);
	cv::imshow("INSTAGRAM", src);
	waitKey(0);

}*/

IplImage* Parametrs :: VisualBrightness(IplImage* image)
{
	Parametrs obj;
	IplImage* img = 0;
	img = cvCloneImage(image);
	int alp = obj.getAlpha();
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvCreateTrackbar("яркость", "original", &alp, 100, mytTrackbarBrightness);
	cvSetMouseCallback("original", myMouseBrightness, (void*)img);
	while (1)
	{
		cvCopyImage(image, img);
		cvShowImage("original", img);
		char c = cvWaitKey(33);
		if (c == 27) {
			break;
		}
	}
	return image;
}

/*void VisualBrightness(IplImage* image)
{
Parametrs obj;
//IplImage* src = 0;
int alp = obj.getAlpha();
cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
cvCreateTrackbar("яркость", "original", &alp, obj.getAlphaMax(), myTrackbarBright);
cvShowImage("original", image);
/*src = cvCloneImage(image);
cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
int alp = obj.getAlpha();
cvCreateTrackbar("яркость", "original", &alp, obj.getAlphaMax(), myTrackbarBright);
BrightnessImage(image);
while (true){
IplImage* img = BrightnessImage(image);
cvCopyImage(img, src);
cvShowImage("original", src);
delete img;
char c = cvWaitKey(33);
if (c == 27) {
break;
}
}
cvReleaseImage(&image);
cvReleaseImage(&src);
cvDestroyWindow("original");
}*/

/*void SaturationImage(IplImage* image)
{
IplImage* img;
Parametrs obj;
cvCvtColor(image, image, CV_BGR2HSV);
for (int y = 0; y<image->height; y++) {
uchar* ptr = (uchar*)(
image->imageData + y * image->widthStep);
for (int x = 0; x<image->width; x++) {
ptr[3 * x + 1] = ptr[3 * x + 1] + obj.getAlpha();
}
}
cvNamedWindow("Saturation", CV_WINDOW_AUTOSIZE);
cvShowImage("Saturation", image);

}*/
