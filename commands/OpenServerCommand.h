//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_OPENSERVERCOMMAND_H
#define SIMULATOR_OPENSERVERCOMMAND_H

#include "Command.h"
#include "input/Utils.h"
#include "data/MyException.h"
#include "reader/ConnectionsManager.h"

class OpenServerCommand : public Command {
public:
    virtual void doCommand(vector <string> str);
};

#endif //SIMULATOR_OPENSERVERCOMMAND_H
