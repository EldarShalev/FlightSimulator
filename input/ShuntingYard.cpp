//
// Created by Eldar on 20-Dec-18.
//

#include "ShuntingYard.h"

Expression *ShuntingYard::toExpression(string src) {
    string postfixFormat = infixToPostfix(src);
    stack<Expression *> st;
    string tmpBuf;
    for (auto curSym = postfixFormat.begin(); curSym != postfixFormat.end(); ++curSym) {
        if (isdigit(*curSym)) {
            tmpBuf += *curSym;
        } else {
            if (!tmpBuf.empty()) {
                st.push(new Number(std::stoi(tmpBuf)));
            }
            tmpBuf.clear();
        }

        if (!st.empty() && m_op.isOperator(*curSym) && st.size() >= 2) {
            Expression *res;

            Expression *rightOp = st.top(); // Last value from stack
            st.pop();
            Expression *leftOp = st.top();
            st.pop();

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
        // If current symbol is digit
        if (std::isdigit(*curSym)) {
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
        else if (m_op.isOperator(*curSym) && stackOp.empty()) {
            stackOp.push(*curSym);
            strOut += std::string(" ");

        }
            // If current symbol is operator and stack is not empty
        else if (m_op.isOperator(*curSym) && !stackOp.empty()) {
            int topOpPrior = m_op.FindPriorByOp(stackOp.top()); //Priority of operator of TOP stack
            int curOpPrior = m_op.FindPriorByOp(*curSym); //Priority of operator of current symbol

            while ((topOpPrior >= curOpPrior) && !stackOp.empty()) {
                strOut += stackOp.top();
                stackOp.pop();

                if (!stackOp.empty())
                    topOpPrior = m_op.FindPriorByOp(stackOp.top());
                else
                    continue;

                curOpPrior = m_op.FindPriorByOp(*curSym);
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
    string temp2 = "";
    for (std::string::size_type i = 0; i < src.size(); ++i) {
        if (src[i] != ' ') {
            temp2 += src[i];
        }
    }
    for (std::string::size_type i = 0; i < temp2.size() - 1; ++i) {
        if (temp2[i] == '-' && temp2[i + 1] == '-') {
            string temp = temp2.substr(0, i);
            temp += "+";
            temp += temp2.substr(i + 2, temp2.size());
            temp2 = temp;
        }
    }
    return temp2;
}