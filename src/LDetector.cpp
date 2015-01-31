/*
 * LDetector.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: heidi
 */

#include <iostream>
#include <opencv2/opencv.hpp>
#include "LDetector.h"
#include <math.h>
#include "L.h"

LDetector::LDetector() {


}

void LDetector::elLoad()
{
	image = cv::imread("/home/heidi/Downloads/2FL.jpg");
	cv::imshow("OriginalImage", image);
}

void LDetector::elSplit()
{
	std::vector<std::vector<cv::Point2i> > ALLtheContours;
	std::vector<cv::Vec4i> hierarchy;
	cv::cvtColor(image, b, CV_RGB2HSV);
	cv::split(b, a); //Converted RGB to HSV, split into H S and V
}
void LDetector::elThresh()
{
	cv::threshold(a[0], hueLower, 25, 255, CV_THRESH_BINARY);
	cv::threshold(a[0], hueUpper, 50, 255, CV_THRESH_BINARY_INV);
	cv::Mat hueBoth = hueLower & hueUpper;
	//hueBoth is all greens
	cv::imshow("hue", hueBoth);

	cv::threshold(a[2], valUp, 225, 255, CV_THRESH_BINARY);
	cv::threshold(a[2], valLow, 0, 255, CV_THRESH_BINARY);
	cv::Mat valBoth = valUp & valLow;
	cv::imshow("val", valBoth);
	//valBoth is all brights

	combine = hueBoth & valBoth; //combine is final thresholded image
	cv::imshow("all.png", combine);
}
void LDetector::elFilter()
{
	for (unsigned j = 0; j < all.size(); ++j)
	{
		L L1 = L(all.at(j));
		L1.determineTopPoint();
		unsigned i = j+1;
		while(i < all.size())
		{
			L L2 = L(all.at(i));
			L2.determineTopPoint();
			if(L1.getTopPoint().x < L2.getTopPoint().x + 10 &&
					L1.getTopPoint().x > L2.getTopPoint().x - 10 &&
					L1.getTopPoint().y < L2.getTopPoint().x + 10 &&
					L1.getTopPoint().y > L2.getTopPoint().x - 10)
			{
				all.erase(all.begin()+i);
				//CODE TO REMOVE L2
			}
			else
			{
				i++;
			}

		}

	}

}


void LDetector::elContours()
{
	cv::Mat gray0(image.size(), CV_8U);
	cv::Mat gray;
	// Variable Declarations
	std::vector<std::vector<cv::Point> > contours;
	int ch[] = {0, 0};
	cv::mixChannels(&image, 1, &gray0, 1, ch, 1); // Extract Channel
	// Canny helps to catch squares with gradient shading
	// apply Canny. Take the upper threshold from slider
	// and set the lower to 0 (which forces edges merging)
	cv::Canny(combine, gray, 0, 50, 5);
	//currently testing: setting lower to 5


	// dilate canny output to remove potential
	// holes between edge segments
	dilate(gray, gray, cv::Mat());
	// erode(gray, gray, cv::Mat());
	findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);



	for (size_t i = 0; i < contours.size(); ++i)
			{
				// approximate contour with accuracy proportional
				// to the contour parametric
				cv::approxPolyDP(cv::Mat(contours.at(i)), approx, cv::arcLength(cv::Mat(contours.at(i)), true) * 0.02, true);
				// rectangular contours should have 6 vertices after approximation
				// relatively large area (to filter out noisy contours)
				// and be convex.
				// Note: absolute value of an area is used because
				// area may be positive or negative - in accordance with the
				// contour orientation

				if(approx.size() == 6
						&& LosAngles(approx) == true
						)
					all.push_back(approx);
				}
}

bool LDetector::LosAngles(std::vector<cv::Point> vect)
{
	std::vector<bool> wat;
	int a = 0, b, c;
	while (a < 6)
	{
		b = (a + 1);
		c = (a + 2);
		if (b > 5)
		{
			b = (b % 5) - 1;
		}
		if (c > 5)
		{
			c = (c % 5) - 1;
		}

		if (fabs(elAngles(vect.at(a), vect.at(c), vect.at(b))) < .2)
		{
			wat.push_back(true);
			std::cout << "tru" << std::endl;
		}
		else
		{
			wat.push_back(false);
			std::cout << "no" << std::endl;
		}
		a++;
	}
	std::cout << "\n" << std::endl;
	unsigned y = 0;
	bool returned = true;
	while (y < wat.size())
	{
		returned = returned * wat.at(y);
		y++;
	}
	return returned;
}

double LDetector::elAngles(cv::Point pt1, cv::Point pt2, cv::Point pt0)
{
	double dx1 = pt1.x - pt0.x;
	double dy1 = pt1.y - pt0.y;
	double dx2 = pt2.x - pt0.x;
	double dy2 = pt2.y - pt0.y;
	double bleh = (dx1 * dx2 + dy1 * dy2) / sqrt((dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2) + 1e-10);
	std::cout << bleh << std::endl;
	return bleh;

}
void LDetector::show()
{

	for (size_t i = 0; i < all.size(); i++)
	{

		const cv::Point* p = &all.at(i).at(0);
		int n = (int) all.at(i).size();
		cv::polylines(image, &p, &n, 1, true, cv::Scalar(0,0,255), 1, CV_AA);


	}
	cv::imshow("yes.jpg",image);
}

void LDetector::largest2()
{
	std::vector<std::vector<cv::Point> > array;
	int count = 0;
	while (count < 2)
	{
	int largeItr = 0;
	double largeSize = 0;

	for(int x = 0; x < all.size(); x++)
	{
		L temp = L(all.at(x));
		if (temp.getArea() > largeSize)
		{
			largeItr = x;
		}
	}
	array.push_back(all.at(largeItr));
	all.erase(all.begin() + largeItr);
	count++;
	}

	all = array;


}
