//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_SETCOMMAND_H
#define SIMULATOR_SETCOMMAND_H

#include "../Utils.h"
#include "Global/VarMap.h"
#include "data/BoundedVar.h"

class SetCommand : public Command {
public:
    virtual void doCommand(vector<string> str);
};

#endif //SIMULATOR_SETCOMMAND_H
