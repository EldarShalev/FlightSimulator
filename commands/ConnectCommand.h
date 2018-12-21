//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_CONNECTCOMMAND_H
#define SIMULATOR_CONNECTCOMMAND_H

#include "Command.h"
#include "input/Utils.h"
#include "maps/VarMap.h"
#include "reader/ConnectionsManager.h"

class ConnectCommand : public Command {
public:
    ConnectCommand(){}
    virtual void doCommand(vector<string> str);
};

#endif //SIMULATOR_CONNECTCOMMAND_H
