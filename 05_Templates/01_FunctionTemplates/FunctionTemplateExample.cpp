/**
 * @file FunctionTemplateExample.cpp
 * @brief Function Templates
 * @date 2025-11-15
 */

#include <iostream>
template<typename T>
T add(T a, T b) { return a + b; }

int main() {
    std::cout << "Int: " << add(5, 3) << std::endl;
    std::cout << "Double: " << add(5.5, 3.3) << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 FunctionTemplateExample.cpp -o  */
