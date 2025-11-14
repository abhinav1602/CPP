/**
 * @file SetUnionExample.cpp
 * @brief Examples of std::set_union and set_difference
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Set Union Algorithm" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {3, 4, 5, 6, 7};
    std::vector<int> result;

    // set_union
    std::cout << "--- std::set_union ---" << std::endl;
    std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));

    std::cout << "Union: ";
    for (int x : result) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    // set_difference
    result.clear();
    std::cout << "--- std::set_difference ---" << std::endl;
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));

    std::cout << "Difference (v1 - v2): ";
    for (int x : result) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 SetUnionExample.cpp -o SetUnionExample */

