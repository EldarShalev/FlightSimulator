//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_LOOPCOMMAND_H
#define SIMULATOR_LOOPCOMMAND_H

#include "input/Utils.h"
#include "maps/VarMap.h"
class LoopCommand : public Command {
private:
    vector<Command> commands;
    static bool isOpen;
public:

    virtual void doCommand(vector<string> str);

    static bool isWhileOpen() { return isOpen; }

    static void close() { isOpen = false; }

    //static void open() { isOpen = true; }
};

#endif //SIMULATOR_LOOPCOMMAND_H
