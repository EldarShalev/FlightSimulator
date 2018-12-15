//
// Created by Eldar on 12/15/2018.
//

#ifndef FLIGHTSIMULATOR_CREATECOMMAND_H
#define FLIGHTSIMULATOR_CREATECOMMAND_H

#include "../Utils.h"

class CreateCommand : Command {
public:
    virtual void doCommand(string str);
};

#endif //FLIGHTSIMULATOR_CREATECOMMAND_H
