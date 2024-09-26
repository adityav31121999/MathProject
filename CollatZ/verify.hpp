
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
 * @brief Check if a given node is valid according to the Collatz Conjecture.
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
        return {0};

    int rvalue = std::pow(2, p[p.size() - 1]);
    // reverse the vector this gives original vector
    std::reverse(p.begin(), p.end());
    p[0] = rvalue;
    return p;
}


/**
 * @brief verification of the division ladder equation for collatz conjecture
 * @param[in] p position vector
 * @param[in] r base stem value
 * @return vector of node values
 */
int verifytheory(std::vector<int> p, int r) {
    // check for base stem
    if (((r - 1) % 9 == 0) || ((r - 1) % 3 != 0)) {
        std::cout << "It ends at R" << std::endl;
        return 0;
    }

    // number of permutations and nodes to be traversed
    int k = p.size();
    int permutes = 1;
    for (int i = 1; i <= k; i++)
        permutes *= i;

    std::cout << "\nPermutations (expected) are: " << permutes << std::endl;

    // hold result
    std::vector<std::vector<int>> check(permutes, std::vector<int>(k + 1, 0));

    // sort original vector for positions
    std::sort(p.begin(), p.end());
    for (int i = 0; i < k; i++)
        std::cout << p[i] << "   ";
    std::cout << " <- Sorted Vector" << std::endl;

    for (int i = 0; i < k; i++)
        std::cout << "m" << i + 1 << "  ";
    std::cout << "Result" << std::endl;

    // run for permutations and also calculate nodes
    do {
        // hold first node
        int t = (r - 1) / 3;

        // Loop until we reach the kth term
        for (int i = 0; i < k; i++) {
            t *= std::pow(2, p[i]);
            // for branchless branches and nodes
            if ((t - 1) % 9 == 0) {
                check[permutes - 1][i] = p[i];
                t = (t - 1) / 3;
                break;
            }
            // if wrong node comes in
            if ((t - 1) % 3 != 0) {
                check[permutes - 1][i] = p[i];
                break;
            }
            check[permutes - 1][i] = p[i];
            t = (t - 1) / 3;
        }

        check[permutes - 1][k] = t;         // Store the node
        permutes--;
    } while (std::next_permutation(p.begin(), p.end()));

    // remove the duplicates
    check.erase(std::unique(check.begin(), check.end()), check.end());

    // delete the first vector
    check.erase(check.begin());

    // count even results
    int count = 0;

    // print the result
    for (int i = 0; i < check.size(); i++) {
        for (int j = 0; j < check[i].size(); j++) {
            std::cout << check[i][j] << "   ";
        }
        std::cout << std::endl;
        if (check[i][k] % 2 == 0) // Corrected the index to use k instead of check[0].size()
            count++;
    }

    std::cout << "Total Results: " << check.size() \
              << "\nTotal Even Results: " << count \
              << "\nCorrect Results: " << (check.size() - count) << std::endl;

    return 0;
}

