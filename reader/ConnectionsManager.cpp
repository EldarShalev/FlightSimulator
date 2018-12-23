//
// Created by Eldar on 12/21/2018.
//

#include "ConnectionsManager.h"

ConnectionsHandler ConnectionsManager::handler;

void ConnectionsManager::connectDataReaderServer(string ip, int port, int sampleRate) {
    handler.connectDataReaderServer(ip, port, sampleRate);
}

void ConnectionsManager::connectReaderClient(string ip, int port) {
    handler.connectReaderClient(ip, port);
}

string  ConnectionsManager::send(string cmd) {
    return handler.send(cmd);
}

