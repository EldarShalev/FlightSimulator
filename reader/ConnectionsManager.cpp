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

void ConnectionsManager::send(string cmd) {
    handler.send(cmd);
}

string ConnectionsManager::sendAndRecieve(string cmd) {
    handler.send(cmd);
    return handler.receive("something");
}
