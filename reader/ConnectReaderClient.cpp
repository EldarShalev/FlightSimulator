//
// Created by Eldar on 21-Dec-18.
//

#include <netdb.h>
#include "ConnectReaderClient.h"

ConnectReaderClient::ConnectReaderClient(string ip1, int port1) : ip(ip1), port(port1) {}

void ConnectReaderClient::connectToServer() {
    struct sockaddr_in address;
    int valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if ((socketListener = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(ip));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    // serv_addr.sin_addr.s_addr=inet_addr(ip.c_str());

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(0);
    }

    if (::connect(socketListener, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        exit(0);
    }
    string hello="get /controls/flight/speedbrake";
    send(socketListener, hello.c_str(), hello.length(), 0);
    printf(hello.c_str());
    valread = read(socketListener, buffer, 1024);
    printf("%s\n", buffer);
}

void ConnectReaderClient::closeConnection() {
    close(socketListener);
}

void ConnectReaderClient::sendCommand(string cmd) {
    //TODO send cmd
}
