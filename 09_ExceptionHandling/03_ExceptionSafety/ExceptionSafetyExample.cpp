/**
 * @file ExceptionSafetyExample.cpp
 * @brief Demonstrates basic, strong, and no-throw exception safety concepts.
 * @date 2025-11-15
 */

#include <iostream>
#include <vector>
#include <stdexcept>

// Strong exception guarantee function (commit or rollback)
void pushStrong(std::vector<int>& v, int value) {
    std::vector<int> temp = v; // copy (could throw if memory issues)
    temp.push_back(value);     // may throw
    v.swap(temp);              // commit only after success
}

// Basic guarantee: state valid but modified
void pushBasic(std::vector<int>& v, int value) {
    v.push_back(value); // if throws, vector unchanged (still valid)
}

int main() {
    std::cout << "=== Exception Safety Examples ===\n";
    std::vector<int> v{1,2,3};
    pushBasic(v,4);
    pushStrong(v,5);
    std::cout << "Vector: ";
    for (int x : v) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 ExceptionSafetyExample.cpp -o ExceptionSafetyExample */

