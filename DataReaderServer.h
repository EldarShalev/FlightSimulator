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
    // TODO this class needs to open new server with given port and times. (what about IP? always 127...?)
private:
    static int port;
    static int sampleRate;

public:
    static void setPort(int newPort) { DataReaderServer::port = newPort; }

    static void setSampleRate(int newSampleRate) { DataReaderServer::sampleRate = newSampleRate; }

    static void openConnection();

};


#endif //SIMULATOR_DATAREADERSERVER_H
