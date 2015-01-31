//============================================================================
// Name        : ElDetector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <opencv2/opencv.hpp>
#include "LProcessor.h"

int main() {
	std::vector<cv::Point> firstL;
	firstL.push_back(cv::Point(254, 280)); //** 53
	firstL.push_back(cv::Point(291, 263));
	firstL.push_back(cv::Point(307, 225));
	firstL.push_back(cv::Point(307, 278)); //**
	firstL.push_back(cv::Point(253, 266));
	firstL.push_back(cv::Point(290, 255));

	std::vector<cv::Point> secondL;
	secondL.push_back(cv::Point(382, 262));
	secondL.push_back(cv::Point(342, 224));
	secondL.push_back(cv::Point(382, 277)); //**54
	secondL.push_back(cv::Point(328, 279)); //**
	secondL.push_back(cv::Point(343, 262));
	secondL.push_back(cv::Point(327, 225));

	LProcessor oak;
	std::vector<std::vector<cv::Point> > points;
	points.push_back(secondL);
	points.push_back(firstL);
	oak.determineL(points);
	oak.determineAzimuth();
	oak.determineDistance();
	oak.outputData();
	return 0;
}
