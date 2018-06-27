#include <climits>
#include "mainFunctions.h"
#include "Terminal.h"

queries getQuery(string s);

void getUserQueries(Terminal *terminal) {
    string input;
    cout << "Enter command: ";
    cin >> input;

        while (getQuery(input) != exit) {
            try {
                switch (getQuery(input)) {
                    case read:{
                        string fileName;
                        int location;

                        cin >> fileName >> location;
                        if (cin.fail()){
                            throw invalidReadQueryException();
                        }

                        terminal->read(fileName,location);
                    } break;
                    case write:{
                        string fileName;
                        int location;
                        char c;

                        cin >> fileName >> location >> c;

                        if (cin.fail()){
                            throw invalidWriteQueryException();
                        }

                        terminal->write(fileName,location,c);
                    } break;
                    case touch: {
                        string fileName;
                        cin >> fileName;   /*  file name   */
                        terminal->touch(fileName);
                    }
                        break;
                    case cp: {
                        string source;
                        string destination;
                        cin >> source >> destination;
                        terminal->copy(source, destination);
                    } break;
                    case rm:{
                        string fileName;
                        cin >> fileName;

                        terminal->remove(fileName);
                    } break;
                    case move:{
                        string source;
                        string destination;
                        cin >> source >> destination;

                        terminal->move(source, destination);
                    } break;
                    case cat:
                        break;
                    case head:
                        break;
                    case tail:
                        break;
                    case ls:
                        terminal->ls();
                        break;
                    case exit:
                        break;
                    default:
                        cerr << "ERROR: command is not supported" << endl;
                }
            } catch (exception &e){
                cerr << e.what() << endl;
            }
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "Enter command: ";
            cin >> input;
        }

}

queries getQuery(string s) {
    if (s == "read") return read;
    if (s == "write") return write;
    if (s == "touch") return touch;
    if (s == "copy") return cp;
    if (s == "remove") return rm;
    if (s == "move") return move;
    if (s == "cat") return cat;
    if (s == "head") return head;
    if (s == "tail") return tail;
    if (s == "ls") return ls;
    if (s == "exit") return exit;
    return invalidQuery;
}
