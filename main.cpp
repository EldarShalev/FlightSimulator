#include <iostream>
#include "Utils.h"
int main(int argc,char* argv[]) {

    string temp;
    for (int i=1;i<argc;i++){

        temp=temp + " " + argv[i];
    }
    vector<string> temp2=Utils::lexer(temp);
    return 0;
}