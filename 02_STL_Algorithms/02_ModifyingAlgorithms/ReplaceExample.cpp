/**
 * @file ReplaceExample.cpp
 * @brief Examples of std::replace algorithms
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Replace Algorithms" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    // replace
    std::cout << "--- std::replace ---" << std::endl;
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    std::replace(vec.begin(), vec.end(), 2, 99);

    std::cout << "After replacing 2 with 99: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    // replace_if
    std::cout << "--- std::replace_if ---" << std::endl;
    vec = {1, 2, 3, 4, 5, 6, 7, 8};
    std::replace_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }, 0);

    std::cout << "After replacing even with 0: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 ReplaceExample.cpp -o ReplaceExample */

