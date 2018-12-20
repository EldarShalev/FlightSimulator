//
// Created by Eldar on 16-Dec-18.
//

#include "Parser.h"
#include "Global/VarMap.h"

void Parser::parse(vector<string> input) {
    for (vector<string>::iterator it = input.begin(); it != input.end(); ++it) {
        if (commandsMap->getCommand(*it) != NULL) {
            // If we have a command for the string
            Command *d = commandsMap->getCommand(*it);
            vector<string> tempSplit(input.begin() + 1, input.end());
            d->doCommand(tempSplit);
        } else if (VarMap::isVarExists(*it)) {
            // Else if we have a var to assign
            // TODO
        }
    }
}

