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
    } else {
        commands.push_back(cmd);
        args.push_back(args1);
    }
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
    if (condtion[condtion.size() - 1] == "{") {
        vector<string> arg1(condtion.begin(), condtion.end() - 1);
        vector<string> args = ParsingUtils::replaceExistingVars(arg1);
        result = args;
    } else {
        vector<string> arg1(condtion.begin(), condtion.end());
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
    if (left.size() == 1) {
        if (left.at(0)[0] == '-') {
            leftexp = (new Negative(new Number(stod(left.at(0)))));
        } else
            leftexp = new Number(stod(left.at(0)));
    } else {
        leftexp = ParsingUtils::getExpression(left, 0);
    }

    // Create right expression
    if (right.size() == 1) {
        if (right.at(0)[0] == '-') {
            rightexp = (new Negative(new Number(stod(right.at(0)))));
        } else
            rightexp = new Number(stod(right.at(0)));
    } else {
        rightexp = ParsingUtils::getExpression(right, 0);
    }
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
}

/**
 *
 * @param args2 a given vector.
 * @return the place the the operator is found.
 */
int ConditionCommand::seekForExpression(vector<string> args2) {
    // We use regulat for loop and not iterator because we need the number
    for (int i = 0; i < args2.size(); i++) {
        if (args2[i] == "<" || args2[i] == ">" || args2[i] == "=" || args2[i] == ">=" || args2[i] == "<=" ||
            args2[i] == "!" || args2[i] == "&&" || args2[i] == "||") {
            return i;
        }
    }
    return -1;
}