#include "bluePrint.h"

#include <iostream>

#define byte unsigned char



Line BluePrint::tokenArrayToLine(vector<string> line) {


    cout << "-Token array to line:";
    for (int i = 0; i < line.size(); i++) { cout << " " << line[i];} cout << endl;

    // if it's an empty line or a line with just a comment: skip it
    if (line.size() == 0 || (line[0][0] == '/' && line[0][1] == '/')) {
        return {"", 0, 0, 0};
    }

    cout << "-Fonud that line is not empty or a comment line" << endl;

    for (prototype BP : BPlist) {
        // if the argument name matches the name of an instruction
        if (line[0].compare(BP.name) == 0) {
            // if the arguments match
            for (prototype::argDef D : BP.argDefs) {
                if (argTypeMatch(D.argType, line)) {

                    cout << "Found matching Blueprint: " << D.func << endl;
                    //cout << "Matching arguments are: " << argToNum(line[1]) << ", " << argToNum(line[2]) << ", " << argToNum(line[3]);

                    // return the line as a Line object

                    Line L;
                    L.name = D.func;
                    for (size_t i = 0; i < D.argType.size(); i++) {
                        L.arg[i] = argToNum(line[i+1]);
                    }

                    return L;

                }
            }

            // print argument unrecognized error 
            cout << "unknown argument array:";
            for (size_t i = 1; i < line.size(); i++) {
                cout << " " << line[i];
            }
            cout << endl;
            exit(1);
        }
    }

    // print name unrecognized error
    cout << "unknown token \"" << line[0] << "\"" << endl;
    exit(1);
    
}

// note: remember to clear input of comment tokens to make sure this works
// and also validate tokens in programizer class
bool BluePrint::argTypeMatch(vector<bool> AT, vector<string> args) {
    
    if (args.size()-1 != AT.size())
        return false; 

    for (size_t i = 1; i < AT.size()+1; i++) {
        if (argType(args[i]) != AT[i-1])
            return false;
    }

    return true;
}

bool BluePrint::argType(string arg) {
    if (arg[0] == '$')
        return true;
    else 
        return false;
}


// helps turn strings into integers
size_t strtoi(string s) {

    size_t ret = 0;

    for (size_t i = 0; i < s.size(); i++) {

        ret *= 10;

        // if a character is not a number
        if (s[i] < 48 || s[i] > 57)
            return SIZE_MAX;
        else
            ret += s[i] - 48;
   } 

   return ret;
}


byte BluePrint::argToNum(string arg) {

    cout << "agrToNum: " << arg << endl;

    if (argType(arg) == REG) {
        return strtoi(arg.substr(1));
    } else {
        return strtoi(arg);
    }
}
