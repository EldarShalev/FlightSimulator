//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_BINARY_H
#define SIMULATOR_BINARY_H

#include "Expression.h"

class Binary : public Expression {
public:
    Expression *left;
    Expression *right;
public:
    Binary(Expression *leftv, Expression *rightv) : left(leftv), right(rightv) {}

    ~Binary() {
        delete left;
        delete right;
    }

    virtual double calculate() {};
};

#endif //SIMULATOR_BINARY_H
