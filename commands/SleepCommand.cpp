//
// Created by Eldar on 12/15/2018.
//

#include "SleepCommand.h"

void SleepCommand::doCommand(vector<string> str) {
    try {
        if (str.size() != 2) {
            throw MyException("Can accept only 2 arguments", __func__, "SleepCommand");
        }
        cout << "Sleeping for  " << str[1] << " ms " << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(Utils::stringToInt(str[1].c_str())));
    } catch (MyException &e1) {
        cout << "SleepCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;
    }
}