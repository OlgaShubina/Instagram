#pragma once
#include "stdafx.h"
#include"Instagram.h"
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <stdlib.h>
#include <stdio.h>

class Crop : public Instagram
{
	IplImage* image;
	static int radius;
	const int radius_max = 1000;

public:
	Crop(){}
	~Crop(){}

	void setRadius(int r) {
		radius = r;
	}

	int getRadius(){
		return radius;
	}


	int getRadiusMax(){
		return radius_max;
	}
	void CropImage(IplImage* image, int x, int y);
	void Rectangle(IplImage* image, int x, int y);
	IplImage* VisualCrop(IplImage* image);
};
