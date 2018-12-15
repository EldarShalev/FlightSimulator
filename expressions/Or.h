//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_OR_H
#define SIMULATOR_OR_H

#include "Binary.h"

class Or : Binary {
public:
    Or(Expression leftv, Expression rightv) : Binary(leftv, rightv){}
    double calculate(){ return left.calculate() || right.calculate(); }
};

#endif //SIMULATOR_OR_H
