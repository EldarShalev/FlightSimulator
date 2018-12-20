//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_PRINTCOMMAND_H
#define SIMULATOR_PRINTCOMMAND_H

#include "../Utils.h"
#include <iostream>
using namespace std;

class PrintCommand : public Command {
public:
    virtual void doCommand(vector<string> str);
};

#endif //SIMULATOR_PRINTCOMMAND_H
