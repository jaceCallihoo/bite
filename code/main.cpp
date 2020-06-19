#include "bite.h"

#include <time.h>
#include <iostream>

using namespace std;

void print(Bite B);
void sleep(int milisec);

int main()
{
	// construct the Bite object
	Bite B("bite.txt");

	// print start state
	print(B);

	// print throughout execution
	while (B.execute())
		print(B);
	
	// print end state
	print(B);

    return 0;
}

void print(Bite B) {
	cout << "\033[2J\033[1;1H"; // clear terminal
	B.print();					// print
	sleep(500);					// sleep
}

void sleep(int milisec) {
	struct timespec req = {0};
	req.tv_sec = 0;
	req.tv_nsec = milisec * 1000000L;
	nanosleep(&req, (struct timespec *)NULL);
}
