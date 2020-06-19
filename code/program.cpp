#include "program.h"

#include <iostream>
#include <iomanip>

Program::Program() {

    pc = 0;
    sp = 0;

    for (byte r : reg)
        r = 0;
}

bool Program::execute() {

    // execute line[pc]
    if (instruction[pc].name.compare("add1") == 0) { add1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("add2") == 0) { add2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("and1") == 0) { and1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("and2") == 0) { and2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("or1") == 0) { or1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("or2") == 0) { or2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("beq1") == 0) { beq1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("beq2") == 0) { beq2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("beq3") == 0) { beq3(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("beq4") == 0) { beq4(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("jump1") == 0) { jump1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("jump2") == 0) { jump2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("move1") == 0) { move1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("move2") == 0) { move2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("shiftLeft1") == 0) { shiftLeft1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("shiftLeft2") == 0) { shiftLeft2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("shiftRight1") == 0) { shiftRight1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("shiftRight2") == 0) { shiftRight2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("load1") == 0) { load1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("load2") == 0) { load2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("store1") == 0) { store1(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else if (instruction[pc].name.compare("store2") == 0) { store2(instruction[pc].arg[0], instruction[pc].arg[1], instruction[pc].arg[2]); }
    else exit(1); // if the instruction is not recognizezed

    pc += 1;

    if (pc >= 255)
        return false;
    else
        return true;
}

void Program::addLine(Line line) {

    cout << "addline" << endl;

    if (line.name.compare("") == 0)
        return;
    else
        instruction.push_back(line);
}

void Program::addPrintTokens(vector<vector<string>> printTokens) {
    printInstructions = printTokens;
    printInstructions.push_back({"J", "255"});
}

void Program::print() {

    // print pc and instruction
    int pcPrintStart, pcPrintEnd;
    setPrintItters(pcPrintStart, pcPrintEnd);

    for (size_t pcPrintCurrent = pcPrintStart; pcPrintCurrent < pcPrintEnd; pcPrintCurrent++) {
        
        if (pcPrintCurrent == (size_t)pc) {
            cout << ">" << setw(3) << right << pcPrintCurrent << " ";
        } else {
            cout << setw(4) << right << pcPrintCurrent << " ";
        }
        

        for (string s : printInstructions[pcPrintCurrent]) {
            cout << setw(5) << s;
        }
        cout << endl;
    }

    cout << endl << "--------------------------------------------------" << endl;

    for (size_t i = 0; i < sizeof(reg); i++) { cout << " $" << i << "[" << (int)reg[i] << "]"; } cout << endl;

    cout << "--------------------------------------------------" << endl << endl;
}

void Program::setPrintItters(int &start, int &end) {
    
    // if the size of the program is less then five lines
    if (instruction.size() < 5) {
        start = 0;
        end = instruction.size();
        return;
    } else {
        if ((int)pc - 2 < 0) {
            start = 0;
            end = start + 5;
        } else if ((int)pc + 3 > instruction.size()) {
            end = instruction.size();
            start = end - 5;
        } else {
            start = pc - 2;
            end = pc + 3;
        }
    }
}

// bite instructions

void Program::add1(byte a0, byte a1, byte a2) {

    reg[a0] = (byte)reg[a1] + (byte)reg[a2];
}


void Program::add2(byte a0, byte a1, byte a2) {
    reg[a0] = reg[a1] + a2;
}


void Program::and1(byte a0, byte a1, byte a2) {
    reg[a0] = reg[a1] & reg[a2];
}


void Program::and2(byte a0, byte a1, byte a2) {
    reg[a0] = reg[a1] & a2;
}


void Program::or1(byte a0, byte a1, byte a2) {
    reg[a0] = reg[a1] | reg[a2];
}


void Program::or2(byte a0, byte a1, byte a2) {
    reg[a0] = reg[a1] & a2;
}


void Program::beq1(byte a0, byte a1, byte a2) {
    if (reg[a0] == reg[a1])
        pc = reg[a2] - 1;
}


void Program::beq2(byte a0, byte a1, byte a2) {
    if (reg[a0] == reg[a1])
        pc = a2 - 1;
}


void Program::beq3(byte a0, byte a1, byte a2) {
    if (reg[a0] == a1)
        pc = reg[a2] - 1;
}


void Program::beq4(byte a0, byte a1, byte a2) {
    if (reg[a0] == a1)
        pc = a2 - 1;
}


void Program::jump1(byte a0, byte a1, byte a2) {
    pc = reg[a0] - 1;
}


void Program::jump2(byte a0, byte a1, byte a2) {
    pc = a0 - 1;
}


void Program::move1(byte a0, byte a1, byte a2) {
  

    reg[a0] = reg[a1];

}


void Program::move2(byte a0, byte a1, byte a2) {

    reg[a0] = a1;
}


void Program::shiftLeft1(byte a0, byte a1, byte a2) {
    reg[a0] = reg[a1] << reg[a2];
}


void Program::shiftLeft2(byte a0, byte a1, byte a2) {
    reg[a0] = reg[a1] << a2;
}


void Program::shiftRight1(byte a0, byte a1, byte a2) {
    reg[a0] = reg[a1] >> reg[a2];
}


void Program::shiftRight2(byte a0, byte a1, byte a2) {
    reg[a0] = reg[a1] >> a2;
}


void Program::load1(byte a0, byte a1, byte a2) {
    reg[a0] = mem[reg[a1]];
}


void Program::load2(byte a0, byte a1, byte a2) {
    reg[a0] = mem[a1];
}


void Program::store1(byte a0, byte a1, byte a2) {
    mem[reg[a1]] = reg[a0];
}


void Program::store2(byte a0, byte a1, byte a2) {
    mem[a1] = reg[a0];
}