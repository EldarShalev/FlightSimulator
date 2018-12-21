//
// Created by Eldar on 14-Dec-18.
//


#include "Utils.h"

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

vector<string> Utils::splitByWhitespaces(string str) {
    vector<string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, ' ')) {
        if (item.length() > 0) {
            result.push_back(trim(item));
        }
    }
    return result;
}
