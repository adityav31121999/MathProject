// CollatZ.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "basic.hpp"
#include "gterm.hpp"
#include "verify.hpp"


/*
 * @brief Compute the kth term of the Collatz sequence for a given starting value R
 *       This function takes a list of positions and computes the kth term of the Collatz
 *       sequence starting from the given value. The function works by flipping the bits
 *       at the given positions and then computing the next term in the sequence. If the
 *       value is 1, the function returns 0.
 * @param[in] positions the positions of the bits to flip (including base stem value position)
 * @param[in] k the kth term to compute
 * @return the kth term of the sequence
long long int generateterm(std::vector<int> positions) {
    // Compute the kth term of the sequence
    long long int t = 0;
    t = std::pow(2, positions[0]);
    // Loop until we reach the kth term
    for (int i = 1; i < positions.size(); i++) {
        // Flip the bit at position i to compute the next term
        if((t-1)%9 == 0)
            break;
        // Compute the next term in the sequence
        t = (t * std::pow(2, positions[i]) - 1) / 3;
    }
    return t;
}
*/
