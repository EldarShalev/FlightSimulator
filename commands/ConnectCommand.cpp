//
// Created by Eldar on 12/15/2018.
//

#include "ConnectCommand.h"

void ConnectCommand::doCommand(vector<string> str) {

    try {
        // Simple parsing and send to connect reader
        string ip = str.at(1);
        int port = Utils::stringToInt(str.at(2));
        ConnectionsManager::connectReaderClient(ip, port);

    } catch (MyException &e1) {
        cout << "ConnectCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;
    }
}