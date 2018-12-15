//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_CONNECTCOMMAND_H
#define SIMULATOR_CONNECTCOMMAND_H

#include "Command.h"
#include "../Utils.h"

class ConnectCommand : Command {
public:
    virtual void doCommand(string str);
};

#endif //SIMULATOR_CONNECTCOMMAND_H
