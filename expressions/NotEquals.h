//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_NOT_H
#define SIMULATOR_NOT_H

#include "Binary.h"

class NotEquals : public Binary {
public:
    NotEquals(Expression *leftv, Expression *rightv) : Binary(leftv, rightv) {}

    double calculate() { return left->calculate() != right->calculate(); }
};

#endif //SIMULATOR_NOT_H
