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
 * @param str a given string
 * @return double
 */
double Utils::stringToDouble(string str) {
    return stod(str);
}

/**
 *
 * @param str a given string
 * @return int
 */
int Utils::stringToInt(string str) {
    return stoi(str);
}

string Utils::trim(const string str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

string Utils::doubleToString(double number) {
    ostringstream strs;
    strs << number;
    return strs.str();
}

void Utils::join(vector<string> input, char delimiter, string &output) {
    output.clear();

    for (vector<string>::const_iterator p = input.begin();
         p != input.end(); ++p) {
        output += *p;
        if (p != input.end() - 1)
            output += delimiter;
    }
}