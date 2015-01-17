find_package(OpenCV REQUIRED)
add_executable(network_test network_test.cpp)
target_link_libraries(network_test ${OpenCV_LIBS})
