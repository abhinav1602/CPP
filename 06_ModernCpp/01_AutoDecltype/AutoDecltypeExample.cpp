/**
 * @file AutoDecltypeExample.cpp
 * @brief Demonstrates auto type deduction and decltype
 * @date 2025-11-15
 */
#include <iostream>
#include <type_traits>

int main(){
    auto i = 10; auto d = 3.5; auto s = "text";
    decltype(i) another = 20; // same type as i
    std::cout << i << ' ' << d << ' ' << s << ' ' << another << '\n';
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 AutoDecltypeExample.cpp -o AutoDecltypeExample */
