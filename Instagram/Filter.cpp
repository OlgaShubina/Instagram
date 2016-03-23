#include"stdafx.h"
#include"Filter.h"
Mat Filter::cropFade(Mat _img, Rect _roi, int _maxFadeDistance)
{
	Mat fadeMask = Mat::ones(_img.size(), CV_8UC1);
	rectangle(fadeMask, _roi, Scalar(0), -1);

	//imshow("mask",fadeMask>0);

	Mat dt;
	distanceTransform(fadeMask > 0, dt, CV_DIST_L2, CV_DIST_MASK_PRECISE);

	double maxFadeDist;

	if (_maxFadeDistance > 0)
		maxFadeDist = _maxFadeDistance;
	else
	{

		double min, max;
		minMaxLoc(dt, &min, &max);
		maxFadeDist = max;
	}

	dt = 1.0 - (dt* 1.0 / maxFadeDist);

	//imshow("blending mask", dt);

	Mat imgF;
	_img.convertTo(imgF, CV_32FC3);


	vector<Mat> channels;
	split(imgF, channels);

	for (unsigned int i = 0; i<channels.size(); ++i)
		channels[i] = channels[i].mul(dt);

	Mat outF;
	merge(channels, outF);

	Mat out;
	outF.convertTo(out, CV_8UC3);

	return out;
}

static Scalar randomColor(RNG& rng)
{
	return Scalar(150, 150, 150);
}

void Filter::Drawing_Random_Lines(Mat image, RNG rng, int NumOfLines, int height, int width)
{
	int lineType = 1;
	Point pt1, pt2;

	for (int i = 0; i < NumOfLines; i++)
	{
		pt1.x = rng.uniform(0, width);
		pt1.y = rng.uniform(0, height);
		pt2.x = rng.uniform(20, width);
		pt2.y = rng.uniform(15, height);

		line(image, pt1, pt2, randomColor(rng), rng.uniform(1, 1), 1);
		imshow("border", image);
	}
}

Mat Filter::filterGray(Mat img)
{
	Filter obj;
	Mat gray;
	int width = img.rows;
	int height = img.cols;
	cvtColor(img, gray, CV_BGR2GRAY);
	Rect _roi = cvRect(img.cols / 2.7, img.rows / 2.7, img.cols / 4.0, img.rows / 4.0);
	img = cropFade(gray, _roi, 100);
	imshow("border", img);
	return img;
}

Mat Filter::filterEasing(Mat img)
{
	Filter obj;
	Mat src;
	bilateralFilter(img, src, 15, 80, 80);
	src += CV_RGB(120, 50, 0);
	src *= 0.6;
	obj.setImage(src);
	imshow("border", src);
	waitKey(0);
	return src;
}

Mat Filter::filterCinema(Mat img)
{
	Filter obj;
	Mat src;
	int width, height;
	width = src.rows;
	height = src.cols;
	img += CV_RGB(50, 10, 0);
	medianBlur(img, src, 3);
	Rect _roi = cvRect(src.cols / 2.7, src.rows / 2.7, src.cols / 4.0, src.rows / 4.0);
	img = cropFade(src, _roi, 100);
	obj.setImage(img);
	imshow("border", img);
	waitKey(0);
	return img;
}

Mat Filter::filterSmoth(Mat img)
{
	Filter obj;
	Mat src;
	bilateralFilter(img, src, 15, 80, 80);
	obj.setImage(src);
	return src;
}

Mat Filter::filterOld(Mat img)
{
	Mat gray;
	int height = img.cols, width = img.rows;
	//Mat image = Mat::zeros(height, width, CV_8UC3 );
	//namedWindow( "Source", CV_WINDOW_AUTOSIZE );
	//cvtColor(img, gray, CV_BGR2GRAY);
	for (int i = 0; i<3; i++)
	{
		Drawing_Random_Lines(img, i, 3, height, width);
		imshow("border", img);
		waitKey(100);
	}
	cvtColor(img, gray, CV_BGR2GRAY);
	medianBlur(gray, img, 3);
	return img;
}

Mat Filter::Frame(Mat img)
{
	Filter obj;
	Mat dst;
	int borderType = 0;
	int c;
	Scalar value;
	int top, bottom, left, right;
	RNG rng(12345);
	top = (int)(0.05*img.rows); bottom = (int)(0.05*img.rows);
	left = (int)(0.05*img.cols); right = (int)(0.05*img.cols);
	dst = img;
	imshow("Change", dst);
	while (true)
	{
		c = waitKey(500);

		if ((char)c == 27)
		{
			break;
		}
		else if ((char)c == 'c')
		{
			borderType = BORDER_CONSTANT;
		}
		else if ((char)c == 'r')
		{
			borderType = BORDER_REPLICATE;
		}
		value = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		copyMakeBorder(img, dst, top, bottom, left, right, borderType, value);
		imshow("Change", dst);
		waitKey(0);
		obj.setImage(dst);
	}

	return dst;
}