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

#include <math.h>
#include <vector>
#include <opencv2/opencv.hpp>

#include "L.hpp"

L::L()
{
}

L::L(std::vector<cv::Point> p) {
    orientation = false;
    verticalLength = 0;
    horizontalLength = 0;
    points = p;
    topPoint = cv::Point(0, 0);
    cornerPoint = cv::Point(0, 0);
    sidePoint = cv::Point(0, 0);
    referencePoint = cv::Point(0, 0);
    area = fabs(cv::contourArea(points, true));
}

double L::getArea()
{
    return area;
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
    int indexCorner = 0;
    for (unsigned i = 0; i < points.size(); ++i)
    {
        double tempLength = sqrt(pow(points.at(i).x, 2) + pow(points.at(i).y, 2));
        if (tempLength > maxLength)
        {
            maxLength = tempLength;
            indexCorner = i;
        }
    }
    cornerPoint = points.at(indexCorner);
}

void L::determineSidePoint() //swaps current corner point with the other bottom point
{
    double minLength = 6e6;
    int indexPoint = 0;
    for (unsigned i = 0; i < points.size(); ++i)
    {
        if (points.at(i).x != cornerPoint.x) //compare the x values to make sure it's not secretly the same point :O
        {
            double tempLength = abs(points.at(i).y - cornerPoint.y);
            if (tempLength < minLength)
            {
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
    int indexTop = 0;
    for (unsigned i = 0; i < points.size(); ++i)
    {
        if (points.at(i).y != lowerPoint.y) //compare the y values to make sure it's not secretly the same point :O
        {
            double tempLength = abs(points.at(i).x - lowerPoint.x);
            if (tempLength < minLength)
            {
                minLength = tempLength;
                indexTop = i;
            }
        }
    }
    return points.at(indexTop);
}
