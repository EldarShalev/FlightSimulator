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
    client->connectToServer();
}

ConnectionsHandler::~ConnectionsHandler() {
    if (server != NULL) {
        server->closeConnection();
        delete server;
    }
    if (client != NULL) {
        client->closeConnection();
        delete client;
    }
}

void ConnectionsHandler::send(string cmd) {
    client->sendCommand(cmd);
}

string ConnectionsHandler::receive(string key) {
    return server->readServerCommand(key);
};