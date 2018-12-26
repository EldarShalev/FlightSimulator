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
        // Set with Var command
        Var::set(value);
        // Buffer for sending the set command
        char *conversion = new char[path.size() + 1024];
        sprintf(conversion, "set %s %s\r\n", path.c_str(), Utils::doubleToString(value).c_str());
        // Send the "set" command with all the relevant path and details.
        string value1 = ConnectionsManager::send(conversion);
        delete conversion;
    }

    // For get command
    double get() {
        char *conversion = new char[path.length() + 1024];
        sprintf(conversion, "get %s\r\n", path.c_str());
        // Send the command and get output from sending.
        string value2 = ConnectionsManager::send(conversion);
        try { // try to evaluate the returned value
            double dvalue = Utils::parseValueAfterGet(value2);
            cout << "Value is " << dvalue << endl;
            Var::set(dvalue);
            delete conversion;
            return dvalue;
        } catch (MyException &e1) {
            cout << "BoundedVar : " << __func__ << " : ";
            cout << e1.convertToString() << ", function: " << e1.getFunc() << ", Info: " << e1.getInfo() << endl;

        }


    }
};

#endif //SIMULATOR_BOUNDEDVAR_H
