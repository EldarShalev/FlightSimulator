//
// Created by Eldar on 19-Dec-18.
//

#ifndef SIMULATOR_VARMAP_H
#define SIMULATOR_VARMAP_H

#include <map>
#include <string>
#include "data/Var.h"
#include "data/BoundedVar.h"

using namespace std;

class VarMap {

private:
    static map<string, Var *> symbolTable;
public:
    static Var *getVar(string var);

    static bool isVarExists(string var);

    static void update(string varName, Var *var);

    static void add(string varName, Var *var);

    static void release();
};

#endif //SIMULATOR_VARMAP_H
