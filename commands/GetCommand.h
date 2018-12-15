//
// Created by Eldar on 12/15/2018.
//

#ifndef FLIGHTSIMULATOR_GETCOMMAND_H
#define FLIGHTSIMULATOR_GETCOMMAND_H

#include "../Utils.h"

class GetCommand : Command {
public:
    virtual void doCommand(string str);
};

#endif //FLIGHTSIMULATOR_GETCOMMAND_H
