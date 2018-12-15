//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_LESSTHAN_H
#define SIMULATOR_LESSTHAN_H

#include "Binary.h"

class LessThan : Binary {
public:
    LessThan(Expression leftv, Expression rightv) : Binary(leftv, rightv){}
    double calculate(){ return left.calculate() < right.calculate(); }
};

#endif //SIMULATOR_LESSTHAN_H
