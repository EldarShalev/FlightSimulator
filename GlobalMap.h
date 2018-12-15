//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_GLOBALMAP_H

#include "AllCommands/OpenServerCommand.h"

#define SIMULATOR_GLOBALMAP_H


class GlobalMap {
private:
    static map<string, Command> map1;

public:
    static void initMap();

    static map<string, Command> getMap() { return map1; }
};


#endif //SIMULATOR_GLOBALMAP_H
