//
// Created by Eldar on 19-Dec-18.
//

#include <data/Var.h>
#include "VarMap.h"

map<string, Var *> VarMap::symbolTable;

void VarMap::addOrUpdateVar(string varName, Var *var) {
    if (isVarExists(varName)) {
        symbolTable[varName] = var;
    } else {
        symbolTable.insert(make_pair(varName, var));
    }
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
