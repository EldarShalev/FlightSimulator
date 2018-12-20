//
// Created by Eldar on 19-Dec-18.
//

#ifndef SIMULATOR_VARMAP_H
#define SIMULATOR_VARMAP_H

#include <map>
#include <string>

using namespace std;

class VarMap {

public:
    static map<string, Var> symbolTable;
public:

    static Var getValue(string var) {
        if (isVarExists(var)) {
            return symbolTable[var];
        }
        return -1;
    }

    static bool isVarExists(string var) {
        if (symbolTable.count(var) != 0) {
            return true;
        }
        return false;
    }

    static void addOrSetVarAndValue(string var, int value) {
        // If var already exists - override value
        if (isVarExists(var)) {
            symbolTable[var] = value;
        } else {
            symbolTable.insert(make_pair(var, value));
        }
    }


};

#endif //SIMULATOR_VARMAP_H
