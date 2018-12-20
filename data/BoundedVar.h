//
// Created by Eldar on 12/20/2018.
//

#ifndef SIMULATOR_BOUNDEDVAR_H
#define SIMULATOR_BOUNDEDVAR_H

#include <string>
#include "Var.h"

using namespace std;

class BoundedVar : public Var {
private:
    string path;
public:
    BoundedVar(double value, const string &path) : Var(value), path(path) {}

    void set(double value) {
        Var::set(value);
        //TODO - updated path in server too
    }
};

#endif //SIMULATOR_BOUNDEDVAR_H
