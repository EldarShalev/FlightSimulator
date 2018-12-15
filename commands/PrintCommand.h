//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_PRINTCOMMAND_H
#define SIMULATOR_PRINTCOMMAND_H

#include "../Utils.h"
#include <iostream>
using namespace std;

class PrintCommand : Command {
public:
    virtual void doCommand(string str);
};

#endif //SIMULATOR_PRINTCOMMAND_H
