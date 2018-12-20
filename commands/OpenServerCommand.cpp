//
// Created by Eldar on 14-Dec-18.
//
#include "OpenServerCommand.h"
#include "MyException.h"

/**
 * Opening server command.
 * validation of two correct arguments - port and times per second.
 */
void OpenServerCommand::doCommand(vector<string> str) {

    try {
        int port = Utils::stringToInt(str.at(0));
        int times = Utils::stringToInt(str.at(1));
    } catch (MyException &e1) {
        cout << "OpenServerCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;

    }
    // TODO add here DataReaderServer

}
