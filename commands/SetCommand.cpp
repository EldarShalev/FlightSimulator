//
// Created by Eldar on 12/15/2018.
//

#include "SetCommand.h"

void SetCommand::doCommand(vector<string> str) {
    Var *var;
    bool shouldBind = false;
    for (vector<string>::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it == "bind") {
            shouldBind = true;
        }
    }
    try {
        if (shouldBind) {
            string filePath = str.at(3);
            double value = 2;//TODO get from bind
            var = new BoundedVar(value, filePath);
        } else {
            var = new Var(Utils::stringToDouble(str.at(2)));
        }
        VarMap::addOrUpdateVar(str.at(0), var);
    } catch (MyException &e1) {
        cout << "SetCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;
    }
}