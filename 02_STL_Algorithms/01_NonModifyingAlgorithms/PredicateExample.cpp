/**
 * @file PredicateExample.cpp
 * @brief Examples of std::all_of, std::any_of, std::none_of
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>

void example1_AllOf();
void example2_AnyOf();
void example3_NoneOf();

void example1_AllOf() {
    std::cout << "--- std::all_of ---" << std::endl;
    std::vector<int> vec = {2, 4, 6, 8, 10};

    bool all_even = std::all_of(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << "All even: " << (all_even ? "yes" : "no") << std::endl;

    bool all_positive = std::all_of(vec.begin(), vec.end(), [](int x) { return x > 0; });
    std::cout << "All positive: " << (all_positive ? "yes" : "no") << std::endl << std::endl;
}

void example2_AnyOf() {
    std::cout << "--- std::any_of ---" << std::endl;
    std::vector<int> vec = {1, 3, 5, 7, 8};

    bool any_even = std::any_of(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << "Any even: " << (any_even ? "yes" : "no") << std::endl << std::endl;
}

void example3_NoneOf() {
    std::cout << "--- std::none_of ---" << std::endl;
    std::vector<int> vec = {1, 3, 5, 7, 9};

    bool none_even = std::none_of(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << "None even: " << (none_even ? "yes" : "no") << std::endl << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  Predicate Algorithms" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    example1_AllOf();
    example2_AnyOf();
    example3_NoneOf();

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 PredicateExample.cpp -o PredicateExample */

