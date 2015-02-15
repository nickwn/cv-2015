/*
 *    Copyright 2015 Westview Robotics
 *
 *    This file is part of FRC Team 3341 Targeting.
 *
 *    FRC Team 3341 Targeting is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    FRC Team 3341 Targeting is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with FRC Team 3341 Targeting.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <math.h>

#include "LProcessor.hpp"
#include "L.hpp"

void LProcessor::determineL(std::vector<L> ls) {
    firstL = ls.at(0);
    lCount++;
    if (ls.size() == 2)
    {
	secondL = ls.at(1);
	lCount++;
    }
    //firstL.configureL();
//    std::cout << firstL.getHorizontalLength() << std::endl;
//    std::cout << secondL.getHorizontalLength() << std::endl;
    //
    //secondL.configureL();
}

double LProcessor::getAzimuth()
{
    return azimuth;
}

double LProcessor::getDistance()
{
    return fmin(distanceFullHorizontal, distanceVertical);
}


cv::Point LProcessor::determineCenter()
{
	if (lCount == 1)
		return determineCenter1L();
	else
		return determineCenter2Ls();
}

cv::Point LProcessor::determineCenter1L()
{
	double pixelsToCenter = distanceLEdgeToCenter * firstL.getHorizontalLength() / horizontalLLength;
	cv::Point center;
	if (firstL.getOrientation())
		pixelsToCenter *= -1;
	center.x = firstL.getCornerPoint().x + pixelsToCenter;
	center.y = (firstL.getTopPoint().y + firstL.getCornerPoint().y) / 2;
	return center;
}

cv::Point LProcessor::determineCenter2Ls()
{
    std::vector<cv::Point> fPoints = firstL.getPoints();
    double x1 = 0;
    double y1 = 0;
    for(unsigned i = 0; i < fPoints.size(); i++)
    {
        x1 += fPoints.at(i).x;
        y1 += fPoints.at(i).y;
    }
    double avgX1 = x1/fPoints.size();
    double avgY1 = y1/fPoints.size();
    std::vector<cv::Point> sPoints = secondL.getPoints();
    double x2 = 0;
    double y2 = 0;
    for(unsigned i = 0; i < sPoints.size(); i++)
    {
        x2 += sPoints.at(i).x;
        y2 += sPoints.at(i).y;
    }
    double avgX2 = x2/sPoints.size();
    double avgY2 = y2/sPoints.size();
    double avgX = (avgX1 + avgX2)/2;
    double avgY = (avgY1 + avgY2)/2;
    return cv::Point(avgX, avgY);
}

void LProcessor::determineAzimuth()
{
    azimuth = (((double)imgWidth/2.0)-(double)determineCenter().x)/ focalLength;
    azimuth *= 180.0 / M_PI;
}

void LProcessor::determineDistance()
{
	if (lCount == 1)
		return determineDistance1L();
	else
		return determineDistance2Ls();	
}

void LProcessor::determineDistance1L()
{
    distanceFullHorizontal = horizontalLLength * focalLength / firstL.getHorizontalLength();
    distanceVertical = verticalLLength * focalLength / firstL.getVerticalLength();
}

void LProcessor::determineDistance2Ls()
{
    /*
     Currently the distance is calculated using the horizontal length between the side points of each L.
     Additionally, length is calculated using the shorter vertical distance of both L's.
     */
    double lengthFullHorizontal = sqrt(pow(firstL.getSidePoint().x - secondL.getSidePoint().x,2) + pow(firstL.getSidePoint().y - secondL.getSidePoint().y,2));
    distanceFullHorizontal = fullHorizontalLLength * focalLength / lengthFullHorizontal;
    double lengthVertical = (firstL.getVerticalLength() + secondL.getVerticalLength()) / 2; //fmin(firstL.getVerticalLength(), secondL.getVerticalLength());
    distanceVertical = verticalLLength * focalLength / lengthVertical;
}

void LProcessor::outputData()
{
    std::string dir[2] = {"Left Facing", "Right Facing"};
    std::cout << "Final Results" << std::endl;
    std::cout << "================================================================" << std::endl;
    std::cout << "L1: " << "Horizontal Length [In Pixels]: " << firstL.getHorizontalLength() << ", Vertical Length [In Pixels]: " << firstL.getVerticalLength() << ", Orientation: " << dir[firstL.getOrientation()] << std::endl;
    if (lCount > 1)
        std::cout << "L2: " << "Horizontal Length [In Pixels]: " << secondL.getHorizontalLength() << ", Vertical Length [In Pixels]: " << secondL.getVerticalLength() << ", Orientation: " << dir[secondL.getOrientation()] << std::endl;
    std::cout << "Calculated Azimuth: " << azimuth << std::endl;
    std::cout << "Calculated Distance (Full Horizontal) [In Meters]: " << distanceFullHorizontal << std::endl;
    std::cout << "Calculated Distance (Vertical Average) [In Meters]: " << distanceVertical << std::endl;
    std::cout << "Calculated Distance (Full Horizontal) [In Feet]: " << distanceFullHorizontal * 3.2808 << std::endl;
    std::cout << "Calculated Distance (Vertical Average) [In Feet]: " << distanceVertical * 3.2808 << std::endl;
}


