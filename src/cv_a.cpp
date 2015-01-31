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
#include <opencv2/opencv.hpp>

#include "LProcessor.hpp"
#include "LDetector.hpp"
#include "L.hpp"

int main() {
	LDetector detector;
	detector.elLoad(cv::imread("./img.jpg"));
	detector.elSplit();
	detector.elThresh();
	detector.elContours();
	detector.elFilter();
	detector.largest2();
	//detector.show();
	//cv::waitKey(0);
	std::vector<L> foundLs = detector.ArrayReturned();
	//std::cout << foundLs.size() << std::endl;	

	LProcessor processor;
	processor.determineL(foundLs);
	processor.determineAzimuth();
	processor.determineDistance();
	//processor.outputData();
	std::cout << "Distance: " << processor.getDistance() << std::endl;
	std::cout << "Azimuth: " << processor.getAzimuth() << std::endl;
	return 0;
}
