//
// Created by Eldar on 19-Dec-18.
//

#ifndef SIMULATOR_MYEXCEPTION_H
#define SIMULATOR_MYEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception {

    const char* file;
    const char* func;
    const char* info;

public:
    MyException( const char* file_, const char* func_, const char* info_ = "") :
    file (file_), func (func_), info (info_) {}
    const char* convertFromString() const  throw(){
        return "Convert from string failed";
    }

    const char *getFile() const {
        return file;
    }

    const char *getFunc() const {
        return func;
    }

    const char *getInfo() const {
        return info;
    }

};


#endif //SIMULATOR_MYEXCEPTION_H
