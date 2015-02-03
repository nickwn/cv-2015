#include <iostream>

#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include "NetworkController.hpp"
#include "CmdLineInterface.hpp"
#include "AppConfig.hpp"
#include "GUIManager.hpp"
#include "VideoDevice.hpp"
#include "LDetector.hpp"
#include "LProcessor.hpp"


int main(int argc, char* argv[])
{
    // get command line interface condig options
    CmdLineInterface interface(argc, argv);
    AppConfig config = interface.getConfig();

    GUIManager gui;
    VideoDevice camera;
    LProcessor processor;
    NetworkController networkController;

    //init camera
    if(config.getIsDevice())
    {
        camera.startCapture(config.getDeviceID());
        std::cout << "Camera ready!\n";
    }

    //init networking
    if(config.getIsNetworking())
        networkController.startServer();

    if(!config.getIsHeadless())
        gui.init();

    //continuous server loop
    do
    {
        //std::cout << "ran " << counter << " times without crashing!\n";
        //counter ++;

        if(config.getIsNetworking())
            networkController.waitForPing();

        LDetector detector;

        cv::Mat image;
        if(config.getIsFile())
        {
            image = cv::imread(config.getFileName());
        }
        else
        {
            image = camera.getImage();
        }

        detector.elLoad(image);

        detector.elSplit();
        detector.elThresh();
        detector.elContours();
        detector.elFilter();
        if(!config.getIsHeadless())
        {
            gui.setImage(detector.show());
            gui.show();
        }
        std::vector<L> foundLs = detector.ArrayReturned();
        //detector.show();
        //cv::waitKey(0);
        //std::cout << foundLs.size() << std::endl;	

        int numLsFound = (foundLs.size());

        if(!config.getIsHeadless())
            gui.setImageText("Found " + boost::lexical_cast<std::string>(numLsFound) + " L's");

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
        else 
        {
            if(config.getIsNetworking())
                networkController.sendMessage(boost::lexical_cast<std::string> ("false") + std::string(";"));
        }
    }
    while(config.getIsDevice());

	return 0;
}

