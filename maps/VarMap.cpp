//
// Created by Eldar on 19-Dec-18.
//

#include "VarMap.h"

map<string, Var *> VarMap::symbolTable;// = {{"heading", new BoundedVar("/instrumentation/heading-indicator/offset-deg")}};

void VarMap::update(string varName, Var *var) {
    symbolTable[varName] = var;
}

void VarMap::add(string varName, Var *var) {
    symbolTable.insert(make_pair(varName, var));
}

bool VarMap::isVarExists(string var) {
    if (symbolTable.count(var) != 0) {
        return true;
    }
    return false;
}

Var *VarMap::getVar(string var) {
    if (isVarExists(var)) {
        return symbolTable[var];
    }
    return NULL;
}

void VarMap::release() {
    for (map<string, Var *>::iterator it = symbolTable.begin(); it != symbolTable.end(); ++it) {
        delete it->second;
    }
}
