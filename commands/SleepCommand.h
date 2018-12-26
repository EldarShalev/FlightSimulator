//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_SLEEPCOMMAND_H
#define SIMULATOR_SLEEPCOMMAND_H

#include "input/Utils.h"
#include "Command.h"

#include <thread>
#include <chrono>

class SleepCommand : public Command {
public:
    virtual void doCommand(vector<string> str);
};

#endif //SIMULATOR_SLEEPCOMMAND_H
