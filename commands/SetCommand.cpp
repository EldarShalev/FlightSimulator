//
// Created by Eldar on 12/15/2018.
//

#include "SetCommand.h"

void SetCommand::doCommand(vector<string> str) {
    cout << "Setting var " << str[0] << endl;
    try {
        if (str.size() != 4) {
            throw MyException("Can accept only 4 arguments", __func__, "SetCommand");
        }
        Var *var;
        bool shouldBind = false;
        if (str[2] == "bind") {
            shouldBind = true;
        }

        if (shouldBind) {
            var = new BoundedVar(str[3]);
        } else {
            var = new Var(Utils::stringToDouble(str[2]));
        }

        VarMap::update(str[0], var);
    } catch (MyException &e1) {
        cout << "SetCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;
    }
}