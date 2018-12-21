//
// Created by Eldar on 12/15/2018.
//

#include "SetCommand.h"

void SetCommand::doCommand(vector<string> str) {
    cout << "Setting var " << str[0] << endl;
    Var *var;
    bool shouldBind = false;
    for (vector<string>::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it == "bind") {
            shouldBind = true;
            break;
        }
    }
    try {
        if (shouldBind) {
            // TODO str[3] is not the full bind
            var = new BoundedVar(str[2]);
        } else {
            var = new Var(Utils::stringToDouble(str[2]));
        }
        VarMap::update(str[0], var);
    } catch (MyException &e1) {
        cout << "SetCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;
    }
}