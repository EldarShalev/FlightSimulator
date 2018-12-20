//
// Created by Eldar on 16-Dec-18.
//

#include "Parser.h"
#include "Global/VarMap.h"

void Parser::parser(vector<string> lexerOutput, CommandsMap *map2) {
    for (vector<string>::iterator it = lexerOutput.begin(); it != lexerOutput.end(); ++it) {
        // If we have a command for the string
        if (map2->getCommand(*it) != NULL) {
            Command *d = map2->getCommand(*it);
            vector<string> tempSplit(lexerOutput.begin() + 1, lexerOutput.end());
            d->doCommand(tempSplit);
            // Else if we have a var to assign
        } else if (VarMap::isVarExisted(*it)) {

        }
    }
}