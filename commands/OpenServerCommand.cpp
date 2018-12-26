//
// Created by Eldar on 14-Dec-18.
//
#include "OpenServerCommand.h"

/**
 * Opening server command.
 * validation of two correct arguments - port and times per second.
 */
void OpenServerCommand::doCommand(vector<string> str) {

    try {
        if (str.size() != 3) {
            throw MyException("Can accept only 3 arguments", __func__, "OpenServerCommand");
        }
        // Simple opening server parsing and send to connect data reader method
        int port = Utils::stringToInt(str.at(1));
        int sampleRate = Utils::stringToInt(str.at(2));
        ConnectionsManager::connectDataReaderServer("127.0.0.1", port, sampleRate);
    } catch (MyException &e1) {
        cout << "OpenServerCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;

    }
}
