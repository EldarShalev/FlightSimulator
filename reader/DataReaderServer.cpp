//
// Created by Eldar on 17-Dec-18.
//

#include "DataReaderServer.h"

DataReaderServer::DataReaderServer(string address1, int port1, int sampleRate1) : address(address1), port(port1),
                                                                                  sampleRate(sampleRate1) {}

static void *connectionHandlerWrapper(void *context) {
    return ((DataReaderServer *) context)->connectionHandler();
}

void DataReaderServer::openConnection() {
    int opt = 1;
    struct sockaddr_in server, client;

    // Creating socket file descriptor
    if ((serverDescriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(serverDescriptor, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    // Forcefully attaching socket to the port 8080
    if (bind(serverDescriptor, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(serverDescriptor, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    int addrlen = sizeof(sockaddr_in);
    if (socketClient = accept(serverDescriptor, (struct sockaddr *) &client, &addrlen)) {
        cout << "Connection accepted, starting listener thread";
    }

    if (pthread_create(&threadId, NULL, connectionHandlerWrapper, (void *) this) < 0) {
        perror("could not create thread");
        exit(EXIT_FAILURE);
    }
}

void DataReaderServer::closeConnection() {
    threadContinueRunning = false;
    void *returnValue;
    pthread_join(threadId, &returnValue);
    close(socketServer);
    close(socketClient);
}

string DataReaderServer::readServerCommand(string key) {
    locker.wait();
    string value = dataRead[key];
    locker.notify();
    return value;
}

void *DataReaderServer::connectionHandler(void) {
    int messageLen = 2000;
    char *message;
    struct sockaddr_in client;

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    int addrlen = sizeof(sockaddr_in);
    while (threadContinueRunning) {
        if (socketClient = accept(serverDescriptor, (struct sockaddr *) &client, &addrlen)) {
            puts("Connection accepted from thread");
            cout << "Connection accepted from thread";
            bzero(message, messageLen);
            read(socketClient, message, messageLen);

            string msg(message);
            locker.wait();
            dataRead.insert({"someKey", message});
            locker.notify();
        }
    }
}