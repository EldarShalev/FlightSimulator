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
#include "expressions/Negative.h"


#include <string>

using namespace std;

class ShuntingYard {

private:
    OperationPriority priority;
public:
    Expression *toExpression(string src);

    string infixToPostfix(string src) ;

    string parseTheInfix(string src);

    ~ShuntingYard();
};

#endif //SIMULATOR_SHUNTINGYARD_H
