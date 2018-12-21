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
#include "data/MyException.h"

using namespace std;

class Utils {

public:
    static double stringToDouble(string str);
    static int stringToInt(string str);
    static string trim(const string str);
    static string doubleToString(double number);
    static void join(vector<string> input, char delimiter, string &output);
    static vector<string> splitByWhitespaces(string str);
};

#endif //SIMULATOR_UTILS_H
