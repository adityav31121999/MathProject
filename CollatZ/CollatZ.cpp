// CollatZ.cpp : Defines the entry point for the application.
//

#include "CollatZ.h"

int main() {
	std::cout << "-_- Project for Collatz Conjecture -_-" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	int r = 16;
	std::vector<int> p;
	p = { 3, 2, 1, 2, 4, 1, 3, 3};
	verifytheory(p, r);
	std::cout << "" << std::endl;
	return 0;
}
