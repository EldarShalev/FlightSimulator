#include <iostream>
#include <fstream>
#include "input/LexicalAnalyzer.h"
#include "input/Parser.h"

using namespace std;

void inputFromCli(LexicalAnalyzer *lexer, Parser *parser);

void inputFromFile(char *filePath, LexicalAnalyzer *lexer, Parser *parser);

int main(int argc, char *argv[]) {
    cout << "Welcome to the flight simulator!" << endl;

    LexicalAnalyzer *lexer = new LexicalAnalyzer();
    Parser *parser = new Parser();

    if (argc == 2) {
        inputFromFile(argv[1], lexer, parser);
    } else {
        inputFromCli(lexer, parser);
    }

    delete parser;
    delete lexer;
    cout << "Aurvua, Shoshana!" << endl;
    return 0;
}

void inputFromFile(char *filePath, LexicalAnalyzer *lexer, Parser *parser) {
    cout << "Reading script " << filePath << endl;
    ifstream inputFile(filePath);
    string line;

    while (getline(inputFile, line)) {
        vector<string> lxd = lexer->analyze(line);
        parser->parse(lxd);
    }
    inputFile.close();
}

void inputFromCli(LexicalAnalyzer *lexer, Parser *parser) {
    cout << "Please enter a command, or enter \"exit\" to end the program" << endl;
    bool exit = false;
    while (!exit) {
        string input;
        getline(cin, input);

        if (input.compare("exit") == 0) {
            exit = true;
        } else {
            vector<string> lxd = lexer->analyze(input);
            parser->parse(lxd);
        }
    }
}
