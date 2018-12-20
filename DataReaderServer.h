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

using namespace std;

class DataReaderServer {
private:
    static string address;
    static int port;
    static int sampleRate;

public:
    static void setAddress(string newAddress);

    static void setPort(int newPort);

    static void setSampleRate(int newSampleRate);

    static void openConnection();
};

#endif //SIMULATOR_DATAREADERSERVER_H
