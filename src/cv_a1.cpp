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

int main() 
{
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
    std::vector<L> points;
    points.push_back(L(secondL));
    points.push_back(L(firstL));
    oak.determineL(points);
    oak.determineAzimuth();
    oak.determineDistance();
    oak.outputData();
    return 0;
}
