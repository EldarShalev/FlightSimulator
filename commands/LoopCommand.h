//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_LOOPCOMMAND_H
#define SIMULATOR_LOOPCOMMAND_H

#include "input/Utils.h"
#include "maps/VarMap.h"
#include "maps/CommandsMap.h"
#include "input/ShuntingYard.h"


class LoopCommand : public Command {
private:
    static CommandsMap *commandsMap;
    static VarMap varMap;
    static ShuntingYard shuntingYard;

    static vector<vector<string>> commands;
    static bool isOpen;
    static vector<string> theCondition;
public:

    virtual void doCommand(vector<string> str);

    static bool isWhileOpen() { return isOpen; }

    static void close() { isOpen = false; }

    static void open() { isOpen = true; }

    static const vector<string> &getTheCondition();

    static void setCondition(const vector<string> &theCondition);

    static bool checkCondition();

    static void addVector(vector<string> vic);

    static void start();

    static vector<string> createParsedInput(vector<string> &input, int idx);

    static Expression *getExpression(vector<string> &input, int idx);
};

#endif //SIMULATOR_LOOPCOMMAND_H
