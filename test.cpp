#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    
    vector<string> v(3);

    v[2] = to_string(10);

    cout << v[2] << endl;

    return 0;
}
