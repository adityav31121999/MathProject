
// CollatZ.cpp : Defines the entry point for the application.
//

#include "CollatZ.h"

int main() {
    std::cout << "Verify Theory with this program:" << std::endl;
    int r = 0;
    int k = 0;
    std::cout << "ENTER Total number of nodes: ";
    std::cin >> k;
    std::cout << "\nENTER R-value: ";
    std::cin >> r;
    std::vector<int> p(k, 0);
    std::cout << "\nEnter Positions: ";
    for (int i = 0; i < k; i++)
        std::cin >> p[i];
    verifytheory(p, r);
    return 0;
}
