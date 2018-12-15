//
// Created by Eldar on 14-Dec-18.
//

#ifndef SIMULATOR_UTILS_H

#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>
#include "commands/Command.h"
#define SIMULATOR_UTILS_H
using namespace std;

class Utils {

private:
    map <string,Command> map1;
public:
    static string getNextString(string full, char trim, int index);
    static vector<string> lexer(string str);

};


#endif //SIMULATOR_UTILS_H
