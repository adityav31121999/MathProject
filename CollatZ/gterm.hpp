
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>


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
        t = (t * static_cast<int>(std::pow(2, positions[i]) - 1)) / 3;
        if ((t - 1) % 9 == 0) {
            t = (t - 1) / 3;
            std::cout << "Stops at " << i << " due to no-branching criteria." << std::endl;
            break;
        }
    }
    return t;
}


/**
 * @brief Given a position vector p and number of nodes k, this function
 *        generates all permutations of positions and calculates the
 *        immediate node and branch for each permutation.
 * @param[in] r The number of the node in the Collatz sequence.
 * @param[in] k The number of nodes to be traversed.
 * @param[in] p A vector of positions.
 * @return A 2D vector of size (number of permutations, k+2) where each row
 *         contains the permutation of positions, immediate node value and
 *         branch value.
 */
std::vector<std::vector<int>> checksamestop(int r, int k, std::vector<int> p) {
    // for other values
    std::sort(p.begin(), p.end());      // sort position vector
    // hold all results
    std::vector<std::vector<int>> result(1, std::vector<int>(k+2, 0));
    // for branchless values
    if (((r - 1) % 9 == 0) || ((r - 1) % 3 != 0)) {
        std::cout << "It ends with R -_-" << std::endl;
    }
    else {
        // perform all permutations and generate terms
        int R = static_cast<int>(std::log2(r));
        std::cout << "\nMaximum Possible Stopping time: " << std::accumulate(p.begin(), p.end(), 0) + k + R + 1 << std::endl;
        do {
            int node = (r-1)/3;                 // node value from R
            int m = 0, count  = 0;              // for step counter
            std::vector<int> currentResult(k + 2, 0);
            // loop for current permutation
            for(int i = 0; i < k; i++) {
                // calculate node for current position
                node *= static_cast<int>(std::pow(2, p[i]));
                currentResult[i] = p[i];
                m += currentResult[i];
                count++;
                // break for branchless node
                if((node-1) % 9 == 0) {
                    node = (node - 1) / 3;
                    break;
                }
                // break for connecting nodes
                if ((node - 1) % 3 != 0) {
                    break;
                }
                // for branching not possible
                node = (node - 1)/3;            // calculate new node
            }

            // store all the values and resize for next iteration
            currentResult[k] = node;
            currentResult[k + 1] = m + R + 1 + count;
            result.push_back(currentResult);
        } while(std::next_permutation(p.begin(), p.end()));

        // remove first row containing all zeroes
        std::sort(result.begin(), result.end());
        result.erase(result.begin());
        // keep only unique rows in result 2D vector
        result.erase(std::unique(result.begin(), result.end()), result.end());
    }
    
    return result;
}
