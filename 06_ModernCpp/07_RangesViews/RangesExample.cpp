/**
 * @file RangesExample.cpp
 * @brief Demonstrates basic C++20 ranges and views pipeline (requires C++20).
 * @date 2025-11-15
 */

#include <iostream>
#include <vector>
#if __cplusplus >= 202002L
#include <ranges>
#endif

int main() {
#if __cplusplus >= 202002L
    std::vector<int> nums{1,2,3,4,5,6,7,8,9};
    auto evenSquares = nums | std::views::filter([](int x){ return x % 2 == 0; })
                             | std::views::transform([](int x){ return x * x; });
    std::cout << "Even squares: ";
    for (int v : evenSquares) std::cout << v << ' ';
    std::cout << '\n';
#else
    std::cout << "Ranges not supported (compile with -std=c++20)." << '\n';
#endif
    return 0;
}

/* Compilation:
 *   g++ -std=c++20 -Wall -Wextra -O2 RangesExample.cpp -o RangesExample
 */

