
/**
 * --------------------------------------------------:checktheory:--------------------------------------------------
 * This process involves the calculation of the Nodes of Collatz Conjecture.
 * - By using the division ladder equation, calculate node values of the collatz tree.
 * - For this, first take certain numbre of values in a vector, this is position vector.
 * - This vector will be used in calculatiing powers of 2.
 * - Get a base stem value which is of even power and also power should be larger than 3.
 * - If this value is divisible by 9, then this is not valid. Return 0.
 * - On next step, perform the operations as per division ladder.
 * - If any value T*2^n -1 is divisible by 9, then this is not valid. Return 0.
 * - If all the values are valid, return the node value.
 * 
 * For cecking theory and finding a patter:
 * - Get a vector of numebrs/positions
 * - Perform permutations on positions, and store in 2D vector.
 * - Operate using above process and store values along with positions 
 * - Use another function to check whether the obtained values are correct or not
 * - This function will calculate whether all the values involved are correct or not
 * - Return the vector
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>


/**
 * @brief verification of the division ladder equation
 * @param[in] p position vector
 * @param[in] r base stem value
 * @return vector of node values
 */
std::vector<std::vector<long long int>> checktheory(std::vector<long long int> p, int r) {
    // check for base stem
    if((r-1)%9 == 0)
        return {{0}};

    // number of permutations and nodes to be traversed
    int k = p.size();
    int permutes = 1;
    for (int i = 0; i < k; i++)
        permutes *= i;

    // holds permutation
    std::vector<std::vector<long long int>> ps(permutes, std::vector<long long int>(k, 0));
    // hold result
    std::vector<std::vector<long long int>> c(permutes, std::vector<long long int>(k+1, 0));

    // sort original vector for positions
    std::sort(p.begin(), p.end());
    // run for permutations and also calculate nodes
    do {
        // allot permutation of p to ps
        ps[permutes-1] = p;
        // hold first node
        long long int t = (r - 1) / 3;

        // Loop until we reach the kth term
        for (int i = 0; i < k; i++) {
            // Flip the bit at position i to compute the next term
            t = t * std::pow(2, p[i]);
            if((t-1)%9 == 0)
                break;
            c[permutes][i] = i; 
            t = (t - 1) / 3;
        }

        // Store the node
        c[permutes][k] = t;
        permutes--;
    } while (std::next_permutation(p.begin(), p.end()));
    
    return c;
}


/**
 * @brief Check if a given node is valid according to the Collatz
 *        Conjecture.
 * @param[in] node the node to check
 * @return a vector of positions of the bits to flip in the division
 *         ladder to get the next node in the sequence. If the node is
 *         invalid, the function returns an empty vector.
 */
std::vector<long long int> checkpositions(int node) {
    std::vector<long long int> p;
    while(node != 1) {
        // 2^n = 3node + 1 => log2(3node + 1) = n => pushback n
        node = 3*node + 1; // make it even
        int count = 0;
        while(node%2 == 0) {
            count++;
            node = node/2;  // divide by 2 and continue incrementing count
        }
        p.push_back(count); // pushback count in vector
    }
    if (p.size() == 0)
        return p;

    int rvalue = std::pow(2, p[p.size() - 1]);
    // reverse the vector this gives original vector
    std::reverse(p.begin(), p.end());
    p[0] = rvalue;
    return p;
}


std::vector<std::vector<long long int>> verifytheory(std::vector<long long int> p, int r) {
    // check for base stem
    if((r-1)%9 == 0)
        return {{0}};

    // number of permutations and nodes to be traversed
    int k = p.size();
    int permutes = 1;
    for (int i = 0; i < k; i++)
        permutes *= i;
    
    // holds all the values required for cross checking and verification
    std::vector<std::vector<long long int>> v(permutes, std::vector<long long int>(2*p.size()+3));
    
    return v;
}
