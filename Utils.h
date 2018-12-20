//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_UTILS_H
#define SIMULATOR_UTILS_H

#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include "commands/Command.h"
#include "MyException.h"

using namespace std;

class Utils {

public:
    static string getNextString(string full, char delimiter, int index);
    static vector<string> lexer(string str);
    static double stringToDouble(string str);
    static int stringToInt(string str);
};

#endif //SIMULATOR_UTILS_H
