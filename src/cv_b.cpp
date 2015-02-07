#include <iostream>

#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include "NetworkController.hpp"



int main()
{
    bool found = true;
    double distance = 0.3, azimuth = 0.1;
    std::cout << "Hi" << std::endl;
    
    //init networking
    NetworkController networkController;
    networkController.startServer();

    //continuous server loop
    while(true)
    {
        networkController.waitForPing();
        if(found)
        {
            networkController.sendMessage(boost::lexical_cast<std::string> ("true") + std::string(";") 
                + boost::lexical_cast<std::string> (distance) + std::string(";") 
                + boost::lexical_cast<std::string> (azimuth));
        }
        else
        {
            networkController.sendMessage(boost::lexical_cast<std::string> ("false") + std::string(";"));
        }
        //change the values every time
        distance += 0.1;
        azimuth += 0.05;
        found = !found;
    }
    return 0;
}

