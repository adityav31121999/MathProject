
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <functional>
#include <filesystem>


/**
 * @brief Compute the kth term of the Collatz sequence for a given starting value R
 * @param[in] positions the positions of the bits to flip
 * @param[in] k the kth term to compute
 * @param[in] Rvalue the starting value of the sequence
 * @return the kth term of the sequence
 */
long long int generateterm(std::vector<int> positions, int k, long long int Rvalue) {
    // Compute the kth term of the sequence
    long long int t = (Rvalue - 1) / 3;
    for (int i = 0; i < k; i++) {
        // Flip the bit at position i to compute the next term
        t = (t * std::pow(2, positions[i]) - 1) / 3;
    }
    return t;
}
