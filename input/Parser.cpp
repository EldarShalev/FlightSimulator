//
// Created by Eldar on 16-Dec-18.
//

#include "Parser.h"

void Parser::parse(vector<string> input) {
    if (input.empty()) {
        return;
    }

    // First if we need to create a var, lets create it and continue to look for set command
    if (input[0] == "var") {
        Command *d = commandsMap->getCommand(input[0]);
        vector<string> arg(input.begin() + 1, input.begin() + 2);
        d->doCommand(arg);
        input.erase(input.begin()); //remove the keyword var
    }

    // Second step - replace all existing vars with their values, unless its the first argument - then its an assignment and we don't need to replace it, so we are skipping it
    for (int i = 1; i < input.size(); ++i) {
        if (varMap.isVarExists(input[i])) {
            input[i] = Utils::doubleToString(varMap.getVar(input[i])->get());
        }
    }

    // Third step - find the command, there should only be 1 per line, unless its var (or bounded var)
    for (int i = 0; i < input.size(); ++i) {
        if (commandsMap->getCommand(input[i]) != NULL) {
            Command *d = commandsMap->getCommand(input[i]);
            if (input[i + 1] == "bind") { //send as is
                d->doCommand(input);
            } else {
                if (input.size() - i - 2 > 1) { //more then 1 argument left
                    vector<string> smellsLikeAnExpression(input.begin() + i + 1, input.end());
                    string joinedString;
                    Utils::join(smellsLikeAnExpression, ' ', joinedString);
                    Expression *expression = shuntingYard.toExpression(joinedString);
                    vector<string> newInput;
                    if (input[i] == "=") {
                        //get var name too!
                        newInput.push_back(input[i - 1]);
                    }
                    newInput.push_back(input[i]);
                    newInput.push_back(Utils::doubleToString(expression->calculate()));
                    delete expression;
                    d->doCommand(newInput);
                } else {
                    d->doCommand(input);
                }
            }
            break; //because we found the command in this line, so we are done here
        }
    }
}

Parser::~Parser() {
    delete commandsMap;
    varMap.release();
}