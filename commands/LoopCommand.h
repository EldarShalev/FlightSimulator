//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_LOOPCOMMAND_H
#define SIMULATOR_LOOPCOMMAND_H

#include "../Utils.h"

class LoopCommand : Command {
public:
    virtual void doCommand(string str);
};

#endif //SIMULATOR_LOOPCOMMAND_H
