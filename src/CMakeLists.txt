# Find Libraries
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

# CV-A1 unintegrated code
#add_executable(cv_a1 cv_a1.cpp LProcessor.cpp L.cpp)
#target_link_libraries(cv_a1 ${OpenCV_LIBS})

# CV-A2 unintegrated code
#add_executable(cv_a2 cv_a2.cpp LDetector.cpp L.cpp)
#target_link_libraries(cv_a2 ${OpenCV_LIBS})

# CV-A integrated code
#add_executable(cv_a cv_a.cpp LDetector.cpp LProcessor.cpp L.cpp)
#target_link_libraries(cv_a ${OpenCV_LIBS})

# CV-B unintegrated code
#add_executable(cv_b cv_b.cpp NetworkController.cpp VideoDevice.cpp CmdLineInterface.cpp AppConfig.cpp GUIManager.cpp)
#target_link_libraries(cv_b ${OpenCV_LIBS} ${Boost_LIBRARIES})

# CV-2015 integrated code
add_executable(cv_2015 cv_2015.cpp LDetector.cpp LProcessor.cpp L.cpp NetworkController.cpp VideoDevice.cpp CmdLineInterface.cpp AppConfig.cpp GUIManager.cpp)
target_link_libraries(cv_2015 ${OpenCV_LIBS} ${Boost_LIBRARIES})
