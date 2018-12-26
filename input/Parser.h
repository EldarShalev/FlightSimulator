//
// Created by Eldar on 16-Dec-18.
//

#ifndef SIMULATOR_PARSER_H
#define SIMULATOR_PARSER_H

#include <sstream>
#include "maps/CommandsMap.h"
#include "ParsingUtils.h"

class Parser {
private:

    bool loopConditionFound = false;
    CommandsMap *commandsMap;
    ConditionCommand *conditionCommand;

public:

    vector<string> createVar(vector<string> input1);

    void bind(vector<string> input1);

    void parse(vector<string> input);

    Parser() {
        commandsMap = new CommandsMap();
    }

    void createCondition(vector<string> input);

    void createWhileCondition(vector<string> input);

    void createIfCondition(vector<string> input);

    ~Parser();

};

#endif //SIMULATOR_PARSER_H
