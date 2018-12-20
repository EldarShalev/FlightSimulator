#include <iostream>
#include <fstream>
#include "Parser.h"
#include <string>
using namespace std;

int main(int argc,char* argv[]) {
    CommandsMap* map1 = new CommandsMap();
    if (argc==2){
        ifstream myfile;
        string line;
        myfile.open(argv[2]);
        while (!myfile.eof()){
            // todo
            // send each line to lexer and parser
        }
        myfile.close();
    }
    string temp;
    for (int i=1;i<argc;i++){

        temp=temp + " " + argv[i];
    }
    vector<string> temp2=Utils::lexer(temp);
    Parser::parser(temp2, map1);
    return 0;
}