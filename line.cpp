#include "line.h"

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>


using namespace std;

Line::Line(void(*func)(byte a0, byte a1, byte a2), byte a0 = 0, byte a1 = 0, byte a2 = 0) {
    this->func = func;
    al[0] = a0;
    al[1] = a1;
    al[2] = a2;
}

void Line::execute() {
    func(al[0], al[1], al[2]);
}
