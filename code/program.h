#pragma once

#include "line.h"

#include <vector>

#define byte unsigned char

class Program {
private:

    byte pc;			// program counter
    byte sp;			// stack pointer    
    byte reg[8];		// registers
    char stack[256];	// stack
    char mem[256];   	// memory

    vector<Line> instruction;
    vector<vector<string>> printInstructions;

public:
    Program();
    bool execute();
    void addLine(Line line);
    void addPrintTokens(vector<vector<string>> printTokens);
    void print();
    void setPrintItters(int &start, int &end);



    // bite instructions
    void add1(byte a0, byte a1, byte a2);
    void add2(byte a0, byte a1, byte a2);
    void and1(byte a0, byte a1, byte a2);
    void and2(byte a0, byte a1, byte a2);
    void or1(byte a0, byte a1, byte a2);
    void or2(byte a0, byte a1, byte a2);
    void beq1(byte a0, byte a1, byte a2);
    void beq2(byte a0, byte a1, byte a2);
    void beq3(byte a0, byte a1, byte a2);
    void beq4(byte a0, byte a1, byte a2);
    void jump1(byte a0, byte a1, byte a2);
    void jump2(byte a0, byte a1, byte a2);
    void move1(byte a0, byte a1, byte a2);
    void move2(byte a0, byte a1, byte a2);
    void shiftLeft1(byte a0, byte a1, byte a2);
    void shiftLeft2(byte a0, byte a1, byte a2);
    void shiftRight1(byte a0, byte a1, byte a2);
    void shiftRight2(byte a0, byte a1, byte a2);
    void load1(byte a0, byte a1, byte a2);
    void load2(byte a0, byte a1, byte a2);
    void store1(byte a0, byte a1, byte a2);
    void store2(byte a0, byte a1, byte a2);
   
};