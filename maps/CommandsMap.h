//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_COMMANDSMAP_H
#define SIMULATOR_COMMANDSMAP_H

#include "commands/OpenServerCommand.h"
#include "commands/ConnectCommand.h"
#include "commands/SetCommand.h"
#include "commands/LoopCommand.h"
#include "commands/PrintCommand.h"
#include "commands/SleepCommand.h"
#include "commands/CreateCommand.h"
#include "commands/IfCommand.h"
#include "Command.h"

#include <map>

using namespace std;

class CommandsMap {
public:
    map<string, Command *> commands;
    map<string, ConditionCommand*> cmdCommands;

public:
    CommandsMap() {
        commands.insert(make_pair("openDataServer", new OpenServerCommand()));
        commands.insert(make_pair("connect", new ConnectCommand()));
        commands.insert(make_pair("var", new CreateCommand()));
        commands.insert(make_pair("=", new SetCommand()));
        commands.insert(make_pair("print", new PrintCommand()));
        commands.insert(make_pair("sleep", new SleepCommand()));

        cmdCommands.insert(make_pair("while", new LoopCommand()));
        cmdCommands.insert(make_pair("if", new IfCommand()));
    }

    virtual Command *getCommand(string cmd) {
        if (commands.count(cmd) != 0) {
            return commands[cmd];
        }
        return NULL;
    }

    virtual ConditionCommand *getCmdCommand(string cmd) {
        if (cmdCommands.count(cmd) != 0) {
            return cmdCommands[cmd];
        }
        return NULL;
    }

    ~CommandsMap() {
        for (map<string, Command *>::iterator it = commands.begin(); it != commands.end(); ++it) {
            delete it->second;
        }

        for (map<string, ConditionCommand *>::iterator it = cmdCommands.begin(); it != cmdCommands.end(); ++it) {
            delete it->second;
        }
    }
};

#endif //SIMULATOR_COMMANDSMAP_H

