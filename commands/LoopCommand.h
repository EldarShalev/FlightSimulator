//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_LOOPCOMMAND_H
#define SIMULATOR_LOOPCOMMAND_H

#include "input/Utils.h"

class LoopCommand : public Command {
public:
    virtual void doCommand(vector<string> str);
};

#endif //SIMULATOR_LOOPCOMMAND_H
