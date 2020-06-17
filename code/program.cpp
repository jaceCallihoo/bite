#include "program.h"

#include <iostream>

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

void Program::print() {

    for (Line L : instruction) {
        cout << L.name << ": " << (int)L.arg[0] << ", " << (int)L.arg[1] << ", " << (int)L.arg[2] << endl;
    }

    cout << "pc: " << (int)pc << endl;
    cout << "sp: " << (int)sp << endl;
    cout << "reg:";
    for (size_t i = 0; i < 8; i++) { cout << " " << (int)reg[i]; } cout << endl;
}

// bite instructions

void Program::add1(byte a0, byte a1, byte a2) {

    cout << "add1 " << (int)a0 << " " << (int)a1 << " " << (int)a2 << endl;

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
    if (reg[a1] == reg[a2])
        pc = reg[a0] - 1;
}


void Program::beq2(byte a0, byte a1, byte a2) {
    if (reg[a1] == a2)
        pc = reg[a0] - 1;
}


void Program::beq3(byte a0, byte a1, byte a2) {
    if (reg[a1] == reg[a2])
        pc = a0 - 1;
}


void Program::beq4(byte a0, byte a1, byte a2) {
    if (reg[a1] == a2)
        pc = a0 - 1;
}


void Program::jump1(byte a0, byte a1, byte a2) {
    pc = reg[a0] - 1;
}


void Program::jump2(byte a0, byte a1, byte a2) {
    pc = a0 - 1;
}


void Program::move1(byte a0, byte a1, byte a2) {
    cout << "move1 " << (int)a0 << " " << (int)a1 << endl;

    cout << "before: " <<  (int)reg[a0];

    reg[a0] = reg[a1];

    cout << " after: " << (int)reg[a0] << endl;
}


void Program::move2(byte a0, byte a1, byte a2) {
        cout << "move2 " << (int)a0 << " " << (int)a1 << endl;


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