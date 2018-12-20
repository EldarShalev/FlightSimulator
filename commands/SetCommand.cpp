//
// Created by Eldar on 12/15/2018.
//

#include "SetCommand.h"
#include "Global/VarMap.h"

void SetCommand::doCommand(vector<string> str) {
    bool foungBind = false;
    for (vector<string>::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it == "bind") {
            foungBind = true;
        }
    }
    //TODO  If there is bind, the set shouldn't work?
    if (!foungBind) {
        try {
            int value = Utils::stringToInt(str.at(2));
            VarMap::addOrSetVarAndValue(str.at(0),value);
        } catch (MyException& e1) {
            cout << "SetCommand : " << __func__ << " : ";
            cout <<e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() <<endl ;
        }
    }

    //TODO - set var and update symbolTable
}