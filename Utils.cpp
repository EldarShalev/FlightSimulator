//
// Created by Eldar on 14-Dec-18.
//


#include "Utils.h"

/**
 *
 * @param full string
 * @param delimiter the type of char, backspace, comma etc.
 * @param index which part of the string to cut.
 * @return the specific delimited string we want.
 */
string Utils::getNextString(string full, char delimiter, int index) {
    int i = 0;
    int counter = 1;
    string stringToReturn = "";
    while (i < full.length()) {
        if (full.at(i) == delimiter) {
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
    vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());
    return results;
}


/**
 *
 * @param str a given string.
 * @return int format.
 */
double Utils::stringToDouble(string str) {
    int n = str.length();
    int i = 0;
    double res = 0;
    for (; i < n; i++) {
        char temp = str.at(i);
        if (temp > '9' || temp < '0') {
            throw MyException("no file",__func__,"Utils");
        }
        res += temp - '0';
        res *= 10;
    }
    res /= 10;
    return res;
}

int Utils::stringToInt(string str) {
    return (int)stringToDouble(str);
}