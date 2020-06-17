#pragma once

#include "program.h"
#include "bluePrint.h"

#include <vector>
#include <string>

class Programizer
{
private:

public:
    Program programize(vector<vector<string>> tokens);
    vector<vector<string>> removeComments(vector<vector<string>> tokens);
    vector<vector<string>> addressToNum(vector<vector<string>> tokens);
    Program tokenToProgram(vector<vector<string>> tokens);
};
