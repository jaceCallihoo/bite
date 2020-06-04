#define byte unsigned char

#include <string>
#include <vector>

using namespace std;

extern byte pc;			// program counter
extern char reg[8];		// registers
extern byte sp;			// stack pointer
extern byte stack[256];	// stack
extern byte mem[256];   // memory

 


class Line {

public:
     struct arg {
        bool regFlag;   // true for reg, false for Num
        byte val;       // value of teh reg or number
    };


    private:
        byte instruction;
        arg al[3];         // list of argmuments
    public:
        Line(byte in, arg a0, arg a1, arg a2);
        void execute();
  
};

enum code { ADD, AND, OR, BEQ, SL, SR, J, MOV, LW, SW };     // list of instructions

vector<Line> parse(vector<string> input);
Line validateLine(vector<string> tokenList);
