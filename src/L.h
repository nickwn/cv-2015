/*
 * L.h
 *
 *  Created on: Jan 14, 2015
 *      Author: josh
 */

#ifndef L_H_
#define L_H_

#include "vector"
#include "opencv2/opencv.hpp"

class L {
public:
	L();
	L(std::vector<cv::Point>);
	virtual ~L();
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

#endif /* L_H_ */
