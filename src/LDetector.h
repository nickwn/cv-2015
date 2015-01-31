/*
 * LDetector.h
 *
 *  Created on: Jan 14, 2015
 *      Author: heidi
 */
#include <iostream>
#include <opencv2/opencv.hpp>
#ifndef LDETECTOR_H_
#define LDETECTOR_H_

class LDetector {
public:
	LDetector();

	void elLoad();
	void elSplit();
	void elThresh();
	void show();
	void elFilter();
	void elContours();
	double elAngles(cv::Point pt1, cv::Point pt2, cv::Point pt3);
	bool LosAngles(std::vector<cv::Point> vect);
	void largest2();
	//double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
	//void whatever();
	//void populateRectangles();
//	void loopAndPrint();
	//void show();
	//bool containsRectangle(Rectangle rec1, Rectangle rec2);

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
	std::vector<std::vector<cv::Point> > all;
	std::vector<cv::Point> approx;
};
#endif /* LDETECTOR_H_ */
