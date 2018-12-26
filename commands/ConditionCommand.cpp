//
// Created by Eldar on 25-Dec-18.
//

#include "ConditionCommand.h"

void ConditionCommand::setCondition(const vector<string> &condition) {
    this->condition = condition;
}

void ConditionCommand::addCommand(Command *cmd, vector<string> arguments) {
    if (nested.size() > 0) {
        nested[nested.size() - 1]->addCommand(cmd, arguments);
    } else {
        commands.push_back(cmd);
        args.push_back(arguments);
    }
}

bool ConditionCommand::isOpen() {
    return this->isOpenMember;
}

void ConditionCommand::open() {
    this->isOpenMember = true;
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

/**
 *
 * @return true if condition is true, o.w false.
 */
bool ConditionCommand::checkCondition() {
    // Replace vars in the input to their value
    vector<string> args;
    vector<string> result;
    Expression *leftexp;
    Expression *rightexp;
    if (condition[condition.size() - 1] == "{") {
        vector<string> arg1(condition.begin(), condition.end() - 1);
        vector<string> args = ParsingUtils::replaceExistingVars(arg1);
        result = args;
    } else {
        vector<string> arg1(condition.begin(), condition.end());
        vector<string> args = ParsingUtils::replaceExistingVars(arg1);
        result = args;
    }
    // Search for operator
    int place = seekForExpression(result);
    // Split to left & right vectors.
    vector<string> left(result.begin() + 1, result.begin() + place);
    vector<string> right(result.begin() + place + 1, result.end());
    // Verify for only one expression, and not two (like <=, ==, etc)
    int place2 = seekForExpression(right);
    if (place2 != -1) {

        vector<string> temp(right.begin() + 1, right.end());
        right = temp;

    }
    // Create left expression
    leftexp = ParsingUtils::getExpression(left, 0);
    rightexp = ParsingUtils::getExpression(right, 0);


    // check the logic expression
    if (place2 != -1) {
        string temp2 = result.at(place) + result.at(place + 1);
        return (ParsingUtils::checkExpression(leftexp, rightexp, temp2));
    }
    // check the logic expression
    return (ParsingUtils::checkExpression(leftexp, rightexp, result.at(place)));
}

/**
 *
 * @param conditionCommand a condition command we got during another condition command, therfor pushed to nested vector
 */
void ConditionCommand::addConditionCommandToNested(ConditionCommand *conditionCommand) {
    nested.push_back(conditionCommand);
    toRelease.push_back(conditionCommand);
}

/**
 *
 * @param args2 a given vector.
 * @return the place the the operator is found.
 */
int ConditionCommand::seekForExpression(vector<string> args2) {
    // We use regular for loop and not iterator because we need the number
    for (int i = 0; i < args2.size(); i++) {
        if (args2[i] == "<" || args2[i] == ">" || args2[i] == "=" || args2[i] == ">=" || args2[i] == "<=" ||
            args2[i] == "!" || args2[i] == "&&" || args2[i] == "||") {
            return i;
        }
    }
    return -1;
}

ConditionCommand::~ConditionCommand() {
    for (int i = 0; i < toRelease.size(); ++i) {
        delete toRelease[i];
    }
}