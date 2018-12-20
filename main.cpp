#include <iostream>
#include <fstream>
#include "Parser.h"
#include <string>
#include "ShuntingYard.h"

using namespace std;

void inputFromCli();

void inputFromFile(char *filePath);

int main(int argc, char *argv[]) {
    // Test
    string one = " 5 + (4/2) * 5 * 4-2-3";
    string two = "( 1 + (2/3) * (4+5) -6)";
    ShuntingYard p(two);
    cout << p.infixToPostfix() << endl;
    Expression* e1= p.toExpression();
    cout << e1->calculate() << endl;
    if (argc == 2) {
        inputFromFile(argv[1]);
    } else {
        inputFromCli();
    }

    return 0;
}

void inputFromFile(char *filePath) {
    Parser parser;
    cout << "Reading script " << filePath << endl;
    ifstream inputFile(filePath);
    string line;

    while (getline(inputFile, line)) {
        vector<string> lxd = Utils::lexer(line);
        parser.parse(lxd);
    }
    inputFile.close();
    cout << "Finished executing the script, exiting program" << endl;
}

void inputFromCli() {
    Parser parser;
    cout << "Please enter a command, or enter \"exit\" to end the program" << endl;
    bool exit = false;
    while (!exit) {
        string input;
        getline(cin, input);

        if (input.compare("exit") == 0) {
            exit = true;
        } else {
            vector<string> lxd = Utils::lexer(input);
            parser.parse(lxd);
        }
    }
    cout << "Aurvua, Shoshana!" << endl;
}
