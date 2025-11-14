/**
 * @file BinarySearchExample.cpp
 * @brief Examples of binary search algorithms
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  Binary Search Algorithms" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15};

    // binary_search
    std::cout << "--- std::binary_search ---" << std::endl;
    bool found = std::binary_search(vec.begin(), vec.end(), 7);
    std::cout << "7 found: " << (found ? "yes" : "no") << std::endl << std::endl;

    // lower_bound
    std::cout << "--- std::lower_bound ---" << std::endl;
    auto lb = std::lower_bound(vec.begin(), vec.end(), 7);
    std::cout << "Lower bound of 7 at index: " << std::distance(vec.begin(), lb) << std::endl << std::endl;

    // upper_bound
    std::cout << "--- std::upper_bound ---" << std::endl;
    auto ub = std::upper_bound(vec.begin(), vec.end(), 7);
    std::cout << "Upper bound of 7 at index: " << std::distance(vec.begin(), ub) << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 BinarySearchExample.cpp -o BinarySearchExample */

