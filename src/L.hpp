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

#ifndef L_hpp
#define L_hpp

#include <vector>
#include <opencv2/opencv.hpp>

class L {
public:
	L();
	L(std::vector<cv::Point>);
	void setOrientation(bool);
	cv::Point getTopPoint();
	cv::Point getCornerPoint();
	cv::Point getSidePoint();
	float getHorizontalLength();
	float getVerticalLength();
	void determineCornerPoint();
	cv::Point determinePointAbove(cv::Point);
	void configureL();
	void determineSidePoint(); //determines the side point and swaps with the corner point if right facing
	void calculateLength();
	bool getOrientation();
	std::vector<cv::Point> getPoints();
private:
	std::vector<cv::Point> points;
	bool orientation; //the direction the side point is facing from the center - true = right; false = left
	cv::Point topPoint; //top point closest to the middle of the box
	cv::Point cornerPoint; //the point of the outer corner
	cv::Point sidePoint; //the other bottom point
	cv::Point referencePoint;
	float verticalLength; //length between topPoint and cornerPoint
	float horizontalLength; //length between sidePoint and cornerPoint
};

#endif /* L_hpp */
