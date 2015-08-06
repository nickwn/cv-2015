#include "ArduinoController.hpp"
#include <string>
#include "rs232.h"

ArduinoController::ArduinoController(){}

void ArduinoController::init(int baudRate, int Port)
{
    baud_rate = baudRate;
    port = Port;
}

void sendMessage(int vertical, int horizontal)
{

}

int recieveMessage()
{
    // this might be for error messages or something
}
