//
// Created by Eldar on 21-Dec-18.
//

#ifndef SIMULATOR_CONNECTREADERCLIENT_H
#define SIMULATOR_CONNECTREADERCLIENT_H

#include <string>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <cstring>
#include <thread>
#include <arpa/inet.h>
#include <netdb.h>

using namespace std;

class ConnectReaderClient {
private:
    int port;
    string ip;
    int socketListener;
public:
    ConnectReaderClient(string ip1, int port1);

    void connectToServer();

    void closeConnection();

    string sendCommand(string cmd);
};

#endif //SIMULATOR_CONNECTREADERCLIENT_H
