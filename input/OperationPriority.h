//
// Created by Eldar on 20-Dec-18.
//

#ifndef SIMULATOR_OPERATIONPRIORITY_H
#define SIMULATOR_OPERATIONPRIORITY_H

#include <iostream>
#include <stack>
#include <string>
#include <map>
#include "data/MyException.h"

using namespace std;
enum Priority {
    HIGH = 2,
    MED = 1,
    LOW = 0
};

enum Brackets {
    OPEN_BRACKET = '(',
    CLOSE_BRACKET = ')'
};

class OperationPriority {

private:
    map<char, int> mapPriority;

    void init() {
        //Hight priority
        mapPriority['*'] = Priority::HIGH;
        mapPriority['/'] = Priority::HIGH;
        //Med priority
        mapPriority['+'] = Priority::MED;
        mapPriority['-'] = Priority::MED;
        //Low priority
        mapPriority['('] = Priority::LOW;
        mapPriority[')'] = Priority::LOW;
    }

public:

    OperationPriority() {
        init();
    }

    int FindPriorByOp(char op) const;
    bool isOperator(char sym) const;
};


#endif //SIMULATOR_OPERATIONPRIORITY_H
