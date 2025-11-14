/**
 * @file ConstexprExample.cpp
 * @brief Demonstrates constexpr functions, variables, and compile-time evaluation (C++17/20 subset).
 * @date 2025-11-15
 */

#include <iostream>
#include <array>

constexpr int square(int x) { return x * x; }
constexpr std::array<int,5> makeArray() {
    return {square(1), square(2), square(3), square(4), square(5)};
}

int main() {
    constexpr int s = square(7); // compile-time
    constexpr auto arr = makeArray();

    std::cout << "constexpr square(7)=" << s << '\n';
    std::cout << "constexpr array: ";
    for (auto v : arr) std::cout << v << ' ';
    std::cout << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 ConstexprExample.cpp -o ConstexprExample */

