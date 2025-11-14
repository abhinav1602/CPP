/**
 * @file SearchExample.cpp
 * @brief Examples of std::search algorithms
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>

void example1_BasicSearch();
void example2_SearchN();

void example1_BasicSearch() {
    std::cout << "--- std::search ---" << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> pattern = {4, 5, 6};

    auto it = std::search(vec.begin(), vec.end(), pattern.begin(), pattern.end());
    if (it != vec.end()) {
        std::cout << "Pattern found at index: " << std::distance(vec.begin(), it) << std::endl;
    }
    std::cout << std::endl;
}

void example2_SearchN() {
    std::cout << "--- std::search_n ---" << std::endl;
    std::vector<int> vec = {1, 2, 3, 3, 3, 4, 5};

    auto it = std::search_n(vec.begin(), vec.end(), 3, 3);  // Find 3 consecutive 3's
    if (it != vec.end()) {
        std::cout << "Found 3 consecutive 3's at index: " << std::distance(vec.begin(), it) << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Search Algorithms" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    example1_BasicSearch();
    example2_SearchN();

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 SearchExample.cpp -o SearchExample */

