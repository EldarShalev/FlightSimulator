//
// Created by Eldar on 12/20/2018.
//

#ifndef SIMULATOR_IFCOMMAND_H
#define SIMULATOR_IFCOMMAND_H

#include "../Utils.h"

class IfCommand : public Command {
public:
    virtual void doCommand(vector<string> str);
};

#endif //SIMULATOR_IFCOMMAND_H
