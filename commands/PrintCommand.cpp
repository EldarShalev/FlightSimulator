//
// Created by Eldar on 12/15/2018.
//

#include "PrintCommand.h"

void PrintCommand::doCommand(string str) {
    string toPrint = Utils::getNextString(str,' ',1);

    cout << toPrint;
}