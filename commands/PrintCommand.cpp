//
// Created by Eldar on 12/15/2018.
//

#include "PrintCommand.h"

void PrintCommand::doCommand(vector<string> str) {
    vector<string> toPrint(str.begin() + 1, str.end());
    string joinedString;
    Utils::join(toPrint, ' ', joinedString);
    cout << "Print command: " << joinedString << endl;
}