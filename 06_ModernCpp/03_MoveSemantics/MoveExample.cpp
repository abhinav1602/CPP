/**
 * @file MoveExample.cpp
 * @brief Move Semantics
 * @date 2025-11-15
 */

#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::cout << "v1 size: " << v1.size() << std::endl;

    std::vector<int> v2 = std::move(v1);
    std::cout << "After move - v1 size: " << v1.size() << ", v2 size: " << v2.size() << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 MoveExample.cpp -o  */
