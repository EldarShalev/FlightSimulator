//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_MULTIPLY_H
#define SIMULATOR_MULTIPLY_H

#include "Binary.h"

class Multiply : public Binary {
public:
    Multiply(Expression *leftv, Expression *rightv) : Binary(leftv, rightv) {}

    double calculate() { return left->calculate() * right->calculate(); }
};

#endif //SIMULATOR_MULTIPLY_H
