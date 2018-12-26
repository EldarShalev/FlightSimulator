//
// Created by Eldar on 24-Dec-18.
//

#ifndef SIMULATOR_PARSINGUTILS_H
#define SIMULATOR_PARSINGUTILS_H

#include "maps/VarMap.h"
#include "ShuntingYard.h"

#include "Or.h"
#include "LessThan.h"
#include "And.h"
#include "GreaterThan.h"
#include "NotEquals.h"
#include "Equals.h"


class ParsingUtils {

public:
    static VarMap varMap;
    static ShuntingYard shuntingYard;

    static vector<string> replaceExistingVars(vector<string> input);

    static vector<string> createParsedInput(vector<string> &input, int idx);

    static Expression *getExpression(vector<string> &input, int idx);

    static bool checkExpression(Expression *left, Expression *right, string logicCondition);

    static void release();

    static bool calculateExpression(Expression *e);
};


#endif //SIMULATOR_PARSINGUTILS_H
