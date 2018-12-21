//
// Created by Eldar on 12/15/2018.
//

#include "ConnectCommand.h"

void ConnectCommand::doCommand(vector<string> str) {

    try {
        string ip = str.at(0);
        int port = Utils::stringToInt(str.at(1));
        // TODO - don't forget to delete allocated memory
        ConnectReaderClient *connectReaderClient = new ConnectReaderClient(ip, port);
        connectReaderClient->connect();

    } catch (MyException &e1) {
        cout << "ConnectCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;
    }
}