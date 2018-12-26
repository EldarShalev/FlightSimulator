//
// Created by Eldar on 25-Dec-18.
//

#ifndef SIMULATOR_CONDITIONCOMMAND_H
#define SIMULATOR_CONDITIONCOMMAND_H

#include "Command.h"
#include "input/ParsingUtils.h"

class ConditionCommand : public Command {
private:
    vector<string> condition;
    bool isOpenMember = false;
    vector<ConditionCommand *> nested;
    vector<ConditionCommand *> toRelease;
public:
    vector<vector<string>> args;
    vector<Command *> commands;

    virtual void doCommand(vector<string> str) {}

    bool isOpen();

    bool close();

    void open();

    bool checkCondition();

    void addCommand(Command *cmd, vector<string> arguments);

    void addConditionCommandToNested(ConditionCommand *conditionCommand);

    void setCondition(const vector<string> &condition);

    int seekForExpression(vector<string> args);

    virtual ~ConditionCommand();
};

#endif //SIMULATOR_CONDITIONCOMMAND_H
