#ifndef ArduinoController_hpp
#define ArduinoController_hpp

class ArduinoController
{
    public:
        ArduinoController();
        void init(int baudRate, int Port);
        void sendMessage(int azimuth, int distance, int height);
        int recieveMessage();

    private:
        int baud_rate;
        int port;
};

#endif // ArduinoController_hpp
