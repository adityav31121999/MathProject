
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <functional>
#include <filesystem>


/**
 * @brief Compute the kth term of the Collatz sequence for a given starting value R
 *        This function takes a list of positions and a value from a base stem, and computes
 *        the kth term of the Collatz sequence starting from the given value. The function
 *        works by flipping the bits at the given positions and then computing the next
 *        term in the sequence. If the value is 1, the function returns 0.
 * @param[in] positions the positions of the bits to flip
 * @param[in] k the kth term to compute
 * @param[in] Rvalue value from base stem
 * @return the kth term of the sequence
 */
long long int generateterm(std::vector<int> positions, long long int k, long long int Rvalue) {
    // Compute the kth term of the sequence
    if ((Rvalue - 1) % 9 == 0) {
        std::cerr << "Branchless Stem Value -_-" << std::endl;
        return (Rvalue - 1) / 3;
    }

    // calculate the first node
    long long int t = (Rvalue - 1) / 3;

    // Loop until we reach the kth term
    for (int i = 0; i < k; i++) {
        // Flip the bit at position i to compute the next term
        t = (t * std::pow(2, positions[i]) - 1) / 3;
        /*
        if ((t - 1) % 9 == 0) {
            t = (t - 1) / 3;
            break;
        }
        */
    }
    return t;
}
