//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_OPENSERVERCOMMAND_H
#define SIMULATOR_OPENSERVERCOMMAND_H

#include "Command.h"
#include "input/Utils.h"
#include "reader/DataReaderServer.h"
#include "data/MyException.h"

class OpenServerCommand : public Command {
public:
    virtual void doCommand(vector <string> str);
};

#endif //SIMULATOR_OPENSERVERCOMMAND_H
