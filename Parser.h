//
// Created by Eldar on 16-Dec-18.
//

#ifndef SIMULATOR_PARSER_H
#define SIMULATOR_PARSER_H

#include "Global/CommandsMap.h"


class Parser {
private:
    CommandsMap *commandsMap;
public:
    Parser() { commandsMap = new CommandsMap(); }

    void parse(vector<string> input);

};


#endif //SIMULATOR_PARSER_H
