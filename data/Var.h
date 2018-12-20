//
// Created by Eldar on 12/20/2018.
//

#ifndef SIMULATOR_VAR_H
#define SIMULATOR_VAR_H


class Var {
private:
    double value;
public:
    Var(double value) : value(value) {}

    virtual double get() { return value; }

    virtual void set(double value) { this->value = value; }
};


#endif //SIMULATOR_VAR_H
