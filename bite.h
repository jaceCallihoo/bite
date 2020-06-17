#pragma once

#include "tokenizer.h"
#include "programizer.h"
#include "program.h"

#include <string>

using namespace std;

class Bite {
private:
    
    Program program;

public:

    Bite();
    Bite(string fileName);
    bool execute();
    void print();
    // State getState();
};