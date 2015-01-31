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
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See thelibboost1.55-all-dev
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with FRC Team 3341 Targeting.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LDetector_hpp
#define LDetector_hpp

#include <iostream>
#include <opencv2/opencv.hpp>
#include "L.hpp"

class LDetector {
public:
	LDetector();

	void elLoad(cv::Mat foto);
	void elSplit();
	void elThresh();
	void show();
	void elFilter();
	void elContours();
	void largest2();
	//double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
	//void whatever();
	//void populateRectangles();
//	void loopAndPrint();
	//void show();
	//bool containsRectangle(Rectangle rec1, Rectangle rec2);
	std::vector<L> ArrayReturned();
private:
	//std::vector<Rectangle> rectList;
	//std::vector<std::vector<cv::Point> > allRectangles;
	cv::Mat image;

	//FOR THE SPLITTY-RECREATEY STUFF
	cv::Mat b;
	std::vector<cv::Mat> a;
	cv::Mat hueLower;
	cv::Mat hueUpper;
	cv::Mat valUp, valLow;
	cv::Mat thresh;
	cv::Mat combine;
	std::vector<L> all;
	std::vector<cv::Point> approx;
	double elAngles(cv::Point pt1, cv::Point pt2, cv::Point pt3);
	bool LosAngles(std::vector<cv::Point> vect);
	


};

#endif /* LDetector_hpp */
