/**
 * @file FindExample.cpp
 * @brief Comprehensive examples of std::find family algorithms
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void example1_BasicFind();
void example2_FindIf();
void example3_FindIfNot();
void example4_FindEnd();
void example5_FindFirstOf();
void example6_AdjacentFind();

/**
 * @brief Example 1: Basic std::find
 * @complexity O(n)
 */
void example1_BasicFind() {
    std::cout << "--- Basic std::find ---" << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto it = std::find(vec.begin(), vec.end(), 5);
    if (it != vec.end()) {
        std::cout << "Found 5 at index: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "5 not found" << std::endl;
    }

    // Not found case
    it = std::find(vec.begin(), vec.end(), 100);
    std::cout << "100 found: " << (it != vec.end() ? "yes" : "no") << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: std::find_if with lambda
 * @complexity O(n)
 */
void example2_FindIf() {
    std::cout << "--- std::find_if ---" << std::endl;

    std::vector<int> vec = {1, 3, 5, 7, 8, 9, 11};

    // Find first even number
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    if (it != vec.end()) {
        std::cout << "First even number: " << *it << std::endl;
    }

    // Find number greater than 10
    it = std::find_if(vec.begin(), vec.end(), [](int x) { return x > 10; });
    if (it != vec.end()) {
        std::cout << "First number > 10: " << *it << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 3: std::find_if_not
 * @complexity O(n)
 */
void example3_FindIfNot() {
    std::cout << "--- std::find_if_not ---" << std::endl;

    std::vector<int> vec = {2, 4, 6, 8, 9, 10};

    // Find first non-even number
    auto it = std::find_if_not(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    if (it != vec.end()) {
        std::cout << "First odd number: " << *it << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 4: std::find_end (find last occurrence of subsequence)
 * @complexity O(n*m)
 */
void example4_FindEnd() {
    std::cout << "--- std::find_end ---" << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 1, 2, 3, 5};
    std::vector<int> subseq = {1, 2, 3};

    auto it = std::find_end(vec.begin(), vec.end(), subseq.begin(), subseq.end());
    if (it != vec.end()) {
        std::cout << "Last occurrence at index: " << std::distance(vec.begin(), it) << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 5: std::find_first_of
 * @complexity O(n*m)
 */
void example5_FindFirstOf() {
    std::cout << "--- std::find_first_of ---" << std::endl;

    std::vector<int> vec = {0, 2, 4, 6, 8, 10};
    std::vector<int> values = {3, 5, 7, 8, 9};

    // Find first element from vec that is in values
    auto it = std::find_first_of(vec.begin(), vec.end(), values.begin(), values.end());
    if (it != vec.end()) {
        std::cout << "First match: " << *it << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 6: std::adjacent_find
 * @complexity O(n)
 */
void example6_AdjacentFind() {
    std::cout << "--- std::adjacent_find ---" << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 4, 5, 6};

    // Find first pair of adjacent equal elements
    auto it = std::adjacent_find(vec.begin(), vec.end());
    if (it != vec.end()) {
        std::cout << "Adjacent duplicates: " << *it << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Find Algorithms Examples" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicFind();
    example2_FindIf();
    example3_FindIfNot();
    example4_FindEnd();
    example5_FindFirstOf();
    example6_AdjacentFind();

    std::cout << "========================================" << std::endl;
    std::cout << "  All examples completed!" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 FindExample.cpp -o FindExample
 *
 * Key Takeaways:
 * 1. find returns iterator to first match or end()
 * 2. find_if uses predicates for custom conditions
 * 3. Always check if iterator != end() before dereferencing
 * 4. find_end finds last occurrence of subsequence
 * 5. All have O(n) or O(n*m) complexity
 */

