network_test: network_test.o Makefile NetworkController.o
	g++ -o ../build/src/network_test NetworkController.o network_test.o -L/usr/lib/x86_64-linux-gnu -pthread -lboost_system -lboost_thread
NetworkController.o: NetworkController.cpp
	g++ -o NetworkController.o -c NetworkController.cpp
network_test.o: network_test.cpp
	g++ -o network_test.o -c network_test.cpp
