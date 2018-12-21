//
// Created by Eldar on 12/15/2018.
//

#include "CreateCommand.h"

void CreateCommand::doCommand(vector<string> str) {
    cout << "Creating var " << str[0] << endl;
    VarMap::add(str[0], new Var());
}