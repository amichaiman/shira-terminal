//
// Created by amichai on 27/06/18.
//

#include "Terminal.h"

void Terminal::touch(const string &fileName) {
    File *file = getFile(fileName);

    if (file){
        file->touch();
    }else {
        files.push_back(new File(fileName));
    }
}

void Terminal::ls() {
    for (vector<File*>::iterator i=files.begin(); i !=files.end();i++ ){
        cout << (*i)->getName() << endl;
    }
}

void Terminal::copy(const string &source, const string &destination) {
    File *sourceFile = getFile(source);

    if (sourceFile == NULL){
        throw noSuchFileException();
    }
    File *destinationFile = sourceFile->clone();

    destinationFile->setName(destination);

    files.push_back(destinationFile);

}

File *Terminal::getFile(const string &fileName) {
    for (vector<File*>::iterator i=files.begin(); i !=files.end();i++ ){
        if ((*i)->getName() == fileName){
            return (*i);
        }
    }
    return NULL;
}

void Terminal::remove(const string &fileName) {
    for (vector<File*>::iterator i=files.begin(); i !=files.end();i++ ){
        if ((*i)->getName() == fileName){
            delete(*i);
            files.erase(i);
            return;
        }
    }

}

void Terminal::move(const string &source,const string &destination) {
    File *sourceFile = getFile(source);

    if (sourceFile == NULL){
        throw noSuchFileException();
    }

    copy(source,destination);
    remove(source);
}

void Terminal::write(const string &fileName, const int pos, const char c) {
    File *file = getFile(fileName);

    if (file == NULL){
        throw noSuchFileException();
    }

    (*file).operator[](pair<int,char>(pos,c));
}

void Terminal::read(const string &fileName, const int pos) {
    File *file = getFile(fileName);

    if (file == NULL){
        throw noSuchFileException();
    }

    cout << (*file).operator[](pos) << endl;
}


