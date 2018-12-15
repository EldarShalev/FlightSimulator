//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_COMMAND_H

#include <string>

#define SIMULATOR_COMMAND_H
using namespace std;

class Command {

public:
    virtual void doCommand(string str){};
};


#endif //SIMULATOR_COMMAND_H
