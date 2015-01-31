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

#ifndef LProcessor_hpp
#define LProcessor_hpp

#include <vector>
#include <opencv2/opencv.hpp>

#include "L.hpp"

class LProcessor {
public:
	L firstL;
	L secondL;
	void determineL(std::vector<std::vector<cv::Point> >);
	cv::Point determineCenter();
	void determineDistance();
	void determineAzimuth();
	void outputData();
	float getAzimuth();
	float getDistanceFullHorizontal(); //Distance calculated from the full horizontal length
	float getDistanceVertical(); //Distance calculated from the average vertical length
	float focalLength = 640;
	float imgWidth = 640;
	float imgHeight = 480;
private:
	float azimuth;
	float distanceFullHorizontal;
	float distanceVertical;
};

#endif /* LProcessor_hpp */
