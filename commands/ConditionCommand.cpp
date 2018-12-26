//
// Created by Eldar on 25-Dec-18.
//

#include "ConditionCommand.h"


const vector<string> &ConditionCommand::getCondtion() const {
    return this->condtion;
}

void ConditionCommand::setCondition(const vector<string> &condtion) {
    ConditionCommand::condtion = condtion;
}

void ConditionCommand::addCommand(Command *cmd, vector<string> args1) {
    if (nested.size() > 0) {
        nested[nested.size() - 1]->addCommand(cmd, args1);
    }
    commands.push_back(cmd);
    args.push_back(args1);
}

bool ConditionCommand::isOpen() {
    return this->isOpenMember;
}

void ConditionCommand::open() {
    isOpenMember = true;
}

bool ConditionCommand::close() {
    if (nested.size() > 0) {
        bool child = nested[nested.size() - 1]->close();
        if (child) {
            nested.pop_back();
        }
        return false;
    } else {
        this->isOpenMember = false;
        return true;
    }
}

bool ConditionCommand::checkCondition() {
    // Replace vars in the input to their value
    vector<string> args;
    vector<string> result;
    Expression *leftexp;
    Expression *rightexp;
    if (condtion[condtion.size() - 1] == "{") {
        vector<string> arg1(condtion.begin(), condtion.end() - 1);
        vector<string> args = ParsingUtils::replaceExistingVars(arg1);
        result = args;
    } else {
        vector<string> arg1(condtion.begin(), condtion.end());
        vector<string> args = ParsingUtils::replaceExistingVars(arg1);
        result = args;
    }
    int place = seekForExpression(result);
    vector<string> left(result.begin() + 1, result.begin() + place);
    vector<string> right(result.begin() + place + 1, result.end());
    if (left.size() == 1) {
        if (left.at(0)[0] == '-') {
            leftexp = (new Negative(new Number(stod(left.at(0)))));
        } else
            leftexp = new Number(stod(left.at(0)));
    } else {
        leftexp = ParsingUtils::getExpression(left, 0);
    }

    if (right.size() == 1) {
        if (right.at(0)[0] == '-') {
            rightexp = (new Negative(new Number(stod(right.at(0)))));
        } else
            rightexp = new Number(stod(right.at(0)));
    } else {
        rightexp = ParsingUtils::getExpression(right, 0);
    }
    return (ParsingUtils::checkExpression(leftexp, rightexp, result.at(place)));


}

void ConditionCommand::addConditionCommandToNested(ConditionCommand *conditionCommand) {
    nested.push_back(conditionCommand);
}

int ConditionCommand::seekForExpression(vector<string> args2) {
    // We use regulat for loop and not iterator because we need the number
    for (int i = 0; i < args2.size(); i++) {
        if (args2[i] == "<" || args2[i] == ">" || args2[i] == "==" || args2[i] == ">=" || args2[i] == "<=" ||
            args2[i] == "!=" || args2[i] == "&&" || args2[i] == "||") {
            return i;
        }
    }
}