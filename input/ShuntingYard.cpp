//
// Created by Eldar on 20-Dec-18.
//

#include "ShuntingYard.h"

Expression *ShuntingYard::toExpression(string src) {
    // Get the postifx format
    string postfixFormat = infixToPostfix(src);
    stack<Expression *> st;
    string tmpBuf;

    if (src.length() == 1 || src.length()==2) {
        if (src[0] == 'u') {
            string temp(src.substr(1,src.length()));
            st.push(new Negative(new Number(stod(temp))));
        } else {
            st.push(new Number((stod(src))));
        }
    }

    for (auto curSym = postfixFormat.begin(); curSym != postfixFormat.end(); ++curSym) {
        if (isdigit(*curSym) || *curSym == '.') {
            tmpBuf += *curSym;
        } else {
            if (!tmpBuf.empty()) {
                st.push(new Number(std::stoi(tmpBuf)));
            }
            tmpBuf.clear();
        }

        if (!st.empty() && *curSym == 'u') {
            Expression *res;
            Expression *mid = st.top();
            st.pop();
            res = new Negative(mid);
            st.push(res);
            // If we have an operator and the stack is at least with 2 elements
        } else if (!st.empty() && priority.isOperator(*curSym) && st.size() >= 2) {
            Expression *res;
            Expression *rightOp = st.top(); // Last value from stack
            st.pop();
            Expression *leftOp = st.top();
            st.pop();
            // Create expression according to the operator we drop
            switch (*curSym) {
                case '*':
                    res = new Multiply(leftOp, rightOp);
                    break;
                case '/':
                    res = new Divide(leftOp, rightOp);
                    break;
                case '+':
                    res = new Plus(leftOp, rightOp);
                    break;
                case '-':
                    res = new Minus(leftOp, rightOp);
                    break;
            }
            st.push(res);
        }
    }
    return st.top();
}

string ShuntingYard::infixToPostfix(string src) {
    std::string parsedSrc = parseTheInfix(src);
    string strOut = "";
    std::stack<char> stackOp;

    for (auto curSym = parsedSrc.begin(); curSym != parsedSrc.end(); ++curSym) {
        if (*curSym == ' ') {
            continue;
        }
        // If current symbol is digit or dot (for float and double)
        if (std::isdigit(*curSym) || (*curSym == '.')) {
            strOut += *(curSym);
        }
            // If current symbol is open bracket
        else if (*curSym == Brackets::OPEN_BRACKET) {
            stackOp.push(*curSym);
        }
            // If current symbol is close bracket
        else if (*curSym == Brackets::CLOSE_BRACKET) {
            while (stackOp.top() != Brackets::OPEN_BRACKET) {
                if (!stackOp.empty()) {
                    strOut += stackOp.top();
                    stackOp.pop();
                } else
                    throw std::invalid_argument("Incorrect expression!");
            }
            stackOp.pop(); // Remove open bracket
        }
            // If current symbol is operator and stack is empty
        else if (priority.isOperator(*curSym) && stackOp.empty()) {
            stackOp.push(*curSym);
            strOut += std::string(" ");

        }
            // If current symbol is operator and stack is not empty
        else if (priority.isOperator(*curSym) && !stackOp.empty()) {
            int topOpPrior = priority.FindPriorByOp(stackOp.top()); //Priority of operator of TOP stack
            int curOpPrior = priority.FindPriorByOp(*curSym); //Priority of operator of current symbol

            while ((topOpPrior >= curOpPrior) && !stackOp.empty()) {
                strOut += stackOp.top();
                stackOp.pop();

                if (!stackOp.empty())
                    topOpPrior = priority.FindPriorByOp(stackOp.top());
                else
                    continue;

                curOpPrior = priority.FindPriorByOp(*curSym);
            }
            stackOp.push(*curSym);
            strOut += std::string(" ");
        }
    }
    //Add to string remaining in stack operators
    while (!stackOp.empty()) {
        strOut += stackOp.top();
        stackOp.pop();
    }
    return strOut;
}

string ShuntingYard::parseTheInfix(string src) {
    if (src[0] == '-') {
        src[0] = 'u';
    }
    string temp2 = "";
    for (std::string::size_type i = 0; i < src.size(); ++i) {
        if (src[i] != ' ') {
            temp2 += src[i];
        }
    }
    if (src.length() > 2) {
        for (std::string::size_type i = 0; i < temp2.size() - 1; ++i) {
            if (temp2[i] == '-' && temp2[i + 1] == '-') {
                string temp = temp2.substr(0, i);
                temp += "+";
                temp += temp2.substr(i + 2, temp2.size());
                temp2 = temp;
            }
        }

        for (std::string::size_type i = 0; i < temp2.size() - 1; ++i) {
            if (temp2[i] == '(' && temp2[i + 1] == '-') {
                temp2[i + 1] = 'u';
                continue;
            }
            if (temp2[i] == '-' && !isdigit(temp2[i - 1]) && temp2[i - 1] != '(' && temp2[i - 1] != ')') {
                temp2[i] = 'u';
            }
        }
    }
    return temp2;
}