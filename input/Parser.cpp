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
        vector <string> arg(input.begin() + 1, input.begin() + 2);
        d->doCommand(arg);
        input.erase(input.begin()); //remove the keyword var
    }


    // Then check for bind command
    if (input.size() >= 3 && input[2] == "bind") {
        vector <string> bindPathVector(input.begin() + 3, input.end());
        string joinedPath;
        Utils::buildPathFromVector(bindPathVector, joinedPath);
        // build command args: x = bind /path/to/file
        vector <string> args(input.begin(), input.begin() + 3);
        args.push_back(joinedPath);
        Command *d = commandsMap->getCommand(input[1]); // set command
        d->doCommand(args);
        return; //No more commands on this line
    }


    if (input[0] == "while") {
        //LoopCommand::open();
    }


    // Third step - replace all existing vars with their values, unless its the first argument - then its an assignment and we don't need to replace it, so we are skipping it
    for (int i = 1; i < input.size(); ++i) {
        if (varMap.isVarExists(input[i])) {
            Var *temp = varMap.getVar(input[i]);
            input[i] = Utils::doubleToString(temp->get());
        }
    }

    // Fourth step - find the command, there should only be 1 per line, unless its var (or bounded var)
    for (int i = 0; i < input.size(); ++i) {
        if (commandsMap->getCommand(input[i]) != NULL) {
            Command *d = commandsMap->getCommand(input[i]);
            if (input.size() - i - 2 > 1) { //more then 1 argument left
                vector <string> newInput = createParsedInput(input, i);
                d->doCommand(newInput);
            } else {
                d->doCommand(input);
            }
            return; //No more commands on this line
        }
    }
}

vector<string> Parser::createParsedInput(vector<string> &input, int idx) {
    Expression *expression = getExpression(input, idx);
    vector <string> newInput;
    if (input[idx] == "=") {
        //get var name too!
        newInput.push_back(input[idx - 1]);
    }
    newInput.push_back(input[idx]);
    newInput.push_back(Utils::doubleToString(expression->calculate()));
    delete expression;
    return newInput;
}

Expression *Parser::getExpression(vector<string> &input, int idx) {
    vector <string> smellsLikeAnExpression(input.begin() + idx + 1, input.end());
    string joinedString;
    Utils::join(smellsLikeAnExpression, ' ', joinedString);
    Expression *expression = shuntingYard.toExpression(joinedString);
    return expression;
}

Parser::~Parser() {
    delete commandsMap;
    varMap.release();
}