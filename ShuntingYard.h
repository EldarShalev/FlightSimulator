//
// Created by Eldar on 20-Dec-18.
//

#ifndef SIMULATOR_SHUNTINGYARD_H
#define SIMULATOR_SHUNTINGYARD_H

#include "OperationPriority.h"
#include "expressions/Minus.h"
#include "expressions/Divide.h"
#include "expressions/Plus.h"
#include "expressions/Multiply.h"
#include "expressions/Number.h"


#include <string>

using namespace std;

class ShuntingYard {

private:
    std::string m_srcFormula;
    OperationPriority m_op;
public:
    ShuntingYard(string string1);

    Expression* toExpression();

    string infixToPostfix() const;

};


#endif //SIMULATOR_SHUNTINGYARD_H
