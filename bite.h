#include "line.h"

#include <string>
#include <unordered_map>

using namespace std;

#define byte unsigned char
#define uint unsigned int

class Bite {
    private:
        byte pc;			// program counter
        byte sp;			// stack pointer    
        char reg[8];		// registers
        char stack[256];	// stack
        char mem[256];   	// memory

        vector<Line> instructions;

        enum code { ADD, AND, OR, BEQ, SL, SR, J, MOV, LW, SW };     // list of instructions
        unordered_map<string,byte> codeNum = { {"ADD",ADD}, {"AND",AND}, {"OR",OR}, {"BEQ",BEQ}, {"SL",SL}, {"SR",SR},{"J",J}, {"MOV",MOV}, {"LW",LW}, {"SW",SW} };

    public:
        Bite(string fileName);
        bool next();

        vector<string> fileToString(string fileName);
        vector<vector<string>> tokenize(vector<string> inputText);
        bool tokenError(vector<vector<string>> inputTokens);
        vector<vector<string>> reduceTokens(vector<vector<string>> inputTokens);

        bool isValidReg(string token);
        bool isValidNum(string token);

};