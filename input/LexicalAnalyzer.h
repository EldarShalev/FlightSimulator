//
// Created by Eldar on 12/20/2018.
//

#ifndef SIMULATOR_LEXICALANALYZER_H
#define SIMULATOR_LEXICALANALYZER_H

#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <regex>
#include <iostream>
#include <algorithm>
#include "Utils.h"

using namespace std;

class LexicalAnalyzer {
private:
    regex keywords;
public:
    LexicalAnalyzer();

    vector<string> analyze(string str);
};

#endif //SIMULATOR_LEXICALANALYZER_H


