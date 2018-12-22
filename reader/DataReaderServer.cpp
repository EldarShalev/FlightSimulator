//
// Created by Eldar on 17-Dec-18.
//

#include "DataReaderServer.h"

DataReaderServer::DataReaderServer(string address1, int port1, int sampleRate1) : address(address1), port(port1), sampleRate(sampleRate1) {}
void *connection_handler(void *);



void DataReaderServer::openConnection() {
    int server_fd, valread, c;
    socketListener = port;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((socketListener = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        perror("accept");


        puts("Waiting for incoming connections...");
        c = sizeof(struct sockaddr_in);

        //Accept and incoming connection
        puts("Waiting for incoming connections...");
        c = sizeof(struct sockaddr_in);
        pthread_t thread_id;

        if ((socketListener = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &c))) {
            puts("Coneection accepted");
            if (pthread_create(&thread_id, NULL, connection_handler, (void *) &socketListener) < 0) {
                perror("could not create thread");
                exit(EXIT_FAILURE);

            }
            //pthread_join( thread_id , NULL);
            puts("Handler assigned");
        }
        if (socketListener < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        valread = ::read(socketListener, buffer, 1024);
        printf("%s\n", buffer);
    }
}

void DataReaderServer::closeConnection() {
    close(socketListener);
}

string DataReaderServer::readServerCommand(string key) {
    //TODO - read output value by key
    int valread;
    char buffer[1024] = {0};
    valread = read( this->socketListener , buffer, 1024);
    return buffer;
}


void *connection_handler(void *socket_desc) {
    //Get the socket descriptor
    int sock = *(int *) socket_desc;
    int read_size;
    char *message, client_message[2000];



    //Receive a message from client
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        //end of string marker
        client_message[read_size] = '\0';

        //Send the message back to client
        write(sock, client_message, strlen(client_message));

        //clear the message buffer
        memset(client_message, 0, 2000);
    }

    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }
}