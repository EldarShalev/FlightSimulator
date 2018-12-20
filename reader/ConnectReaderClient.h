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


using namespace std;


class ConnectReaderClient {
private:
    int port;
    string ip;
public:
    ConnectReaderClient(string ip1, int port1);

    void connect();
};


#endif //SIMULATOR_CONNECTREADERCLIENT_H
