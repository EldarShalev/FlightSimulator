//
// Created by Eldar on 17-Dec-18.
//

#include <input/Utils.h>
#include "DataReaderServer.h"

DataReaderServer::DataReaderServer(string address1, int port1, int sampleRate1) : address(address1), port(port1),
                                                                                  sampleRate(sampleRate1) {


    dataRead.insert(make_pair("/instrumentation/airspeed-indicator/indicated-speed-kt", "0"));
    dataRead.insert(make_pair("/instrumentation/altimeter/indicated-altitude-ft", "0"));
    dataRead.insert(make_pair("/instrumentation/altimeter/pressure-alt-ft", "0"));
    dataRead.insert(make_pair("/instrumentation/attitude-indicator/indicated-pitch-deg", "0"));
    dataRead.insert(make_pair("/instrumentation/attitude-indicator/indicated-roll-deg", "0"));
    dataRead.insert(make_pair("/instrumentation/attitude-indicator/internal-pitch-deg", "0"));
    dataRead.insert(make_pair("/instrumentation/attitude-indicator/internal-roll-deg", "0"));
    dataRead.insert(make_pair("/instrumentation/encoder/indicated-altitude-ft", "0"));
    dataRead.insert(make_pair("/instrumentation/encoder/pressure-alt-ft", "0"));
    dataRead.insert(make_pair("/instrumentation/gps/indicated-altitude-ft", "0"));
    dataRead.insert(make_pair("/instrumentation/gps/indicated-ground-speed-kt", "0"));
    dataRead.insert(make_pair("/instrumentation/gps/indicated-vertical-speed", "0"));
    dataRead.insert(make_pair("/instrumentation/heading-indicator/indicated-heading-deg", "0"));
    dataRead.insert(make_pair("/instrumentation/magnetic-compass/indicated-heading-deg", "0"));
    dataRead.insert(make_pair("/instrumentation/slip-skid-ball/indicated-slip-skid", "0"));
    dataRead.insert(make_pair("/instrumentation/turn-indicator/indicated-turn-rate", "0"));
    dataRead.insert(make_pair("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", "0"));
    dataRead.insert(make_pair("/controls/flight/aileron", "0"));
    dataRead.insert(make_pair("/controls/flight/elevator", "0"));
    dataRead.insert(make_pair("/controls/flight/rudder", "0"));
    dataRead.insert(make_pair("/controls/flight/flaps", "0"));
    dataRead.insert(make_pair("/controls/engines/current-engine/throttle", "0"));
    dataRead.insert(make_pair("/engines/engine/rpm", "0"));


}

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
    socklen_t addrlen = sizeof(sockaddr_in);

    if (socketClient = accept(serverDescriptor, (struct sockaddr *) &client, &addrlen)) {
        cout << "Connection accepted, starting listener thread" << endl;
    }

    if (pthread_create(&threadId, NULL, connectionHandlerWrapper, (void *) this) < 0) {
        perror("could not create thread");
        exit(EXIT_FAILURE);
    }
    locker.wait();
}

void DataReaderServer::closeConnection() {
    threadContinueRunning = false;
    void *returnValue;
    pthread_join(threadId, &returnValue);
    close(socketServer);
    close(socketClient);
}


void *DataReaderServer::connectionHandler(void) {
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    threadContinueRunning = true;
    char buffer[4096] = {0};
    while (threadContinueRunning) {
        listen(serverDescriptor, 5);
        read(socketClient, buffer, sizeof(buffer));
        xmlDataSplitter(buffer);
    }
}

string DataReaderServer::readServerCommand(string key) {
    // Waiting for locker to finish update the value before we take it from the map
    locker.wait();
    std::lock_guard<mutex> lockGuard(m);
    cout << "Taking value of " << key << endl;
    string value = dataRead[key];
    cout << value << endl;
    return value; // mutex unlocks here
}

void DataReaderServer::xmlDataSplitter(string buff) {
    m.lock();
    vector<string> info = Utils::split(buff, ',');
    updateMapEachIteration(info);
    m.unlock();
    locker.notify();

}

void DataReaderServer::updateMapEachIteration(vector<string> vector1) {
    dataRead["/instrumentation/airspeed-indicator/indicated-speed-kt"] = (vector1.at(0));
    dataRead["/instrumentation/altimeter/indicated-altitude-ft"] = (vector1.at(1));
    dataRead["/instrumentation/altimeter/pressure-alt-ft"] = (vector1.at(2));
    dataRead["/instrumentation/attitude-indicator/indicated-pitch-deg"] = (vector1.at(3));
    dataRead["/instrumentation/attitude-indicator/indicated-roll-deg"] = (vector1.at(4));
    dataRead["/instrumentation/attitude-indicator/internal-pitch-deg"] = (vector1.at(5));
    dataRead["/instrumentation/attitude-indicator/internal-roll-deg"] = (vector1.at(6));
    dataRead["/instrumentation/encoder/indicated-altitude-ft"] = (vector1.at(7));
    dataRead["/instrumentation/encoder/pressure-alt-ft"] = (vector1.at(8));
    dataRead["/instrumentation/gps/indicated-altitude-ft"] = (vector1.at(9));
    dataRead["/instrumentation/gps/indicated-ground-speed-kt"] = (vector1.at(10));
    dataRead["/instrumentation/heading-indicator/indicated-heading-deg"] = (vector1.at(11));
    dataRead["/instrumentation/magnetic-compass/indicated-heading-deg"] = (vector1.at(12));
    dataRead["/instrumentation/slip-skid-ball/indicated-slip-skid"] = (vector1.at(13));
    dataRead["/instrumentation/turn-indicator/indicated-turn-rate"] = (vector1.at(14));
    dataRead["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = (vector1.at(15));
    dataRead["/controls/flight/aileron"] = (vector1.at(16));
    dataRead["/controls/flight/elevator"] = (vector1.at(17));
    dataRead["/controls/flight/rudder"] = (vector1.at(18));
    dataRead["/controls/flight/flaps"] = (vector1.at(19));
    dataRead["/controls/engines/current-engine/throttle"] = (vector1.at(20));
    dataRead["/engines/engine/rpm"] = (vector1.at(21));


}