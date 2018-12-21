//
// Created by Eldar on 12/21/2018.
//

#ifndef SIMULATOR_CONNECTIONSMANAGER_H
#define SIMULATOR_CONNECTIONSMANAGER_H

#include "ConnectionsHandler.h"

class ConnectionsManager {
private:
    static ConnectionsHandler handler;
public:
    static void connectDataReaderServer(string ip, int port, int sampleRate);

    static void connectReaderClient(string ip, int port);
};

#endif //SIMULATOR_CONNECTIONSMANAGER_H
