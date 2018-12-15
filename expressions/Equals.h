//
// Created by Eldar on 12/15/2018.
//

#ifndef FLIGHTSIMULATOR_EQUALS_H
#define FLIGHTSIMULATOR_EQUALS_H

#include "Binary.h"

class Equals : Binary {
public:
    Equals(Expression leftv, Expression rightv) : Binary(leftv, rightv){}
    double calculate(){ return left.calculate() == right.calculate(); }
};
#endif //FLIGHTSIMULATOR_EQUALS_H
