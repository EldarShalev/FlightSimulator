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
    string nameOfVar;
public:
    BoundedVar(const string &path, string name) : path(path), nameOfVar(name) {}

    void set(double value) {
        Var::set(value);
        char *conversion = new char[path.length() + 10];
        sprintf(conversion, "set %s %s\r\n", path.c_str(), Utils::doubleToString(value).c_str());


        string value1 = ConnectionsManager::send(conversion);
        delete conversion;
    }

    double get() {
        char *conversion = new char[path.length() + 10];
        sprintf(conversion, "get %s\r\n", path.c_str());
        string value2 = ConnectionsManager::send(conversion);

        try {
            double dvalue = Utils::parseValueAfterGet(value2);
            cout << "Value is " << dvalue <<endl;
            Var::set(dvalue);
            return dvalue;
        } catch (MyException &e1) {
            cout << "BoundedVar : " << __func__ << " : ";
            cout << e1.convertToString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;

        }


    }
};

#endif //SIMULATOR_BOUNDEDVAR_H
