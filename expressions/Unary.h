//
// Created by Eldar on 24-Dec-18.
//

#ifndef SIMULATOR_UNARY_H
#define SIMULATOR_UNARY_H

#include "Expression.h"


class Unary : public Expression {
public:
    Expression *one;

    Unary(Expression *mid) : one(mid) {}

    ~Unary() {
        delete one;
    }
    virtual double calculate() {};
};


#endif //SIMULATOR_UNARY_H
