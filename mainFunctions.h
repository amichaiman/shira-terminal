//
// Created by amichai on 27/06/18.
//

#ifndef SHIRA_TERMINAL_MAINFUNCTIONS_H
#define SHIRA_TERMINAL_MAINFUNCTIONS_H

#include <iostream>
#include "Terminal.h"

using namespace std;

enum queries{
    read,
    write,
    touch,
    cp,
    rm,
    move,
    cat,
    head,
    tail,
    ls,
    exit,
    invalidQuery
};


void getUserQueries(Terminal *pTerminal);

struct invalidWriteQueryException : public exception {
    virtual const char * what() const throw(){
        return "ERROR: USAGE write <file name> <location> <character>";
    }
};

struct invalidReadQueryException : public exception {
    virtual const char * what() const throw(){
        return "ERROR: USAGE read <file name> <location>";
    }
};


#endif //SHIRA_TERMINAL_MAINFUNCTIONS_H
