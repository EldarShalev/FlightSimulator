//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_UTILS_H
#define SIMULATOR_UTILS_H

#include <string>
#include <vector>
#include <iterator>
#include <sstream>
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
    static void buildPathFromVector(vector<string> input, string &output);
    static double parseValueAfterGet(string parse);
    static vector<string> split(string str, char delimiter);
    static string split2(string str, char delimiter);

};

#endif //SIMULATOR_UTILS_H
