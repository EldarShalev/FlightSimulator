//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_COMMAND_H
#define SIMULATOR_COMMAND_H

#include <string>
using namespace std;

class Command {
public:
    virtual void doCommand(string str){};
};

#endif //SIMULATOR_COMMAND_H
