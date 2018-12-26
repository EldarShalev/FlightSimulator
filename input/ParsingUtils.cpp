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
    Expression *expression = getExpression(input, idx);
    vector<string> newInput;
    if (input[idx] == "=") {
        //get var name too!
        newInput.push_back(input[idx - 1]);
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
    vector<string> smellsLikeAnExpression(input.begin() + idx + 1, input.end());
    string joinedString;
    Utils::join(smellsLikeAnExpression, ' ', joinedString);
    Expression *expression = shuntingYard.toExpression(joinedString);
    return expression;
}

bool ParsingUtils::checkExpression(Expression *left, Expression *right, string logicCondition) {

    if (logicCondition == "==") {
        Equals e(left, right);
        return (e.calculate() == 1);
    } else if (logicCondition == "<") {
        LessThan e(left, right);
        return (e.calculate() == 1);
    }else if (logicCondition == ">") {
        GreaterThan e(left, right);
        return (e.calculate() == 1);
    }else if (logicCondition == "!=") {
        NotEquals e(left, right);
        return (e.calculate() == 1);
    }else if (logicCondition == "&&") {
        And e(left, right);
        return (e.calculate() == 1);
    }else if (logicCondition == "||") {
        Or e(left, right);
        return (e.calculate() == 1);
    } else if (logicCondition == "<=") {
        LessThan e(left, right);
        Equals e2(left,right);
        return (e.calculate() == 1 || e2.calculate());
    }else if (logicCondition == ">=") {
        GreaterThan e(left, right);
        Equals e2(left,right);
        return (e.calculate() == 1 || e2.calculate());
    }
}