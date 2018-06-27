//
// Created by amichai on 27/06/18.
//

#ifndef SHIRA_TERMINAL_TERMIANL_H
#define SHIRA_TERMINAL_TERMIANL_H
#include <vector>
#include <string>
#include "File.h"
#include <iostream>
using namespace std;

class Terminal {
public:
    void touch(const string & fileName);
    void ls();

    void copy(const string &source, const string &destination);
    void move(const string &source, const string &destination);
    File* getFile(const string & fileName);
    void remove(const string & fileName);

    void write(const string& fileName, const int pos, const char c);
    void read(const string& fileName, const int pos);

    struct noSuchFileException : public exception {
        virtual const char * what() const throw(){
            return "ERROR: no such file";
        }
    };
private:
    vector<File*> files;
};


#endif //SHIRA_TERMINAL_TERMIANL_H
