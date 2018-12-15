//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_BINDCOMMAND_H
#define SIMULATOR_BINDCOMMAND_H

#include "../Utils.h"

class BindCommand : Command {
public:
    virtual void doCommand(string str);
};

#endif //SIMULATOR_BINDCOMMAND_H
