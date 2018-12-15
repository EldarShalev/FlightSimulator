//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_SETCOMMAND_H
#define SIMULATOR_SETCOMMAND_H

#include "../Utils.h"

class SetCommand : Command {
public:
    virtual void doCommand(string str);
};

#endif //SIMULATOR_SETCOMMAND_H
