/**
 * @file FillExample.cpp
 * @brief Examples of std::fill and std::generate
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Fill & Generate Algorithms" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    // fill
    std::cout << "--- std::fill ---" << std::endl;
    std::vector<int> vec(10);
    std::fill(vec.begin(), vec.end(), 42);

    std::cout << "Filled with 42: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    // fill_n
    std::cout << "--- std::fill_n ---" << std::endl;
    vec.resize(10);
    std::fill_n(vec.begin(), 5, 99);

    std::cout << "First 5 filled with 99: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    // generate
    std::cout << "--- std::generate ---" << std::endl;
    int n = 0;
    std::generate(vec.begin(), vec.end(), [&n]() { return n++; });

    std::cout << "Generated sequence: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 FillExample.cpp -o FillExample */

