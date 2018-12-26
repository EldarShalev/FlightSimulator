//
// Created by Eldar on 24-Dec-18.
//

#include "ParsingUtils.h"

// Decleration
VarMap ParsingUtils::varMap;
ShuntingYard ParsingUtils::shuntingYard;


/**
 *
 * @param input a given vector.
 * @return same vector after replacing each var with it's value.
 */
vector<string> ParsingUtils::replaceExistingVars(vector<string> input) {
    // Third step - replace all existing vars with their values, unless its the first argument - then its an assignment and we don't need to replace it, so we are skipping it
    for (int i = 1; i < input.size(); ++i) {
        if (varMap.isVarExists(input[i])) {
            Var *temp = varMap.getVar(input[i]);
            input[i] = Utils::doubleToString(temp->get());
        }
    }
    return input;
}

/**
 *
 * @param input a given input.
 * @param idx id.
 * @return caclculate of the parsed input.
 */
vector<string> ParsingUtils::createParsedInput(vector<string> &input, int idx) {
    // Create parsed of given input
    Expression *expression = getExpression(input, idx);
    vector<string> newInput;
    if (input[idx-1] == "=") {
        //get var name too!
        newInput.push_back(input[idx - 2]);
    }
    newInput.push_back(input[idx]);
    newInput.push_back(Utils::doubleToString(expression->calculate()));
    delete expression;
    return newInput;
}


/**
 *
 * @param input a given input.
 * @param idx given id.
 * @return Expression with SuntingYard Algorithm.
 */
Expression *ParsingUtils::getExpression(vector<string> &input, int idx) {
    // Get expression of given vector
    vector<string> smellsLikeAnExpression(input.begin() + idx, input.end());
    string joinedString;
    Utils::join(smellsLikeAnExpression, ' ', joinedString);
    Expression *expression = shuntingYard.toExpression(joinedString);
    return expression;
}

bool ParsingUtils::checkExpression(Expression *left, Expression *right, string logicCondition) {

    // Check all logic condition
    if (logicCondition == "==") {
        Equals *e = new Equals(left, right);
        bool flg = (e->calculate() == 1);
        delete e;
        return flg;
    } else if (logicCondition == "<") {
        LessThan *e = new LessThan(left, right);
        bool flg = (e->calculate() == 1);
        delete e;
        return flg;
    } else if (logicCondition == ">") {
        GreaterThan *e = new GreaterThan(left, right);
        bool flg = (e->calculate() == 1);
        delete e;
        return flg;
    } else if (logicCondition == "!=") {
        NotEquals *e = new NotEquals(left, right);
        bool flg = (e->calculate() == 1);
        delete e;
        return flg;
    } else if (logicCondition == "&&") {
        And *e = new And(left, right);
        bool flg = (e->calculate() == 1);
        delete e;
        return flg;
    } else if (logicCondition == "||") {
        Or *e = new Or(left, right);
        bool flg = (e->calculate() == 1);
        delete e;
        return flg;
    } else if (logicCondition == "<=") {
        LessThan *e = new LessThan(left, right);
        Equals *e2 = new Equals(left, right);
        bool flg = (e->calculate() == 1 || e2->calculate() == 1);
        delete e;
        return flg;
    } else if (logicCondition == ">=") {
        GreaterThan *e = new GreaterThan(left, right);
        Equals *e2 = new Equals(left, right);
        bool flg = (e->calculate() == 1 || e2->calculate() == 1);
        delete e;
        return flg;
    }
}