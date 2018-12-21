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
    BoundedVar(const string &path) : path(path) { }

    void set(double value) {
        Var::set(value);
        //TODO - update value in server too
    }

    double get() {
        //TODO: get value from server
        return 0;
    }
};

#endif //SIMULATOR_BOUNDEDVAR_H
