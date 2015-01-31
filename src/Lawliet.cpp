//============================================================================
// Name        : Lawliet.cpp
// Author      : Heidi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Maine.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: heidi
 */


#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "LDetector.h"



int main(int argc, char* argv[])
{
	LDetector what = LDetector();
	what.elLoad();
	what.elSplit();
	what.elThresh();
	what.elContours();
	what.elFilter();
	what.largest2();
	what.show();

	cv::waitKey(0);


	return 0;

}
