//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_OPENSERVERCOMMAND_H
#include "../Command.h"
#include "../Utils.h"

#define SIMULATOR_OPENSERVERCOMMAND_H


class OpenServerCommand : Command {

public:
    void doCommand(string str);
    int stringToInt(string str);

};


#endif //SIMULATOR_OPENSERVERCOMMAND_H
