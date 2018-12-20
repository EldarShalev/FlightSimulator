//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_PLUS_H
#define SIMULATOR_PLUS_H

#include "Binary.h"

class Plus : public Binary {
public:
    Plus(Expression *leftv, Expression *rightv) : Binary(leftv, rightv) {}

    double calculate() { return left->calculate() + right->calculate(); }
};

#endif //SIMULATOR_PLUS_H
