# Find Libraries
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

# CV-A1 unintegrated code
add_executable(el_processor el_processor.cpp LProcessor.cpp)
target_link_libraries(el_processor ${OpenCV_LIBS})

# CV-A2 unintegrated code
add_executable(lawliet lawliet.cpp LDetector.cpp)
target_link_libraries(lawliet ${OpenCV_LIBS})

# CV-B unintegrated code
add_executable(network_test network_test.cpp NetworkController.cpp VideoDevice.cpp CmdLineInterface.cpp AppConfig.cpp GUIManager.cpp)
target_link_libraries(network_test ${OpenCV_LIBS} ${Boost_LIBRARIES})
