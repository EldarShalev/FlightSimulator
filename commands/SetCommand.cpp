//
// Created by Eldar on 12/15/2018.
//

#include "SetCommand.h"

void SetCommand::doCommand(string str) {
    string varName = Utils::getNextString(str,' ',1);
    string value = Utils::getNextString(str,' ',2);

    //TODO - set var and update symbolTable
}