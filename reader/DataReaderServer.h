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
#include <pthread.h>
#include <map>
#include <iostream>
#include "data/Semaphore.h"

using namespace std;

class DataReaderServer {
private:
    string address;
    int port;
    int sampleRate;
    int socketServer;
    int socketClient;
    int serverDescriptor;
    map<string, string> dataRead;
    Semaphore locker;
    pthread_t threadId;
    bool threadContinueRunning;
public:
    DataReaderServer(string address1, int port1, int sampleRate1);

    void openConnection();

    void closeConnection();

    string readServerCommand(string key);

    void *connectionHandler(void);
};

#endif //SIMULATOR_DATAREADERSERVER_H
