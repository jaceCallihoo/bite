#include "bite.h"
// #include "line.h"

#include <iostream>

using namespace std;

int main()
{
	// construct the Bite object
	Bite B("bite.txt");

	// execute the object repeatedly until the bite program is over
	//while(B.execute());

	for (int i = 0; i < 4; i++) {
		B.execute();
	}

	B.print();

    return 0;
}
