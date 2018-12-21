//
// Created by Eldar on 12/21/2018.
//

#include "ConnectionsHandler.h"

void ConnectionsHandler::connectDataReaderServer(string ip, int port, int sampleRate) {
    server = new DataReaderServer(ip, port, sampleRate);
    server->openConnection();
}

void ConnectionsHandler::connectReaderClient(string ip, int port) {
    client = new ConnectReaderClient(ip, port);
    client->connect();
}

ConnectionsHandler::~ConnectionsHandler() {
    //TODO should close connections first somehow?
    if (server != NULL) {
        delete server;
    }
    if (client != NULL) {
        delete client;
    }
};