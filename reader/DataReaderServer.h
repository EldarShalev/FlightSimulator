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
#include <iostream>
#include <vector>
#include <unordered_map>
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
    std::unordered_map<string, string> dataRead;
    Semaphore locker;
    pthread_t threadId;
    bool threadContinueRunning;
    // TODO - delete this
    mutex m;

public:


    DataReaderServer(string address1, int port1, int sampleRate1);

    void openConnection();

    void closeConnection();

    string readServerCommand(string key);

    void *connectionHandler(void);

    void xmlDataSplitter(string buff);

    void updateMapEachIteration(vector<string> vector1);


};

#endif //SIMULATOR_DATAREADERSERVER_H
