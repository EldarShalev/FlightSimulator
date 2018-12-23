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
    // TODO for debug purpose, need to delete
    if (str == "") {
        return 0;
    }
    try {
        return stod(str);
    } catch (exception exception1) {
        throw MyException("no file", __func__, "Utils");
    }
}

/**
 *
 * @param str a given string
 * @return int
 */
int Utils::stringToInt(string str) {
    try {
        int toint = stoi(str);
        return toint;
    } catch (exception exception1) {
        throw MyException("no file", __func__, "Utils");
    }
}

string Utils::trim(const string str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
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

void Utils::buildPathFromVector(vector<string> input, string &output) {
    output.clear();
    for (vector<string>::const_iterator p = input.begin();
         p != input.end(); ++p) {
        output += *p;
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

vector<string> Utils::split(string str, char delimiter) {
    vector<string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        if (item.length() > 0) {
            result.push_back(trim(item));
        }
    }
    return result;
}


double Utils::parseValueAfterGet(string parse) {
    vector<string> value = Utils::split(parse, '\'');
    return stringToDouble(value.at(1));
}