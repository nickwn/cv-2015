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

#ifndef AppConfig_hpp
#define AppConfig_hpp

#include <string>

class AppConfig
{
    public:
        AppConfig();
        void setFileName(std::string fileName);
        void setDeviceID(int deviceID);
        void setIsFile(int isFile);
        void setIsDevice(int isDevice);
        void setIsHeadless(int isHeadless);
        void setIsNetworking(int isNetworking);
        void setIsDebug(int debug);
        void setHasArduino(int arduino);
        int getDeviceID();
        int getIsFile();
        int getIsDevice();
        int getIsHeadless();
        int getIsNetworking();
        int getIsDebug();
        int getHasArduino();
        std::string getFileName();
    private:
        std::string fileName;
        int deviceID;
        int isFile;
        int isDevice;
        int isHeadless;
        int isNetworking;
        int isDebug;
        int hasArduino;
};

#endif /* AppConfig_hpp */

