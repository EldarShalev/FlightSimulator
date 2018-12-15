//
// Created by Eldar on 12/15/2018.
//

#ifndef SIMULATOR_NUMBER_H
#define SIMULATOR_NUMBER_H

#include "Expression.h"

class Number : Expression {
private:
    double number;
public:
    Number(double value) : number(value) {}
    double calculate(){ return number;}
};


#endif //SIMULATOR_NUMBER_H
