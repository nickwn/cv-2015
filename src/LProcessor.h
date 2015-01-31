/*LProcessor.h
 *
 *  Created on: Jan 14, 2015
 *      Author: josh
 */

#ifndef LPROCESSOR_H_
#define LPROCESSOR_H_
#include "L.h"
#include "vector"
#include <opencv2/opencv.hpp>

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

#endif /* LPROCESSOR_H_ */
