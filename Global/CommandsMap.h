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

#include <map>
#include "Command.h"

using namespace std;

class CommandsMap {
public:
    map<string, Command *> commands;

public:
    CommandsMap() {

        commands.insert(make_pair("openDataServer", new OpenServerCommand()));
        commands.insert(make_pair("connect", new ConnectCommand()));
        commands.insert(make_pair("bind", new BindCommand()));
        commands.insert(make_pair("var", new CreateCommand()));
        commands.insert(make_pair("=", new SetCommand()));
        commands.insert(make_pair("while", new LoopCommand()));
        commands.insert(make_pair("heading", new HeadingCommand()));
        commands.insert(make_pair("print", new PrintCommand()));
        commands.insert(make_pair("sleep", new SleepCommand()));

        // TODO - handle expressions
//        commands["=="] = {typeid(Equals)};
//        commands[">"] = {typeid(GreaterThan)};
//        commands["<"] = {typeid(LessThan)};
//        commands["!="] = {typeid(Not)};
//        commands["&&"] = {typeid(And)};
//        commands["||"] = {typeid(Or)};
//        commands[">="] = {typeid(GreaterThan), typeid(Or), typeid(Equals)};
//        commands["<="] = {typeid(LessThan), typeid(Or), typeid(Equals)};
//        commands["+"] = {typeid(Plus)};
//        commands["-"] = {typeid(Minus)};
//        commands["*"] = {typeid(Multiply)};
//        commands["/"] = {typeid(Divide)};
    }

    virtual Command *getCommand(string cmd) {
        if (commands.count(cmd) != 0) {
            return commands[cmd];
        }
        return NULL;
    }
};

#endif //SIMULATOR_COMMANDSMAP_H

