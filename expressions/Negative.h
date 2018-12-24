//
// Created by Eldar on 24-Dec-18.
//

#ifndef SIMULATOR_NEGATIVE_H
#define SIMULATOR_NEGATIVE_H


#include "Unary.h"

class Negative : public Unary {
public:
    Negative(Expression *mid) : Unary(mid) {}

    double calculate() { return -1 * one->calculate(); }
};

#endif //SIMULATOR_NEGATIVE_H
