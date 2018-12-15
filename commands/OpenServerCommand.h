//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_OPENSERVERCOMMAND_H
#define SIMULATOR_OPENSERVERCOMMAND_H

#include "Command.h"
#include "../Utils.h"

class OpenServerCommand : Command {
public:
    virtual void doCommand(string str);
    int stringToInt(string str);
};

#endif //SIMULATOR_OPENSERVERCOMMAND_H
