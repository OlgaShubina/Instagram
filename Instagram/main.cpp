#include"stdafx.h"
#include"menu.h"
#include"Crop.h"
#include"Filter.h"
#include"Instagram.h"
#include "Parametrs.h"

void myMouseMenu(int event, int x, int y, int flags, void* param)
{
	Filter obj;
	Crop obj1;
	Menu obj2;
	Parametrs obj3;
	Instagram inst;
	IplImage* img = (IplImage*)param;
	IplImage* image1 = cvLoadImage("1.jpg", CV_LOAD_IMAGE_COLOR);
	Mat image = img;
	IplImage* copy = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);
	cvCopy(img, copy, NULL);
	switch (event){
	case CV_EVENT_MOUSEMOVE:
		if ((75 < x) && (x < 155) && (y>115) && (y < 175))
		{
			cvRectangle(copy, cvPoint(60, 95), cvPoint(160, 185), cvScalar(100, 150, 255, 0), 2);
			cvShowImage("Instagram", copy);
		}
		if ((45 < x) && (x < 150) && (y>215) && (y < 315))
		{
			cvRectangle(copy, cvPoint(45, 215), cvPoint(150, 315), cvScalar(100, 150, 255, 0), 2);
			cvShowImage("Instagram", copy);
		}
		if ((70 < x) && (x < 135) && (y>350) && (y < 455))
		{
			cvRectangle(copy, cvPoint(50, 345), cvPoint(145, 460), cvScalar(100, 150, 255, 0), 2);
			cvShowImage("Instagram", copy);
		}
		if ((705 < x) && (x < 780) && (y>95) && (y < 175))
		{
			cvRectangle(copy, cvPoint(695, 85), cvPoint(795, 180), cvScalar(100, 150, 255, 0), 2);
			cvShowImage("Instagram", copy);
		}
		if ((705 < x) && (x < 805) && (y>215) && (y < 315))
		{
			cvRectangle(copy, cvPoint(695, 210), cvPoint(810, 325), cvScalar(100, 150, 255, 0), 2);
			cvShowImage("Instagram", copy);
		}
		if ((695 < x) && (x < 795) && (y>360) && (y < 460))
		{
			cvRectangle(copy, cvPoint(685, 355), cvPoint(795, 465), cvScalar(100, 150, 255, 0), 2);
			cvShowImage("Instagram", copy);
		}
		break;

	case CV_EVENT_LBUTTONDOWN:
		if ((75 < x) && (x < 155) && (y>115) && (y < 175))
		{
			cvSaveImage("result.jpg", image1);
		}
		if ((45 < x) && (x < 150) && (y>215) && (y < 315))
		{
			obj3.VisualBrightness(image1);
		}
		if ((70 < x) && (x < 135) && (y>350) && (y < 455))
		{
			cvRectangle(copy, cvPoint(50, 345), cvPoint(145, 460), cvScalar(100, 150, 255, 0), 2);
			cvShowImage("Instagram", copy);
		}
		if ((705 < x) && (x < 780) && (y>95) && (y < 175))
		{
			obj.Frame(image1);
		}
		if ((705 < x) && (x < 805) && (y>215) && (y < 315))
		{
			obj2.FilterMenu(image1);
		}
		if ((695 < x) && (x < 795) && (y>360) && (y < 460))
		{
			obj1.VisualCrop(image1);
		}
		break;
	}
}

int main(int argc, char* argv[])
{
	Parametrs obj;
	Crop obj1;
	Filter obj2;
	Instagram inst;
	Menu obj3;
	IplImage* menu = cvLoadImage("menu.jpg", CV_LOAD_IMAGE_COLOR);
	IplImage* src = 0;
	src=cvCloneImage(menu);
	Mat img = cvLoadImage("menu.jpg", 1);
	cvNamedWindow("Instagram", CV_WINDOW_AUTOSIZE);
	cvShowImage("Instagram", menu);
	//char filename;
	IplImage* image;
	//std::cout << "Enter the file" << std::endl;
	//std::cin >> filename;
	image = cvLoadImage("1.jpg", CV_LOAD_IMAGE_COLOR);
	
	cvNamedWindow("Change", CV_WINDOW_AUTOSIZE);
	cvShowImage("Change", image);
	cvSetMouseCallback("Instagram", myMouseMenu, (void*)menu);
	while (1){
		cvCopyImage(menu, src);
		cvShowImage("Instagram", menu);
		char c = cvWaitKey(33);
		if (c == 27) {
			break;
		}
	}
	//cvNamedWindow("1", CV_WINDOW_AUTOSIZE);
	//menu = obj1.VisualCrop(menu);
	//img = obj2.filterSmoth(img);
	
	//imshow("1", img);
	waitKey(0);
	return 0;
	system("PAUSE");
}

