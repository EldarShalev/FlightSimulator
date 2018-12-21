//
// Created by Eldar on 12/15/2018.
//

#ifndef FLIGHTSIMULATOR_CREATECOMMAND_H
#define FLIGHTSIMULATOR_CREATECOMMAND_H

#include "input/Utils.h"
#include "data/Var.h"
#include "maps/VarMap.h"

class CreateCommand : public Command {
public:
    virtual void doCommand(vector<string> str);
};

#endif //FLIGHTSIMULATOR_CREATECOMMAND_H
