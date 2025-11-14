/**
 * @file VariadicTemplateExample.cpp
 * @brief Demonstrates variadic templates & fold expressions.
 * @date 2025-11-15
 */
#include <iostream>
#include <string>

// Fold expression sum
template<typename... Ts>
auto sum(Ts... xs){ return (xs + ...); }

// Print any number of arguments
template<typename... Ts>
void printAll(Ts&&... xs){ ((std::cout<<xs<<' '), ...); std::cout<<'\n'; }

int main(){
    std::cout << sum(1,2,3,4) << '\n';
    printAll("Hello",42,'X');
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 VariadicTemplateExample.cpp -o VariadicTemplateExample */
