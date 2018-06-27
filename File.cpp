//
// Created by amichai on 27/06/18.
//

#include <iostream>
#include "File.h"

const string &File::getName() const {
    return name;
}

void File::setName(const string &name) {
    File::name = name;
}

void File::touch() {

}

File::File(string name) {
    this->name = name;

    outputStream.open(name.c_str(),ios_base::out);
    inputStream.open(name.c_str(),ios_base::in);

    if (!inputStream.is_open()){
        throw errorOpeningFileException();
    }
    if (!outputStream.is_open()){
        throw errorOpeningFileException();
    }
}

File *File::clone() {
    File *copy = new File(name);
    /*
     *
     * TODO: add other stuff
     *
     *
     * */
    return copy;
}

void File::operator[](pair<int, char> p) {
    outputStream.seekp(p.first);
    outputStream << p.second;
    outputStream.flush();

    outputStream.seekp(0);
}

const char File::operator[](int pos){
    char c;

    inputStream.seekg(pos);
    inputStream.get(c);

    return c;
}