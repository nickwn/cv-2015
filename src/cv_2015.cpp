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
    // get command line interface condig options
    CmdLineInterface interface(argc, argv);
    AppConfig config = interface.getConfig();

    VideoDevice camera;
    LProcessor processor;
    NetworkController networkController;

    if(config.getIsDevice())
        //init camera
        camera.startCapture(config.getDeviceID());

    if(config.getIsNetworking())
    {
        //init networking
        networkController.startServer();
    }

    //continuous server loop
    int counter = 0;
    do
    {
        //std::cout << "ran " << counter << " times without crashing!\n";
        //counter ++;

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

        int numLsFound = (foundLs.size());

        if(numLsFound != 0)
        {
            std::cout << "Found " << foundLs.size() << " L's!" << std::endl;
            if(numLsFound >= 2)
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
    while(config.getIsDevice());

	return 0;
}

