#include "ArduinoController.hpp"
#include <string>
#include "rs232.h"
#include <iostream>

ArduinoController::ArduinoController(){}

void ArduinoController::init(int baudRate, int Port)
{
    baud_rate = baudRate;
    port = Port;
    char mode[]={'8','N','1',0};

    if(RS232_OpenComport(port, baud_rate, mode))
    {
        std::cout << "Can not open port\n";
        return(0);
    }
}

void sendMessage(int azimuth, int distance, int height)
{
    if(RS232_SendByte(port, (char)azimuth) == -1)
    {
        std::cout << "error sending byte/n";
    }

    else
    {
        RS232_SendByte(port, (char)distance);
        RS232_SendByte(port, (char)height);
    }

}

int recieveMessage()
{
    // this might be for error messages or something
}
