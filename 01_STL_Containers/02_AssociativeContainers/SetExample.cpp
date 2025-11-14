/**
 * @file SetExample.cpp
 * @brief Comprehensive examples of std::set usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Ordered unique element storage
 * - Fast O(log n) operations
 * - Custom comparators
 * - Set algorithms
 * - Bounds operations
 */

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

void example1_BasicOperations();
void example2_InsertAndFind();
void example3_LowerUpperBound();
void example4_CustomComparator();
void example5_SetOperations();
void example6_EraseOperations();

/**
 * @brief Example 1: Basic Set Operations
 * @complexity Time: O(log n) for insert, O(n log n) for construction
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Set Operations ---" << std::endl;

    // Set automatically sorts and removes duplicates
    std::set<int> s = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    std::cout << "Set (sorted, unique): ";
    for (int val : s) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Size: " << s.size() << std::endl;
    std::cout << "Empty? " << (s.empty() ? "yes" : "no") << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: Insert and Find
 * @complexity Time: O(log n)
 */
void example2_InsertAndFind() {
    std::cout << "--- Insert and Find ---" << std::endl;

    std::set<int> s;

    // Insert returns pair<iterator, bool>
    auto [it1, inserted1] = s.insert(10);
    std::cout << "Insert 10: " << (inserted1 ? "success" : "failed") << std::endl;

    auto [it2, inserted2] = s.insert(10);  // Duplicate
    std::cout << "Insert 10 again: " << (inserted2 ? "success" : "failed") << std::endl;

    s.insert(20);
    s.insert(30);
    s.emplace(25);  // Construct in place

    std::cout << "Set: ";
    for (int v : s) std::cout << v << " ";
    std::cout << std::endl;

    // Find element
    if (s.find(20) != s.end()) {
        std::cout << "Found 20 in set" << std::endl;
    }

    if (s.find(99) == s.end()) {
        std::cout << "99 not found in set" << std::endl;
    }

    // Count (0 or 1 for set)
    std::cout << "Count of 20: " << s.count(20) << std::endl;
    std::cout << "Count of 99: " << s.count(99) << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 3: Lower and Upper Bound
 * @complexity Time: O(log n)
 */
void example3_LowerUpperBound() {
    std::cout << "--- Lower and Upper Bound ---" << std::endl;

    std::set<int> s = {1, 3, 5, 7, 9};

    std::cout << "Set: ";
    for (int v : s) std::cout << v << " ";
    std::cout << std::endl;

    // lower_bound: first element >= key
    auto lb = s.lower_bound(5);
    std::cout << "lower_bound(5): " << *lb << std::endl;

    lb = s.lower_bound(6);  // No exact match
    std::cout << "lower_bound(6): " << *lb << std::endl;

    // upper_bound: first element > key
    auto ub = s.upper_bound(5);
    std::cout << "upper_bound(5): " << *ub << std::endl;

    // equal_range: [lower_bound, upper_bound)
    auto [first, last] = s.equal_range(5);
    std::cout << "equal_range(5): [" << *first << ", " << *last << ")" << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 4: Custom Comparator
 * @complexity Time: O(log n)
 */
void example4_CustomComparator() {
    std::cout << "--- Custom Comparator ---" << std::endl;

    // Descending order
    std::set<int, std::greater<int>> s1 = {1, 5, 3, 9, 2};

    std::cout << "Descending order: ";
    for (int v : s1) std::cout << v << " ";
    std::cout << std::endl;

    // Custom comparator for strings (by length)
    auto cmp = [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    };

    std::set<std::string, decltype(cmp)> s2(cmp);
    s2.insert("apple");
    s2.insert("hi");
    s2.insert("banana");
    s2.insert("car");

    std::cout << "By length: ";
    for (const auto& str : s2) std::cout << str << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 5: Set Operations (Union, Intersection, Difference)
 * @complexity Time: O(n)
 */
void example5_SetOperations() {
    std::cout << "--- Set Operations ---" << std::endl;

    std::set<int> s1 = {1, 2, 3, 4, 5};
    std::set<int> s2 = {4, 5, 6, 7, 8};

    std::cout << "Set 1: ";
    for (int v : s1) std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "Set 2: ";
    for (int v : s2) std::cout << v << " ";
    std::cout << std::endl;

    std::vector<int> result;

    // Union
    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(),
                   std::back_inserter(result));
    std::cout << "Union: ";
    for (int v : result) std::cout << v << " ";
    std::cout << std::endl;

    // Intersection
    result.clear();
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                         std::back_inserter(result));
    std::cout << "Intersection: ";
    for (int v : result) std::cout << v << " ";
    std::cout << std::endl;

    // Difference (s1 - s2)
    result.clear();
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                       std::back_inserter(result));
    std::cout << "Difference (s1-s2): ";
    for (int v : result) std::cout << v << " ";
    std::cout << std::endl;

    // Symmetric difference
    result.clear();
    std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                 std::back_inserter(result));
    std::cout << "Symmetric difference: ";
    for (int v : result) std::cout << v << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Erase Operations
 * @complexity Time: O(log n)
 */
void example6_EraseOperations() {
    std::cout << "--- Erase Operations ---" << std::endl;

    std::set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Initial: ";
    for (int v : s) std::cout << v << " ";
    std::cout << std::endl;

    // Erase by key
    s.erase(5);
    std::cout << "After erase(5): ";
    for (int v : s) std::cout << v << " ";
    std::cout << std::endl;

    // Erase by iterator
    auto it = s.find(3);
    if (it != s.end()) {
        s.erase(it);
    }
    std::cout << "After erasing iterator to 3: ";
    for (int v : s) std::cout << v << " ";
    std::cout << std::endl;

    // Erase range
    auto first = s.find(6);
    auto last = s.find(9);
    s.erase(first, last);
    std::cout << "After erasing range [6, 9): ";
    for (int v : s) std::cout << v << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "     STL Set Comprehensive Examples     " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_InsertAndFind();
    example3_LowerUpperBound();
    example4_CustomComparator();
    example5_SetOperations();
    example6_EraseOperations();

    std::cout << "========================================" << std::endl;
    std::cout << "  All set examples completed!           " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 SetExample.cpp -o SetExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 SetExample.cpp -o SetExample
 *
 * Run:
 *   ./SetExample       (Linux/Mac)
 *   .\SetExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. Set stores unique elements in sorted order
 * 2. All operations are O(log n)
 * 3. Cannot modify keys (they're const)
 * 4. Use custom comparators for custom ordering
 * 5. Supports set theory operations (union, intersection, etc.)
 * 6. Great for maintaining sorted unique collection
 */

