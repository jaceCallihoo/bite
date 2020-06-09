#include <string>
#include <vector>

#define byte unsigned char

using namespace std;

struct BluePrint
{
    string name;
    vector<bool> argType;
    void(*func)(byte, byte, byte);
};

enum argType { NUM, REG };