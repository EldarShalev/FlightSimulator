//
// Created by Eldar on 25-Dec-18.
//

#ifndef SIMULATOR_CONDITIONCOMMAND_H
#define SIMULATOR_CONDITIONCOMMAND_H

#include "Command.h"
#include "input/ParsingUtils.h"

class ConditionCommand : public Command {
private:
    vector<string> condtion;
    bool isOpenMember = false;
    vector<ConditionCommand *> nested;
public:
    vector<vector<string>> args;
    vector<Command *> commands;
    virtual void doCommand(vector<string> str) {}

    bool isOpen();

    bool close();

    void open();

    bool checkCondition();

    void addCommand(Command *cmd, vector<string> args);

    void addConditionCommandToNested(ConditionCommand *conditionCommand);

    const vector<string> &getCondtion() const;

    void setCondition(const vector<string> &condtion);

    int seekForExpression(vector<string> args);


};


#endif //SIMULATOR_CONDITIONCOMMAND_H
