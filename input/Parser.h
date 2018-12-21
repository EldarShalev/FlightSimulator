//
// Created by Eldar on 16-Dec-18.
//

#ifndef SIMULATOR_PARSER_H
#define SIMULATOR_PARSER_H

#include <sstream>
#include "maps/CommandsMap.h"
#include "maps/VarMap.h"
#include "ShuntingYard.h"

class Parser {
private:
    CommandsMap *commandsMap;
    ShuntingYard shuntingYard;
    VarMap varMap;
public:
    Parser() {
        commandsMap = new CommandsMap();
    }
    ~Parser();
    void parse(vector<string> input);
};

#endif //SIMULATOR_PARSER_H
