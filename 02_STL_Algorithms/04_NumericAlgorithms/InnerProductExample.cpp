/**
 * @file InnerProductExample.cpp
 * @brief Examples of std::inner_product
 * @date 2025-11-15
 */

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Inner Product Algorithm" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {5, 4, 3, 2, 1};

    // Dot product
    std::cout << "--- Dot Product ---" << std::endl;
    int dot = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
    std::cout << "Dot product: " << dot << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 InnerProductExample.cpp -o InnerProductExample */

