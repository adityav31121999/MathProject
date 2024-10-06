
// CollatZ.cpp : Defines the entry point for the application.
//

#include "CollatZ.h"

int main() {
    std::cout << "Collatz Conjecture Program for Branch Nodes: " << std::endl;
    int k = 0, r = 0;
    std::cout << "Enter Number of nodes to be traversed: ";
    std::cin >> k;
    std::cout << "\nEnter R value from base stem (2^n): ";
    std::cin >> r;
    std::cout << "\nFollowing are the values of immediate nodes and branches of the positions: " << std::endl;
    std::vector<int> l(k, 0);
    for (int i = 0; i < k; i++)
        std::cin >> l[i];
    std::vector<std::vector<int>> positions;
    for (int i = 0; i < k; i++)
        std::cout << i << "    ";
    std::cout << "Result    Stopping Time" << std::endl;
    positions = checksamestop(r, k, l);
    for (int i = 0; i < positions.size(); i++) {
        for (int j = 0; j < k + 2; j++) {
            std::cout << positions[i][j] << "    ";
        }
        std::cout << std::endl;
    }

    return 0;
}
