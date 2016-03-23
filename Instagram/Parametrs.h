#ifndef PARAMETRS_H
#define PARAMETRS_H
#include "stdafx.h"
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include"Instagram.h"

using namespace cv;

class Parametrs : public Instagram
{ 
private:
	IplImage* image;
	static int _alph;
	const int _alph_max = 100;
public:
	Parametrs(){}
	~Parametrs(){}

	Mat getImage()
	{
		return image;
	}
	IplImage setImage(IplImage* mat)
	{
		image = mat;
	}
	void setAlpha(int a) {
		_alph = a;
	}
	int getAlpha(){
		return _alph;
	}
	int getAlphaMax(){
		return _alph_max;
	}


	IplImage* VisualBrightness(IplImage* image);
	void myTrackbarBright(int pos);
	

};
#endif


