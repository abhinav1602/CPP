/**
 * @file MultisetExample.cpp
 * @brief Comprehensive examples of std::multiset usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Ordered elements with duplicates allowed
 * - Counting duplicate occurrences
 * - equal_range for finding all duplicates
 * - Use cases for frequency counting
 */

#include <iostream>
#include <set>
#include <algorithm>
#include <string>

void example1_BasicOperations();
void example2_DuplicateHandling();
void example3_CountingOperations();
void example4_EqualRange();
void example5_EraseOperations();
void example6_FrequencyCounter();

/**
 * @brief Example 1: Basic Multiset Operations
 * @complexity Time: O(log n) for insert
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Multiset Operations ---" << std::endl;

    // Multiset allows duplicates
    std::multiset<int> ms = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::cout << "Multiset (sorted, duplicates allowed): ";
    for (int val : ms) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Size: " << ms.size() << std::endl;
    std::cout << "Count of 5: " << ms.count(5) << std::endl;
    std::cout << "Count of 1: " << ms.count(1) << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: Duplicate Handling
 * @complexity Time: O(log n) for insert
 */
void example2_DuplicateHandling() {
    std::cout << "--- Duplicate Handling ---" << std::endl;

    std::multiset<int> ms;

    // Insert returns iterator (not pair like set)
    auto it1 = ms.insert(10);
    std::cout << "Inserted 10 at position: " << std::distance(ms.begin(), it1) << std::endl;

    auto it2 = ms.insert(10);  // Duplicate allowed
    std::cout << "Inserted 10 again at position: " << std::distance(ms.begin(), it2) << std::endl;

    ms.insert(10);
    ms.insert(20);
    ms.insert(20);
    ms.insert(30);

    std::cout << "Multiset: ";
    for (int v : ms) std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "Count of 10: " << ms.count(10) << std::endl;
    std::cout << "Count of 20: " << ms.count(20) << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 3: Counting Operations
 * @complexity Time: O(log n + k) where k is count
 */
void example3_CountingOperations() {
    std::cout << "--- Counting Operations ---" << std::endl;

    std::multiset<char> letters = {'a', 'b', 'a', 'c', 'b', 'a', 'd', 'b'};

    std::cout << "Letters: ";
    for (char c : letters) std::cout << c << " ";
    std::cout << std::endl;

    // Count each unique letter
    std::cout << "\nFrequencies:" << std::endl;
    auto it = letters.begin();
    while (it != letters.end()) {
        char current = *it;
        size_t count = letters.count(current);
        std::cout << "'" << current << "': " << count << std::endl;

        // Skip all occurrences of current
        std::advance(it, count);
    }

    std::cout << std::endl;
}

/**
 * @brief Example 4: Equal Range
 * @complexity Time: O(log n)
 */
void example4_EqualRange() {
    std::cout << "--- Equal Range ---" << std::endl;

    std::multiset<int> ms = {1, 2, 2, 2, 3, 4, 5, 5};

    std::cout << "Multiset: ";
    for (int v : ms) std::cout << v << " ";
    std::cout << std::endl;

    // equal_range returns pair of iterators [lower_bound, upper_bound)
    auto [first, last] = ms.equal_range(2);

    std::cout << "\nAll occurrences of 2: ";
    for (auto it = first; it != last; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Count using distance
    std::cout << "Count of 2 using distance: " << std::distance(first, last) << std::endl;

    // For value that doesn't exist
    auto [first2, last2] = ms.equal_range(10);
    std::cout << "Range for 10 (not in set): " << (first2 == last2 ? "empty" : "not empty") << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 5: Erase Operations
 * @complexity Time: O(log n + k) where k is elements erased
 */
void example5_EraseOperations() {
    std::cout << "--- Erase Operations ---" << std::endl;

    std::multiset<int> ms = {1, 2, 2, 2, 3, 4, 5, 5, 6};

    std::cout << "Initial: ";
    for (int v : ms) std::cout << v << " ";
    std::cout << " (size: " << ms.size() << ")" << std::endl;

    // Erase by value - removes ALL occurrences
    size_t erased = ms.erase(2);
    std::cout << "After erase(2) - removed " << erased << " elements: ";
    for (int v : ms) std::cout << v << " ";
    std::cout << std::endl;

    // Erase single element by iterator
    auto it = ms.find(5);
    if (it != ms.end()) {
        ms.erase(it);  // Removes only one occurrence
        std::cout << "After erasing one occurrence of 5: ";
        for (int v : ms) std::cout << v << " ";
        std::cout << std::endl;
    }

    // Erase range
    auto first = ms.find(4);
    auto last = ms.find(6);
    ms.erase(first, last);
    std::cout << "After erasing range [4, 6): ";
    for (int v : ms) std::cout << v << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Real-World - Word Frequency Counter
 * @complexity Time: O(n log m) where n = words, m = unique words
 */
void example6_FrequencyCounter() {
    std::cout << "--- Word Frequency Counter ---" << std::endl;

    std::string text = "the quick brown fox jumps over the lazy dog the fox jumps";
    std::multiset<std::string> words;

    // Tokenize
    std::string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.insert(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.insert(word);
    }

    std::cout << "Text: " << text << std::endl;
    std::cout << "\nWord frequencies (alphabetically):" << std::endl;

    // Display unique words with counts
    auto it = words.begin();
    while (it != words.end()) {
        std::string current = *it;
        size_t count = words.count(current);
        std::cout << "'" << current << "': " << count << std::endl;
        std::advance(it, count);
    }

    std::cout << "\nTotal words: " << words.size() << std::endl;

    // Find most frequent word
    size_t maxCount = 0;
    std::string mostFrequent;
    it = words.begin();
    while (it != words.end()) {
        std::string current = *it;
        size_t count = words.count(current);
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = current;
        }
        std::advance(it, count);
    }

    std::cout << "Most frequent word: '" << mostFrequent << "' (" << maxCount << " times)" << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "   STL Multiset Comprehensive Examples  " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_DuplicateHandling();
    example3_CountingOperations();
    example4_EqualRange();
    example5_EraseOperations();
    example6_FrequencyCounter();

    std::cout << "========================================" << std::endl;
    std::cout << "  All multiset examples completed!      " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 MultisetExample.cpp -o MultisetExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 MultisetExample.cpp -o MultisetExample
 *
 * Run:
 *   ./MultisetExample       (Linux/Mac)
 *   .\MultisetExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. Multiset allows duplicate elements while maintaining sorted order
 * 2. count() returns number of occurrences - O(log n + k)
 * 3. equal_range() efficiently finds all duplicates
 * 4. erase(value) removes ALL occurrences, erase(iterator) removes one
 * 5. Perfect for frequency counting with ordering
 * 6. Use when you need sorted collection with duplicates
 */

