//
// Created by Eldar on 12/15/2018.
//

#include "CreateCommand.h"
#include "Global/VarMap.h"

void CreateCommand::doCommand(vector<string> str) {
    string varName = str.at(0);
    Var *v = new Var(-1);
    VarMap::addOrUpdateVar(varName, v);
}