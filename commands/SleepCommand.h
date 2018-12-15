//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_SLEEPCOMMAND_H
#define SIMULATOR_SLEEPCOMMAND_H

#include "../Utils.h"
#include <thread>
#include <chrono>

class SleepCommand : Command {
public:
    virtual void doCommand(string str);
};

#endif //SIMULATOR_SLEEPCOMMAND_H
