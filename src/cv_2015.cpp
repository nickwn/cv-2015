#include <iostream>

#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include "NetworkController.hpp"
#include "CmdLineInterface.hpp"
#include "AppConfig.hpp"
#include "VideoDevice.hpp"
#include "LDetector.hpp"
#include "LProcessor.hpp"


int main(int argc, char* argv[])
{
    CmdLineInterface interface(argc, argv);
    AppConfig config = interface.getConfig();
    VideoDevice camera;
    if(config.getIsDevice())
        camera.startCapture(config.getDeviceID());

    NetworkController networkController;
    if(config.getIsNetworking())
    {
        //init networking
        networkController.startServer();
    }

    //continuous server loop
    while(true)
    {

        if(config.getIsNetworking())
            networkController.waitForPing();

        LDetector detector;

        if(config.getIsFile())
        {
            detector.elLoad(cv::imread(config.getFileName()));
        }
        else
        {
            detector.elLoad(camera.getImage());
        }

        detector.elSplit();
        detector.elThresh();
        detector.elContours();
        detector.elFilter();
        std::vector<L> foundLs = detector.ArrayReturned();
        //detector.show();
        //cv::waitKey(0);
        //std::cout << foundLs.size() << std::endl;	

        bool found = (foundLs.size() != 0);
        LProcessor processor;

        if(found)
        {
            detector.largest2();
            processor.determineL(foundLs);
            processor.determineAzimuth();
            processor.determineDistance();
            double azimuth = processor.getAzimuth();
            double distance = processor.getDistance();

            if(config.getIsNetworking())
            {
                networkController.sendMessage(boost::lexical_cast<std::string> ("true") + std::string(";") 
                    + boost::lexical_cast<std::string> (distance) + std::string(";") 
                    + boost::lexical_cast<std::string> (azimuth));
            }
        }
        else if(config.getIsNetworking())
        {
            networkController.sendMessage(boost::lexical_cast<std::string> ("false") + std::string(";"));
        }
    }
	return 0;
}

