//
// Created by Eldar on 12/20/2018.
//

#ifndef SIMULATOR_BOUNDEDVAR_H
#define SIMULATOR_BOUNDEDVAR_H

#include <string>
#include "Var.h"
#include "input/Utils.h"
#include "reader/ConnectionsManager.h"

using namespace std;

class BoundedVar : public Var {
private:
    string path;
public:
    BoundedVar(const string &path) : path(path) { }

    void set(double value) {
        Var::set(value);
        string cmd = "set " + path + " " + Utils::doubleToString(value) + "/r/n";
        ConnectionsManager::send(cmd);
    }

    double get() {
        string cmd = "get " + path + "/r/n";
        string value = ConnectionsManager::sendAndRecieve(cmd);
        double dvalue = Utils::stringToDouble(value);
        Var::set(dvalue);
        return dvalue;
    }
};

#endif //SIMULATOR_BOUNDEDVAR_H
