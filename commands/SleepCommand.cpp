//
// Created by Eldar on 12/15/2018.
//

#include "SleepCommand.h"

void SleepCommand::doCommand(string str) {
    string ms = Utils::getNextString(str,' ',1);

    std::this_thread::sleep_for(std::chrono::milliseconds(atoi(ms.c_str())));
}