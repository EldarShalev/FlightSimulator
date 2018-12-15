//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_COMMANDSMAP_H
#define SIMULATOR_COMMANDSMAP_H

#include "commands/OpenServerCommand.h"
#include "commands/ConnectCommand.h"
#include "commands/GetCommand.h"
#include "commands/SetCommand.h"
#include "commands/HeadingCommand.h"
#include "commands/IsVarExistsCommand.h"
#include "commands/LoopCommand.h"
#include "commands/PrintCommand.h"
#include "commands/SleepCommand.h"
#include "commands/CreateCommand.h"
#include "commands/BindCommand.h"

#include "expressions/Number.h"
#include "expressions/And.h"
#include "expressions/Or.h"
#include "expressions/Not.h"
#include "expressions/GreaterThan.h"
#include "expressions/LessThan.h"
#include "expressions/Divide.h"
#include "expressions/Multiply.h"
#include "expressions/Plus.h"
#include "expressions/Minus.h"
#include "expressions/Equals.h"

#include <typeinfo>

class CommandsMap {
private:
    map<string, vector<const type_info &>> commands;

    CommandsMap() {
        commands["openDataServer"] = {typeid(OpenServerCommand)};
        commands["connect"] = {typeid(ConnectCommand)};
        commands["bind"] = {typeid(BindCommand)};
        commands["var"] = {typeid(CreateCommand)};
        commands["="] = {typeid(SetCommand)};
        commands["while"] = {typeid(LoopCommand)};
        commands["heading"] = {typeid(HeadingCommand)};
        commands["print"] = {typeid(PrintCommand)};
        commands["sleep"] = {typeid(SleepCommand)};
        commands["=="] = {typeid(Equals)};
        commands[">"] = {typeid(GreaterThan)};
        commands["<"] = {typeid(LessThan)};
        commands["!="] = {typeid(Not)};
        commands["&&"] = {typeid(And)};
        commands["||"] = {typeid(Or)};
        commands[">="] = {typeid(GreaterThan), typeid(Or), typeid(Equals)};
        commands["<="] = {typeid(LessThan), typeid(Or), typeid(Equals)};
        commands["+"] = {typeid(Plus)};
        commands["-"] = {typeid(Minus)};
        commands["*"] = {typeid(Multiply)};
        commands["/"] = {typeid(Divide)};
    }

public:
    vector<const type_info &> getCommand(string cmd) { return commands[cmd]; }
};

#endif //SIMULATOR_COMMANDSMAP_H

