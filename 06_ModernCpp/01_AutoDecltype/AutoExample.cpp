/**
 * @file AutoExample.cpp
 * @brief Auto and Decltype
 * @date 2025-11-15
 */

#include <iostream>
int main() {
    auto x = 42;
    auto y = 3.14;
    auto z = "Hello";
    std::cout << "x=" << x << ", y=" << y << ", z=" << z << std::endl;
    decltype(x) another_int = 100;
    std::cout << "another_int=" << another_int << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 AutoExample.cpp -o  */
