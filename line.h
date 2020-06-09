#define byte unsigned char

using namespace std;


class Line {

    private:
        void(*func)(byte a0, byte a1, byte a2);
        byte al[3];         // list of argmuments
    public:
        Line(void(*func)(byte a0, byte a1, byte a2), byte a0, byte a1, byte a2);
        void execute();
  
};
