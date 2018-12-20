//
// Created by Eldar on 12/15/2018.
//

#include "SleepCommand.h"

void SleepCommand::doCommand(vector<string> str) {
    string ms = Utils::getNextString(str.at(0), ' ', 1);
    try {
        std::this_thread::sleep_for(std::chrono::milliseconds(Utils::stringToInt(ms.c_str())));
    } catch (MyException &e1) {
        cout << "SleepCommand : " << __func__ << " : ";
        cout << e1.convertFromString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;
    }
}