/**
 * @file CountExample.cpp
 * @brief Examples of std::count and std::count_if
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void example1_BasicCount();
void example2_CountIf();
void example3_CountStrings();
void example4_CountWithLambda();

void example1_BasicCount() {
    std::cout << "--- Basic std::count ---" << std::endl;
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    int count = std::count(vec.begin(), vec.end(), 2);
    std::cout << "Count of 2: " << count << std::endl << std::endl;
}

void example2_CountIf() {
    std::cout << "--- std::count_if ---" << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int even_count = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << "Even numbers: " << even_count << std::endl << std::endl;
}

void example3_CountStrings() {
    std::cout << "--- Count strings ---" << std::endl;
    std::vector<std::string> words = {"hello", "world", "hello", "cpp"};
    int hello_count = std::count(words.begin(), words.end(), "hello");
    std::cout << "Count of 'hello': " << hello_count << std::endl << std::endl;
}

void example4_CountWithLambda() {
    std::cout << "--- Complex predicate ---" << std::endl;
    std::vector<int> vec = {5, 15, 25, 35, 45, 55};
    int count = std::count_if(vec.begin(), vec.end(), [](int x) { return x > 20 && x < 50; });
    std::cout << "Numbers between 20 and 50: " << count << std::endl << std::endl;
}

int main() {
    std::cout << "========================================"<< std::endl;
    std::cout << "  STL Count Algorithms Examples" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    example1_BasicCount();
    example2_CountIf();
    example3_CountStrings();
    example4_CountWithLambda();

    std::cout << "========================================" << std::endl;
    std::cout << "  All examples completed!" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 CountExample.cpp -o CountExample */

