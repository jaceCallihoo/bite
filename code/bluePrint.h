#pragma once

#include "line.h"

#include <string>
#include <vector>

#define byte unsigned char

using namespace std;



struct prototype
{

    struct argDef {
        vector<bool> argType;
        string func;
    };

    string name;
    vector<argDef> argDefs;
};

enum argType { NUM, REG };

class BluePrint {
private:

    vector<prototype> BPlist = {


        {"ADD", {{{REG, REG, REG}, "add1"}, {{REG, REG, NUM}, "add2"}}},
        {"AND", {{{REG, REG, REG}, "and1"}, {{REG, REG, NUM}, "and2"}}},
        {"OR",  {{{REG, REG, REG}, "or1"},  {{REG, REG, NUM}, "or2"}}},
        {"BEQ", {{{REG, REG, REG}, "beq1"}, {{REG, REG, NUM}, "beq2"}, {{REG, NUM, REG}, "beq3"}, {{REG, NUM, NUM}, "beq4"}}},
        {"J",   {{{REG}, "jump1"}, {{NUM}, "jump2"}}},
        {"MOV", {{{REG, REG}, "move1"}, {{REG, NUM}, "move2"}}},
        {"SL", {{{REG, REG, REG}, "shiftLeft1"}, {{REG, REG, NUM}, "shiftLeft2"}}},
        {"SR", {{{REG, REG, REG}, "shiftRight1"}, {{REG, REG, NUM}, "shiftRight2"}}},
        {"LB", {{{REG, REG}, "load1"}, {{REG, NUM}, "load2"}}},
        {"SB", {{{REG, REG}, "store1"}, {{REG, NUM}, "store2"}}},

    };


public:
    Line tokenArrayToLine(vector<string> line);
    bool argTypeMatch(vector<bool> AT, vector<string> args);
    bool argType(string arg);
    byte argToNum(string arg);
};
