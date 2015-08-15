#ifndef ArduinoController_hpp
#define ArduinoController_hpp

#include <opencv2/opencv.hpp>

class ArduinoController
{
    public:
        ArduinoController();
        void init(int baudRate, int Port);
        void sendMessage(int azimuth, cv::Point LCenter);
        int recieveMessage();

    private:
        int baud_rate;
        int port;
        const double focalLength = 640;
        const double imgHeight = 480;
        int altitude;
};

#endif // ArduinoController_hpp
