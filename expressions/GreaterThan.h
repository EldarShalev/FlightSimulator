//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_GREATERTHAN_H
#define SIMULATOR_GREATERTHAN_H

#include "Binary.h"

class GreaterThan : Binary {
public:
    GreaterThan(Expression* leftv, Expression* rightv) : Binary(leftv, rightv){}
    double calculate(){ return left->calculate() > right->calculate(); }
};

#endif //SIMULATOR_GREATERTHAN_H
