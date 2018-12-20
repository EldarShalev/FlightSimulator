//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_COMMAND_H
#define SIMULATOR_COMMAND_H

#include <string>
#include <vector>

using namespace std;

class Command {
public:
    virtual void doCommand(vector<string> str) {};

    Command() {}
};

#endif //SIMULATOR_COMMAND_H
