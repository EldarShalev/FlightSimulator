//
// Created by Eldar on 12/15/2018.
//

#include "SetCommand.h"

void SetCommand::doCommand(vector<string> str) {
    cout << "Setting var " << str[0] << endl;
    try {
        if (!(str.size() == 4 || str.size() == 3)) {
            throw MyException("Can accept only 4 arguments", __func__, "SetCommand");
        }
        if (str.size() == 4) {
            bool shouldBind = false;
            // If we need to bind
            if (str[2] == "bind") {
                shouldBind = true;
            }

            Var *var;

            if (shouldBind) {
                string temp = str[3];
                string temp2 = temp.substr(1, temp.length() - 2);
                var = new BoundedVar(temp2, str[0]);

            } else {
                // Checking in case negative number
                if (str.at(2) == "-") {
                    string tempValue = "-" + str[3];
                    var = new Var(Utils::stringToDouble(tempValue));
                } else {
                    var = new Var(Utils::stringToDouble(str[2]));
                }
            }

            VarMap::update(str[0], var);
        } else { // we might set with bounded var, therefor we need bounded var get & set
            // If we get bounded var, need to set it's value
            if (VarMap::isVarExists(str.at(0))) {
                Var *bounded = VarMap::getVar(str.at(0));
                bounded->set(Utils::stringToDouble(str[2]));
            }
        }
    } catch (MyException &e1) {
        cout << "SetCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;
    }
}