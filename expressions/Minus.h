//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_MINUS_H
#define SIMULATOR_MINUS_H

#include "Binary.h"

class Minus : public Binary {
public:
    Minus(Expression *leftv, Expression *rightv) : Binary(leftv, rightv) {}

    double calculate() { return left->calculate() - right->calculate(); }
};

#endif //SIMULATOR_MINUS_H
