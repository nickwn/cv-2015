/*LProcessor.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: josh
 */

#include "LProcessor.h"
#include "L.h"
#include <iostream>


void LProcessor::determineL(std::vector<std::vector<cv::Point> > points){
	firstL = L(points.at(0));
	secondL = L(points.at(1));
	firstL.configureL();
	secondL.configureL();
}

float LProcessor::getAzimuth()
{
	return azimuth;
}

float LProcessor::getDistanceFullHorizontal()
{
	return distanceFullHorizontal;
}

float LProcessor::getDistanceVertical()
{
	return distanceVertical;
}


cv::Point LProcessor::determineCenter()
{
	std::vector<cv::Point> fPoints = firstL.getPoints();
	float x1 = 0;
	float y1 = 0;
	for(int i = 0; i < fPoints.size(); i++)
	{
		x1 += fPoints.at(i).x;
		y1 += fPoints.at(i).y;
	}
	float avgX1 = x1/fPoints.size();
	float avgY1 = y1/fPoints.size();
	std::vector<cv::Point> sPoints = secondL.getPoints();
	float x2 = 0;
	float y2 = 0;
	for(int i = 0; i < sPoints.size(); i++)
	{
		x2 += sPoints.at(i).x;
		y2 += sPoints.at(i).y;
	}
	float avgX2 = x2/sPoints.size();
	float avgY2 = y2/sPoints.size();
	float avgX = (avgX1 + avgX2)/2;
	float avgY = (avgY1 + avgY2)/2;
	return cv::Point(avgX, avgY);
}


void LProcessor::determineAzimuth()
{
	azimuth = (((float)imgWidth/2.0)-(float)determineCenter().x)/ focalLength;
}

void LProcessor::determineDistance()
{
/*
 Currently the distance is calculated using the horizontal length between the side points of each L.
 Additionally, length is calculated using the shorter vertical distance of both L's.
 */
float lengthFullHorizontal = sqrt(pow(firstL.getSidePoint().x - secondL.getSidePoint().x,2) + pow(firstL.getSidePoint().y - secondL.getSidePoint().y,2));
distanceFullHorizontal = 0.425458 / lengthFullHorizontal * focalLength;
float lengthVertical = (firstL.getVerticalLength() + secondL.getVerticalLength()) / 2; //fmin(firstL.getVerticalLength(), secondL.getVerticalLength());
distanceVertical = 0.1778 / lengthVertical * focalLength;
}

void LProcessor::outputData()
{
	std::string dir[2] = {"Left Facing", "Right Facing"};
	std::cout << "Final Results" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "L1: " << "Horizontal Length [In Pixels]: " << firstL.getHorizontalLength() << ", Vertical Length [In Pixels]: " << firstL.getVerticalLength() << ", Orientation: " << dir[firstL.getOrientation()] << std::endl;
	std::cout << "L2: " << "Horizontal Length [In Pixels]: " << secondL.getHorizontalLength() << ", Vertical Length [In Pixels]: " << secondL.getVerticalLength() << ", Orientation: " << dir[secondL.getOrientation()] << std::endl;
	std::cout << "Calculated Azimuth: " << azimuth << std::endl;
	std::cout << "Calculated Distance (Full Horizontal) [In Meters]: " << distanceFullHorizontal << std::endl;
	std::cout << "Calculated Distance (Vertical Average) [In Meters]: " << distanceVertical << std::endl;
	std::cout << "Calculated Distance (Full Horizontal) [In Feet]: " << distanceFullHorizontal * 3.2808 << std::endl;
	std::cout << "Calculated Distance (Vertical Average) [In Feet]: " << distanceVertical * 3.2808 << std::endl;
}


