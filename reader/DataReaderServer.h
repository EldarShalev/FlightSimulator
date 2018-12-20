//
// Created by Eldar on 17-Dec-18.
//

#ifndef SIMULATOR_DATAREADERSERVER_H
#define SIMULATOR_DATAREADERSERVER_H

#include <string>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <cstring>
#include <thread>


using namespace std;

class DataReaderServer {
private:
    string address;
    int port;
    int sampleRate;

public:
    DataReaderServer(string address1, int port1, int sampleRate1);
    void setAddress(string newAddress);

    void setPort(int newPort);

    void setSampleRate(int newSampleRate);

    void openConnection();

};

#endif //SIMULATOR_DATAREADERSERVER_H
