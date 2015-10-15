#include "ArduinoController.hpp"
#include <string>
#include "rs232.h"
#include <iostream>
#include <opencv2/opencv.hpp>

ArduinoController::ArduinoController(){}

void ArduinoController::init(int baudRate, int Port)
{
    baud_rate = baudRate;
    port = Port;
    char mode[]={'8','N','1',0};

    if(RS232_OpenComport(port, baud_rate, mode))
    {
        std::cerr << "Can not open port\n"; // TODO add error handling
        return;
    }
}

// TODO send more bytes at once
void ArduinoController::sendMessage(int azimuth, cv::Point LCenter)
{
    altitude = ((imgHeight/2.0)-LCenter.y) / focalLength;
    altitude *= 180.0 / M_PI;

    if(RS232_SendByte(port, (char)azimuth) == 1)
    {
        std::cerr << "error sending byte\n"; // TODO add error handling
    }

    else
    {
        std::cout << "successfully sent " << char(azimuth) << std::endl;
        //RS232_SendByte(port, (char)altitude);
    }

}

int ArduinoController::recieveMessage()
{
    // this might be for error messages or something
    return 0;
}
