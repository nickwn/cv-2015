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
        void determineL(std::vector<L>);
        cv::Point determineCenter();
        cv::Point determineCenter1L();
        cv::Point determineCenter2Ls();
        void determineDistance();
        void determineDistance1L();
        void determineDistance2Ls();
        void determineAzimuth();
        void outputData();
        double getAzimuth();
        double getDistance();
        cv::Point getCenter();
    private:
        double azimuth;
        double distanceFullHorizontal;
        double distanceVertical;
        const double focalLength = 640;
        const double imgWidth = 640;
        const double imgHeight = 480;
	const double distanceLEdgeToCenter = 0.034925;
	const double horizontalLLength = 0.1778;
	const double verticalLLength = 0.1778;
	const double fullHorizontalLLength = 0.425458;
	int lCount = 0;
        L firstL;
        L secondL;
};

#endif /* LProcessor_hpp */
