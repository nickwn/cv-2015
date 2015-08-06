#ifndef ArduinoController_hpp
#define ArduinoController_hpp

class ArduinoController
{
    public:
        ArduinoController();
        void init(int baudRate, int Port);
        void sendMessage(int vertical, int horizontal);
        int recieveMessage();

    private:
        int baud_rate;
        int port;
};

#endif // ArduinoController_hpp
