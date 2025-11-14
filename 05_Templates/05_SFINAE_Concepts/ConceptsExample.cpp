/**
 * @file ConceptsExample.cpp
 * @brief C++20 concepts usage to constrain templates.
 * @date 2025-11-15
 */
#include <iostream>
#if __cplusplus >= 202002L
#include <concepts>

template<std::integral T>
T add(T a, T b){ return a+b; }
#else
// Fallback for pre-C++20
template<typename T>
T add(T a, T b){ return a+b; }
#endif

int main(){ std::cout<< add(2,3) << '\n'; return 0; }
/* Compilation: g++ -std=c++20 -Wall -Wextra -O2 ConceptsExample.cpp -o ConceptsExample */
