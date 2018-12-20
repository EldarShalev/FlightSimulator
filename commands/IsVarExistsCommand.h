//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_ISVAREXISTSCOMMAND_H
#define SIMULATOR_ISVAREXISTSCOMMAND_H

#include "../Utils.h"

class IsVarExistsCommand : public Command {
public:
    virtual void doCommand(vector<string> str);
};

#endif //SIMULATOR_ISVAREXISTSCOMMAND_H
