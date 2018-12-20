//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_HEADINGCOMMAND_H
#define SIMULATOR_HEADINGCOMMAND_H

#include "Command.h"

class HeadingCommand : public Command {
public:
    virtual void doCommand(vector<string> str);
};

#endif //SIMULATOR_HEADINGCOMMAND_H
