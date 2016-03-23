#include"stdafx.h"
#include"Instagram.h"
#include"Filter.h"
#include"Parametrs.h"
#include"Crop.h"
#include<opencv\cv.h>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv\highgui.h>
#include"menu.h"

void myMouseFilterMenu(int event, int x, int y, int flags, void* param)
{
	Filter obj;
	Instagram inst;
	IplImage* img = (IplImage*)param;
	IplImage* image = cvLoadImage("1.jpg", CV_LOAD_IMAGE_COLOR);
	IplImage* copy = 0;
	switch (event)
	{
	case CV_EVENT_MOUSEMOVE:
		if ((x>80) && (x < 135) && (y>35) && (y < 90))
		{
			cvRectangle(copy, cvPoint(80, 35), cvPoint(135, 90), cvScalar(0, 0, 255, 0), 2);
			cvShowImage("Filter", copy);
		}
		if ((x>80) && (x < 135) && (y>35) && (y < 90))
		{
			cvRectangle(copy, cvPoint(80, 35), cvPoint(135, 90), cvScalar(0, 0, 255, 0), 2);
			cvShowImage("Filter", copy);

		}
		if ((x>14) && (x < 70) && (y>135) && (y < 190))
		{
			cvRectangle(copy, cvPoint(14, 135), cvPoint(70, 190), cvScalar(0, 0, 255, 0), 2);
			cvShowImage("Filter", copy);

		}
		if ((x>125) && (x < 175) && (y>135) && (y < 190))
		{
			cvRectangle(copy, cvPoint(125, 135), cvPoint(175, 190), cvScalar(0, 0, 255, 0), 2);
			cvShowImage("Filter", copy);

		}
		if ((x>540) && (x < 600) && (y>35) && (y < 90))
		{
			cvRectangle(copy, cvPoint(540, 35), cvPoint(600, 90), cvScalar(0, 0, 255, 0), 2);
			cvShowImage("Filter", copy);

		}
		if ((x>495) && (x < 530) && (y>125) && (y < 190))
		{
			cvRectangle(copy, cvPoint(495, 125), cvPoint(530, 190), cvScalar(0, 0, 255, 0), 2);
			cvShowImage("Filter", copy);

		}
	case CV_EVENT_LBUTTONDOWN:
		if ((x>80) && (x < 135) && (y>35) && (y < 90))
		{
			obj.filterCinema(image);
		}
		if ((x>80) && (x < 135) && (y>35) && (y < 90))
		{
			obj.filterEasing(image);

		}
		if ((x>14) && (x < 70) && (y>135) && (y < 190))
		{
			obj.filterGray(image);

		}
		if ((x>125) && (x < 175) && (y>135) && (y < 190))
		{
			obj.filterOld(image);

		}
		if ((x>540) && (x < 600) && (y>35) && (y < 90))
		{
			obj.filterSmoth(image);

		}
		if ((x>495) && (x < 530) && (y>125) && (y < 190))
		{


		}
	}


}

IplImage* Menu ::loadImage()
{
	Instagram inst;
	char* falename=0;
	std::cout << "Enter the name of file" << std::endl;
	std::cin >> falename;
	IplImage* image = cvLoadImage("falename", CV_LOAD_IMAGE_COLOR);
	inst.setFilename(filename);
	inst.setImage(image);
	return image;
}

void Menu::FilterMenu(IplImage* img)
{
	IplImage* menu = cvLoadImage("1108.jpg", CV_LOAD_IMAGE_COLOR);
	IplImage* src = 0;
	src = cvCloneImage(menu);
	cvShowImage("Filter", menu);
	cvNamedWindow("Filter", CV_WINDOW_AUTOSIZE);
	cvShowImage("Filter", menu);
	cvSetMouseCallback("Filter", myMouseFilterMenu, (void*)menu);
	while (1){
		cvCopyImage(menu, src);
		cvShowImage("Instagram", menu);
		char c = cvWaitKey(33);
		if (c == 27) {
			break;
		}
	}
}

void SaveImage(IplImage* image)
{
	cvSaveImage("result.jpg", image);
}






