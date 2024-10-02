
// Collatz Series and Steps 
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <functional>
#include <filesystem>


/**
 * @brief Compute the Collatz sequence for a single number
 * @param[in] input the input number
 * @return a vector of numbers representing the Collatz sequence
 */
std::vector<long long int> collatzseq(long long int input) {
	std::vector<long long int> seq;
	seq.push_back(input);
	while (input != 1) {
		// if the number is even, divide it by 2
		if (input % 2 == 0)
			input /= 2;
		// if the number is odd, multiply it by 3 and add 1
		else
			input = 3 * input + 1;
		seq.push_back(input);
	}
	return seq;
}


/**
 * @brief Stopping time for a positive integer.
 *		  Using Collatz Conjecture to calculate number of steps required to reach 1.
 * @param[in] input positive integer input
 * @return Stpping time
 */
int stopping(long long int input) {
	int steps = 0;
	long long int n = input;
	while (1) {
		if (n > 1) {
			if (n % 2 == 0)
				n /= 2;
			else
				n = 3 * n + 1;
			steps++;
		}
		else
			break;
	}
	return steps;
}


/**
 * @brief Compute Stopping time of Collatz sequence for a range of numbers
 * @param[in] lim1 lower limit of the range
 * @param[in] lim2 upper limit of the range
 * @return a vector of pairs where each pair contains the number and
 *         the number of steps to reach 1
 */
std::vector<std::pair<long long int, int>> collatzsteps(long long int lim1, long long int lim2) {
	std::vector<std::pair<long long int, int>> csteps;
	for (long long int i = lim1; i <= lim2; i++) {
		long long int n = i;
		int steps = 0;
		// Compute the Collatz sequence for the number
		while (n != 1) {
			if (n % 2 == 0)
				n /= 2; // if n is even, divide it by 2
			else
				n = 3 * n + 1; // if n is odd, multiply it by 3 and add 1
			steps++; // increment the number of steps
		}
		// Store the number and the number of steps
		csteps.push_back({ i, steps });
	}
	return csteps;
}


/**
 * @brief Check if a given node is valid according to the Collatz Conjecture.
 * @param[in] node the node to check
 * @return a vector of positions of the bits to flip in the division
 *         ladder to get the next node in the sequence. If the node is
 *         invalid, the function returns an empty vector.
 */
std::vector<long long int> checkpositions(int node) {
    // when input is one
    if (node == 1) {
        return { 0 };
    }

    // when input is not 1
    std::vector<long long int> p(0);
    while (node != 1) {
        // 2^n = 3node + 1 => log2(3node + 1) = n => pushback n
        node = 3 * node + 1; // make it even
        int count = 0;
        while (node % 2 == 0) {
            count++;
            node = node / 2;  // divide by 2 and continue incrementing count
        }
        p.push_back(count); // pushback count in vector
    }

    int rvalue = std::pow(2, p[p.size() - 1]);
    // reverse the vector this gives original vector
    std::reverse(p.begin(), p.end());
    p[0] = rvalue;
    return p;
}
