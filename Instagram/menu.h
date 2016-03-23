#pragma once
#include<opencv\cv.h>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv\highgui.h>
#include"stdafx.h"
#include"Crop.h"
#include<stdio.h>
#include<stdlib.h>
#include"Parametrs.h"
#include"Filter.h"
#include"Instagram.h"


using namespace cv;

class Menu: public Instagram
{
public:
	IplImage* loadImage();
	//void myMouseFilterMenu(int event, int x, int y, int flags, void* param);
    //void myMouseMenu(int event, int x, int y, int flags, void* param);
	void FilterMenu(IplImage* img);

	
};
