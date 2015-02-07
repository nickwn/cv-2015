/*
 *    Copyright 2012, 2013, 2014 Tushar Pankaj
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <set>

#include "GUIManager.hpp"

// Public Functions
GUIManager::GUIManager()
{
}

void GUIManager::init()
{
    cv::namedWindow("FRC Team 3341 Targeting", 0);
}

void GUIManager::setImage(cv::Mat inputImage)
{
    image = inputImage;
}

void GUIManager::setImageText(std::string imageText)
{
    cv::putText(image, imageText, cv::Point(0, image.rows - 5), 
        cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(0.0, 255.0, 0.0, 0.0),
        1);
}

void GUIManager::show(bool isFile)
{
    //isFile determines if image should be shown indefinitely
    //in File Mode, the main loop only runs once rather than continuously
    cv::imshow("FRC Team 3341 Targeting", image);
    if(isFile)
        cv::waitKey(0);
    else
        cv::waitKey(10);
}
