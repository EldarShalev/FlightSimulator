//
// Created by Eldar on 21-Dec-18.
//
#include "ConnectReaderClient.h"

ConnectReaderClient::ConnectReaderClient(string ip1, int port1) : ip(ip1), port(port1) {}

void ConnectReaderClient::connectToServer() {
    struct sockaddr_in serv_addr;
    if ((socketListener = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(ip));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(0);
    }

    if (connect(socketListener, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        exit(0);
    }
}

void ConnectReaderClient::closeConnection() {
    close(socketListener);
}

void ConnectReaderClient::sendCommand(string cmd) {
    // TODO check first if we can handle client server communication
    static int a = 1;
    string hardCoded;
    if (a == 1) {
        hardCoded = "set /instrumentation/heading-indicator/offset-deg 20\\r\\n";
        a++;
    } else {
        hardCoded = "get /instrumentation/heading-indicator/offset-deg\\r\\n";
    }

    send(this->socketListener, hardCoded.c_str(), cmd.length(), 0);
    //TODO send cmd
}
