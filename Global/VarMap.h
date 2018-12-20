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
    static map<string, double> symbolTable;
public:

    static double getValue(string var) {
        if (isVarExisted(var)) {
            return symbolTable[var];
        }
        return -1;
    }

      static bool isVarExisted(string var) {
        if (symbolTable.count(var) != 0) {
            return true;
        }
        return false;
    }

      static void addOrSetVarAndValue(string var, int value) {
        // If var already exists - override value
        if (isVarExisted(var)) {
            symbolTable[var] = value;
        } else {
            symbolTable.insert(make_pair(var, value));
        }
    }


};



#endif //SIMULATOR_VARMAP_H
