/*
 * L.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: josh
 */

#include "L.h"
#include "vector"
#include "opencv2/opencv.hpp"
#include "math.h"

L::L(){}

L::L(std::vector<cv::Point> p) {
	orientation = false;
	verticalLength = 0;
	horizontalLength = 0;
	points = p;
	topPoint = cv::Point(0, 0);
	cornerPoint = cv::Point(0, 0);
	sidePoint = cv::Point(0, 0);
	referencePoint = cv::Point(0, 0);
}

void L::setOrientation(bool o)
{
	orientation = o;
}

bool L::getOrientation()
{
	return orientation;
}

void L::configureL()
{
	determineCornerPoint();
	determineSidePoint();
	topPoint = determinePointAbove(cornerPoint);
	referencePoint = determinePointAbove(sidePoint);
	float d1 = sqrt(pow(topPoint.x - cornerPoint.x,2) + pow(topPoint.y - cornerPoint.y,2));
	float d2 = sqrt(pow(sidePoint.x - referencePoint.x,2) + pow(sidePoint.y - referencePoint.y,2));
	if (d1 < d2)
	{
		cv::Point temp1 = referencePoint;
		referencePoint = topPoint;
		topPoint = temp1;
		cv::Point temp2 = sidePoint;
		sidePoint = cornerPoint;
		cornerPoint = temp2;
		orientation = true;
	}
	calculateLength();
}

void L::calculateLength()
{
	verticalLength = sqrt(pow(topPoint.x - cornerPoint.x,2) + pow(topPoint.y - cornerPoint.y,2));
	horizontalLength = sqrt(pow(sidePoint.x - cornerPoint.x,2) + pow(sidePoint.y - cornerPoint.y,2));
}

cv::Point L::getCornerPoint()
{
	return cornerPoint;
}

cv::Point L::getTopPoint()
{
	return topPoint;
}

cv::Point L::getSidePoint()
{
	return sidePoint;
}

std::vector<cv::Point> L::getPoints()
{
	return points;
}

float L::getVerticalLength()
{
	return verticalLength;
}

float L::getHorizontalLength()
{
	return horizontalLength;
}

void L::determineCornerPoint()
{
	double maxLength = 0;
	int indexCorner;
		for (unsigned i = 0; i < points.size(); ++i)
		{
			double tempLength = sqrt(pow(points.at(i).x, 2) + pow(points.at(i).y, 2));
			if (tempLength > maxLength){
				maxLength = tempLength;
				indexCorner = i;
			}
		}
	cornerPoint = points.at(indexCorner);
}

void L::determineSidePoint() //swaps current corner point with the other bottom point
{
	double minLength = 6e6;
	int indexPoint;
		for (unsigned i = 0; i < points.size(); ++i)
		{
			if (points.at(i).x != cornerPoint.x) //compare the x values to make sure it's not secretly the same point :O
			{
				double tempLength = abs(points.at(i).y - cornerPoint.y);
				if (tempLength < minLength){
					minLength = tempLength;
					indexPoint = i;
				}
			}
		}
		sidePoint = points.at(indexPoint);
}

cv::Point L::determinePointAbove(cv::Point lowerPoint)
{
	double minLength = 6e6;
	int indexTop;
		for (unsigned i = 0; i < points.size(); ++i)
		{
			if (points.at(i).y != lowerPoint.y) //compare the y values to make sure it's not secretly the same point :O
			{
				double tempLength = abs(points.at(i).x - lowerPoint.x);
				if (tempLength < minLength){
					minLength = tempLength;
					indexTop = i;
				}
			}
		}
		return points.at(indexTop);
}


L::~L() {
	// TODO Auto-generated destructor stub
}

