//
// Created by Eldar on 14-Dec-18.
//
#include "OpenServerCommand.h"

/**
 * Opening server command.
 * validation of two correct arguments - port and times per second.
 */
void OpenServerCommand::doCommand(string str) {
    string port = Utils::getNextString(str,' ',1);
    string times = Utils::getNextString(str,' ',2);

}

/**
 *
 * @param str a given string.
 * @return int format.
 */
int OpenServerCommand::stringToInt(string str) {
    int n = str.length();
    int i = 0;
    int res = 0;
    for (; i < n; i++) {
        char temp = str.at(i);
        if (temp > '9' || temp < '0') {
            throw "unsupported date format";
        }
        res += temp - '0';
        res *= 10;
    }
    res /= 10;
    return res;
}