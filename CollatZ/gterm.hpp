
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
        if ((t - 1) % 9 == 0) {
            t = (t - 1) / 3;
            std::cout << "Stops at " << i << " due to no-branching criteria." << std::endl;
            break;
        }
    }
    return t;
}




/*
 * @brief verification of the division ladder equation for collatz conjecture
 * @param[in] p position vector
 * @param[in] r base stem value
 * @return vector of node values
 
int verifytheory1(std::vector<int> p, int r) {
    // check for base stem
    if (((r - 1) % 9 == 0) || ((r - 1) % 3 != 0)) {
        std::cout << "It ends at R" << std::endl;
        return 0;
    }


    int k = p.size();
    int permutes = calculatePermutations(p);

    // hold result
    std::vector<std::vector<int>> check(permutes, std::vector<int>(k + 1, 0));

    // sort original vector for positions
    std::sort(p.begin(), p.end());
    for (int i = 0; i < k; i++)
        std::cout << p[i] << "   ";
    std::cout << std::endl;

    int unique = 0;

    // run for permutations and also calculate nodes
    do {
        // hold first node
        int t = (r - 1) / 3;

        // Loop until we reach the kth term
        for (int i = 0; i < k; i++) {
            t *= std::pow(2, p[i]);
            // for branchless branches and nodes
            if ((t - 1) % 9 == 0) {
                check[permutes][i] = p[i];
                t = (t - 1) / 3;
                break;
            }
            // if wrong node comes in
            if ((t - 1) % 3 != 0) {
                check[permutes][i] = p[i];
                break;
            }
            check[permutes][i] = p[i];
            t = (t - 1) / 3;
        }

        check[permutes][k] = t;         // Store the node
        unique++;
        permutes++;
    } while (std::next_permutation(p.begin(), p.end()));

    // remove the duplicates
    check.erase(std::unique(check.begin(), check.end()), check.end());

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

    std::cout << "Total Results: " << unique \
        << "\n Total Unique Results: " << check.size() \
        << "\n Total Even Results: " << count \
        << "\n Correct Reults: " << (check.size() - count) << std::endl;

    return 0;
}

*/


/*
//* @brief verification of the division ladder equation
//* @param[in] p position vector
//* @param[in] r base stem value
//* @return vector of node values
std::vector<std::vector<long long int>> checktheory(std::vector<long long int> p, int r) {
    // check for base stem
    if ((r - 1) % 9 == 0)
        return { {0} };

    // number of permutations and nodes to be traversed
    int k = p.size();
    int permutes = 1;
    for (int i = 0; i < k; i++)
        permutes *= i;

    // holds permutation
    std::vector<std::vector<long long int>> ps(permutes, std::vector<long long int>(k, 0));
    // hold result
    std::vector<std::vector<long long int>> c(permutes, std::vector<long long int>(k + 1, 0));

    // sort original vector for positions
    std::sort(p.begin(), p.end());
    // run for permutations and also calculate nodes
    do {
        // allot permutation of p to ps
        ps[permutes - 1] = p;
        // hold first node
        long long int t = (r - 1) / 3;

        // Loop until we reach the kth term
        for (int i = 0; i < k; i++) {
            // Flip the bit at position i to compute the next term
            t = t * std::pow(2, p[i]);
            if ((t - 1) % 9 == 0)
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
*/
