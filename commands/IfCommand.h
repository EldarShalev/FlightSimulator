//
// Created by Eldar on 12/20/2018.
//

#ifndef SIMULATOR_IFCOMMAND_H
#define SIMULATOR_IFCOMMAND_H

#include "input/Utils.h"
#include "input/ParsingUtils.h"
#include "ConditionCommand.h"


class IfCommand : public ConditionCommand {
public:
    virtual void doCommand(vector<string> str);
};

#endif //SIMULATOR_IFCOMMAND_H
