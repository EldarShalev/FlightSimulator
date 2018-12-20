//
// Created by Eldar on 12/15/2018.
//

#include "PrintCommand.h"

void PrintCommand::doCommand(vector<string> str) {
    string toPrint = Utils::getNextString(str.at(0), ' ', 1);
    cout << toPrint;
}