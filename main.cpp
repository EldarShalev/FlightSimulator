#include <iostream>
#include <fstream>
#include "input/LexicalAnalyzer.h"
#include "input/Parser.h"

using namespace std;

void inputFromCli();

void inputFromFile(char *filePath);

int main(int argc, char *argv[]) {
    cout << "Welcome to the flight simulator!" << endl;

    if (argc == 2) {
        inputFromFile(argv[1]);
    } else {
        inputFromCli();
    }

    cout << "Aurvua, Shoshana!" << endl;
    // TODO - thread is still running, need to close when main is finish
    return 0;
}

void inputFromFile(char *filePath) {
    LexicalAnalyzer lexer;
    Parser parser;
    cout << "Reading script " << filePath << endl;
    ifstream inputFile(filePath);
    string line;

    while (getline(inputFile, line)) {
        vector<string> lxd = lexer.analyze(line);
        parser.parse(lxd);
    }
    inputFile.close();
}

void inputFromCli() {
    LexicalAnalyzer lexer;
    Parser parser;
    cout << "Please enter a command, or enter \"exit\" to end the program" << endl;
    bool exit = false;
    while (!exit) {
        string input;
        getline(cin, input);

        if (input.compare("exit") == 0) {
            exit = true;
        } else {
            vector<string> lxd = lexer.analyze(input);
            parser.parse(lxd);
        }
    }

}
