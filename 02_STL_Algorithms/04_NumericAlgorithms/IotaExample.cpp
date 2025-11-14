/**
 * @file IotaExample.cpp
 * @brief Examples of std::iota
 * @date 2025-11-15
 */

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Iota Algorithm" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    std::cout << "--- std::iota (fill with sequence) ---" << std::endl;
    std::vector<int> vec(10);
    std::iota(vec.begin(), vec.end(), 0);

    std::cout << "Generated: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    // Starting from different value
    std::cout << "--- Starting from 100 ---" << std::endl;
    std::iota(vec.begin(), vec.end(), 100);
    std::cout << "Generated: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 IotaExample.cpp -o IotaExample */

