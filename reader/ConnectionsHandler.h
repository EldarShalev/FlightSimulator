//
// Created by Eldar on 12/21/2018.
//

#ifndef SIMULATOR_CONNECTIONSHANDLER_H
#define SIMULATOR_CONNECTIONSHANDLER_H

#include "DataReaderServer.h"
#include "ConnectReaderClient.h"

class ConnectionsHandler {
private:
    DataReaderServer *server = NULL;
    ConnectReaderClient *client = NULL;
public:
    void connectDataReaderServer(string ip, int port, int sampleRate);

    void connectReaderClient(string ip, int port);

    ~ConnectionsHandler();

    void send(string cmd);

    string receive(string key);
};

#endif //SIMULATOR_CONNECTIONSHANDLER_H
