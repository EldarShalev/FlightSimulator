//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_DIVIDE_H
#define SIMULATOR_DIVIDE_H

#include "Binary.h"

class Divide : Binary {
public:
    Divide(Expression leftv, Expression rightv) : Binary(leftv, rightv){}
    double calculate(){ return left.calculate() / right.calculate(); }
};

#endif //SIMULATOR_DIVIDE_H
