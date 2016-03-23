#pragma once
#include "stdafx.h"
#include<opencv\cv.h>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv\highgui.h>

class Instagram
{
protected:
	IplImage* image;
	char filename;
public:
	Instagram(){}
	~Instagram(){}
	void setImage(IplImage* img)
	{
		this->image = img;
	}
	IplImage* getImage()
	{
		return image;
	}
	void setFilename(char file)
	{
		this->filename = file;
	}
	char getFilename()
	{
		return filename;
	}

};

