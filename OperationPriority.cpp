//
// Created by Eldar on 20-Dec-18.
//

#include "OperationPriority.h"

int OperationPriority::FindPriorByOp(char op) const {
    int prior;
    auto find = mapPriority.find(op);
    if (find != mapPriority.end())
    {
        prior = find->second;
        return prior;
    }
    else
        throw MyException("no file",__func__,"OperationPriority");
}

bool OperationPriority::isOperator(char sym) const {
    bool isFound = false;
    auto find = mapPriority.find(sym);
    if (find != mapPriority.end())
    {
        isFound = true;
        return isFound;
    }
    return isFound;
}