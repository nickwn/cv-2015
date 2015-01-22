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

#include <cstdlib>
#include <string>

#include "AppConfig.hpp"

AppConfig::AppConfig() :
	deviceID(0),
	isFile(0),
	isDevice(0),
	isHeadless(0),
	isNetworking(1)
{
}

// Getters
std::string AppConfig::getFileName()
{
	return fileName;
}

int AppConfig::getDeviceID()
{
	return deviceID;
}

int AppConfig::getIsFile()
{
	return isFile;
}

int AppConfig::getIsDevice()
{
	return isDevice;
}

int AppConfig::getIsHeadless()
{
	return isHeadless;
}

int AppConfig::getIsNetworking()
{
	return isNetworking;
}

// Setters
void AppConfig::setFileName(std::string inputFileName)
{
	fileName = inputFileName;
}

void AppConfig::setDeviceID(int inputDeviceID)
{
	deviceID = inputDeviceID;
}

void AppConfig::setIsFile(int inputIsFile)
{
	isFile = inputIsFile;
}

void AppConfig::setIsDevice(int inputIsDevice)
{
	isDevice = inputIsDevice;
}

void AppConfig::setIsHeadless(int inputIsHeadless)
{
	isHeadless = inputIsHeadless;
}

void AppConfig::setIsNetworking(int inputIsNetworking)
{
	isNetworking = inputIsNetworking;
}
