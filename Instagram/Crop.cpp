#include"stdafx.h"
#include"Crop.h"
using namespace cv;

void myTrackbarRadius(int pos) {
	Crop obj;
	obj.setRadius(pos);
}

int Crop::radius = 100;

void Crop::CropImage(IplImage* image, int x, int y)
{
	Crop obj;
	IplImage* crop;
	cvSetImageROI(image, cvRect(x - obj.getRadius() / 2, y - obj.getRadius() / 2, obj.getRadius(), obj.getRadius()));
	IplImage *cropSource = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	cvCopy(image, cropSource, NULL);
	cvResetImageROI(image);
	crop = cvCreateImage(cvSize(500, 500), image->depth, image->nChannels);
	cvResize(cropSource, crop, 2);
	cvNamedWindow("CropImage", CV_WINDOW_AUTOSIZE);
	cvShowImage("CropImage", crop);
}
void Crop::Rectangle(IplImage* image, int x, int y)
{
	Crop obj;
	cvRectangle(image, cvPoint(x - obj.getRadius() / 2, y - obj.getRadius() / 2), cvPoint(x - obj.getRadius() / 2 + obj.getRadius(), y - obj.getRadius() / 2 + obj.getRadius()), cvScalar(0, 0, 0, 255), 3);
	/*if ((x>obj.getRadius())&&(y>obj.getRadius()))
	{
		cvSetImageROI(image, cvRect(x - obj.getRadius() / 2, y - obj.getRadius() / 2, obj.getRadius(), obj.getRadius()));
		IplImage *rect = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
		cvCopy(image, rect, NULL);
		cvCopyMakeBorder(rect, rect, cvPoint(10, 10), IPL_BORDER_CONSTANT, cvScalar(250));
		cvResetImageROI(image);
	}*/
}
void myMouseCallback(int event, int x, int y, int flags, void* param)
{
	IplImage* img = (IplImage*)param;
	IplImage* copy = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);
	//IplImage* rect = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);
	cvCopy(img, copy, NULL);
	//cvCopy(img, rect, NULL);
	Crop obj;
	switch (event){
	case CV_EVENT_LBUTTONDOWN:
		obj.CropImage(img, x, y);
		break;
	case CV_EVENT_MOUSEMOVE:
		obj.Rectangle(copy, x, y);
		cvShowImage("original", copy);
		break;

	/*case CV_EVENT_RBUTTONDOWN:
		cvShowImage("Rect", img);
		break;*/
	}
	
}

IplImage* Crop::VisualCrop(IplImage* image)
{
	Crop obj;
	IplImage* src = 0;
	IplImage* copy = cvCloneImage(image);
	src = cvCloneImage(image);
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvShowImage("original", image);
	int rad = obj.getRadius();
	cvCreateTrackbar("Radius", "original", &rad, obj.getRadiusMax(), myTrackbarRadius);
	cvSetMouseCallback("original", myMouseCallback, (void*)image);
	while (1){
		cvCopyImage(image, src);
		cvShowImage("original", image);
		char c = cvWaitKey(33);
		if (c == 27) {
			break;
		}		
	}
	cvReleaseImage(&image);
	cvReleaseImage(&src);
	cvDestroyWindow("original");
	return image;
}