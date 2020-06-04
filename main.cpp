#include "bite.h"
// #include "line.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// construct the Bite object
	Bite b("bite.txt");

	return 0;

	// execute the object repeatedly until the bite program is over
	while(b.next());

    return 0;
}
