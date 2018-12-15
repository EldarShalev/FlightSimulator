//
// Created by Eldar on 12/15/2018.
//

#include "ConnectCommand.h"

void ConnectCommand::doCommand(string str) {
    string ip = Utils::getNextString(str,' ',1);
    string port = Utils::getNextString(str,' ',2);

    //TODO - connect!

}