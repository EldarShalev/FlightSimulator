//
// Created by Eldar on 14-Dec-18.
//


#include "Utils.h"

string Utils::getNextString(string full, char trim, int index) {
    int i = 0;
    int counter = 1;
    string stringToReturn = "";
    while (i < full.length()) {
        if (full.at(i) == trim) {
            if (counter == index) {
                return stringToReturn;
            }
            counter++;
            stringToReturn = "";
        } else {
            stringToReturn.push_back(full.at(i));
        }
        i++;
    }
}

/**
 *
 * @param str whole line of command.
 * @return vector of strings, each declares a word.
 */
vector<string> Utils::lexer(string str) {
    istringstream iss(str);
    vector<string> results(istream_iterator<string>{iss},
                           istream_iterator<string>());
    return results;
}
