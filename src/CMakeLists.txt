find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)
add_executable(network_test network_test.cpp NetworkController.cpp VideoDevice.cpp CmdLineInterface.cpp AppConfig.cpp GUIManager.cpp)
target_link_libraries(network_test ${OpenCV_LIBS} ${Boost_LIBRARIES})
