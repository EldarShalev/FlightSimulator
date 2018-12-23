//
// Created by Eldar on 12/15/2018.
//

#include "LoopCommand.h"

bool LoopCommand::isOpen = false;
vector<string> LoopCommand::theCondition;
vector<vector<string>> LoopCommand::commands;

 CommandsMap * LoopCommand::commandsMap;
 VarMap LoopCommand::varMap;
 ShuntingYard LoopCommand::shuntingYard;


void LoopCommand::doCommand(vector<string> str) {

    //TODO - build loop!

}

const vector<string> &LoopCommand::getTheCondition() {
    return theCondition;
}

void LoopCommand::setCondition(const vector<string> &theCondition) {
    LoopCommand::theCondition = theCondition;
}

bool LoopCommand::checkCondition() {
    // In case there is no condition
    if (theCondition.empty()) {
        return false;
    }
    string left = theCondition.at(0);
    string condition = theCondition.at(1);
    string right = theCondition.at(2);
    double valueOfLeft, valueOfRight;
    if (VarMap::isVarExists(left)) {
        valueOfLeft = VarMap::getVar(left)->get();
    } else {
        // left expression is a number
        valueOfLeft = Utils::stringToDouble(left);
    }

    if (VarMap::isVarExists(right)) {
        valueOfRight = VarMap::getVar(right)->get();
    } else {
        // right expression is a number
        valueOfRight = Utils::stringToDouble(right);
    }

    if (condition == "<") {
        return valueOfLeft < valueOfRight;
    }
}


void LoopCommand::addVector(vector<string> vic) {
    commands.push_back(vic);
}

void LoopCommand::start() {
    while (checkCondition()){
        for (int i=0;i<commands.size();i++) {
            vector<string> args = commands.at(i);
            // Third step - replace all existing vars with their values, unless its the first argument - then its an assignment and we don't need to replace it, so we are skipping it
            for (int i = 1; i < args.size(); ++i) {
                if (varMap.isVarExists(args[i])) {
                    Var *temp = varMap.getVar(args[i]);
                    args[i] = Utils::doubleToString(temp->get());
                }
            }

            // Fourth step - find the command, there should only be 1 per line, unless its var (or bounded var)
            for (int i = 0; i < args.size(); ++i) {
                if (commandsMap->getCommand(args[i]) != NULL) {
                    Command *d = commandsMap->getCommand(args[i]);
                    if (args.size() - i - 2 > 1) { //more then 1 argument left
                        vector<string> newInput = createParsedInput(args, i);
                        d->doCommand(newInput);
                    } else {
                        d->doCommand(args);
                    }
                    return; //No more commands on this line
                }
            }

        }
    }

}

vector<string> LoopCommand::createParsedInput(vector<string> &input, int idx) {
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

Expression *LoopCommand::getExpression(vector<string> &input, int idx) {
    vector<string> smellsLikeAnExpression(input.begin() + idx + 1, input.end());
    string joinedString;
    Utils::join(smellsLikeAnExpression, ' ', joinedString);
    Expression *expression = shuntingYard.toExpression(joinedString);
    return expression;
}