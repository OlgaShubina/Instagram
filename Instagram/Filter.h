#pragma once
#include "stdafx.h"
#include"Instagram.h"
#include<opencv\cv.h>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv\highgui.h>
using namespace cv;

class Filter : public Instagram 
{
	Mat img;
	Scalar scalar;
public:
	Filter(){}
	~Filter(){}
	Filter(IplImage* imgpointer)
	{
		image = imgpointer;
	}

	void setImage(Mat img)
	{
		img = img;
	}
	Mat getImage()
	{
		return img;
	}

	
	Mat cropFade(Mat _img, Rect _roi, int _maxFadeDistance);
	void Drawing_Random_Lines(Mat image, RNG rng, int NumOfLines, int height, int width);

	Mat filterEasing(Mat img);
	Mat filterCinema(Mat img);
	Mat filterSmoth(Mat img);
	Mat Frame(Mat img);
	Mat filterOld(Mat img);
	Mat filterGray(Mat img);
};

