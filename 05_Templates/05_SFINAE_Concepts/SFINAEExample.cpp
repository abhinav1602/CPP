/**
 * @file SFINAEExample.cpp
 * @brief Simple SFINAE with enable_if to detect integral types.
 * @date 2025-11-15
 */
#include <iostream>
#include <type_traits>

template<typename T>
std::enable_if_t<std::is_integral_v<T>, T> addOne(T v){ return v+1; }

template<typename T>
std::enable_if_t<!std::is_integral_v<T>, T> addOne(T v){ std::cout<<"Non-integral path\n"; return v; }

int main(){ std::cout<< addOne(5) << '\n'; std::cout<< addOne(3.14) << '\n'; return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 SFINAEExample.cpp -o SFINAEExample */
