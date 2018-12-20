//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_AND_H
#define SIMULATOR_AND_H

#include "Binary.h"

class And : public Binary {
public:

    And(Expression *leftv, Expression *rightv) : Binary(leftv, rightv) {}

    double calculate() { return left->calculate() && right->calculate(); }
};

#endif //SIMULATOR_AND_H