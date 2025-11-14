/**
 * @file MultimapExample.cpp
 * @brief Comprehensive examples of std::multimap usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Multiple values per key
 * - One-to-many relationships
 * - equal_range for finding all values for a key
 * - Real-world use cases
 */

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

void example1_BasicOperations();
void example2_MultipleValuesPerKey();
void example3_EqualRange();
void example4_Iteration();
void example5_EraseOperations();
void example6_PhoneBook();

/**
 * @brief Example 1: Basic Multimap Operations
 * @complexity Time: O(log n) for insert
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Multimap Operations ---" << std::endl;

    std::multimap<std::string, int> mm;

    // Insert multiple values for same key
    mm.insert({"apple", 1});
    mm.insert({"banana", 2});
    mm.insert({"apple", 3});  // Duplicate key allowed
    mm.insert({"apple", 5});  // Another duplicate
    mm.insert({"banana", 4});

    std::cout << "Multimap contents (sorted by key):" << std::endl;
    for (const auto& [key, value] : mm) {
        std::cout << key << ": " << value << std::endl;
    }

    std::cout << "Size: " << mm.size() << std::endl;
    std::cout << "Count of 'apple': " << mm.count("apple") << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: Multiple Values Per Key
 * @complexity Time: O(log n) for operations
 */
void example2_MultipleValuesPerKey() {
    std::cout << "--- Multiple Values Per Key ---" << std::endl;

    std::multimap<int, std::string> mm;

    // Year -> Event mapping (one-to-many)
    mm.insert({2020, "COVID-19 pandemic"});
    mm.insert({2020, "US election"});
    mm.insert({2021, "Tokyo Olympics"});
    mm.insert({2021, "Afghanistan withdrawal"});
    mm.insert({2020, "Brexit completed"});

    std::cout << "Historical events:" << std::endl;
    for (const auto& [year, event] : mm) {
        std::cout << year << ": " << event << std::endl;
    }

    std::cout << "\nNumber of 2020 events: " << mm.count(2020) << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 3: Equal Range - Finding All Values for a Key
 * @complexity Time: O(log n + k) where k is count
 */
void example3_EqualRange() {
    std::cout << "--- Equal Range ---" << std::endl;

    std::multimap<std::string, int> scores;
    scores.insert({"Alice", 90});
    scores.insert({"Bob", 85});
    scores.insert({"Alice", 95});
    scores.insert({"Charlie", 88});
    scores.insert({"Alice", 92});
    scores.insert({"Bob", 87});

    std::cout << "All scores:" << std::endl;
    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << std::endl;
    }

    // Find all scores for Alice
    std::cout << "\nAlice's scores:" << std::endl;
    auto [first, last] = scores.equal_range("Alice");
    for (auto it = first; it != last; ++it) {
        std::cout << "  " << it->second << std::endl;
    }

    // Calculate average for Alice
    int sum = 0;
    int count = 0;
    for (auto it = first; it != last; ++it) {
        sum += it->second;
        count++;
    }
    if (count > 0) {
        std::cout << "Alice's average: " << (sum / count) << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 4: Iteration Methods
 * @complexity Time: O(n) for full iteration
 */
void example4_Iteration() {
    std::cout << "--- Iteration Methods ---" << std::endl;

    std::multimap<int, std::string> mm = {
        {1, "one"}, {2, "two"}, {1, "uno"}, {3, "three"}, {2, "dos"}
    };

    // Range-based for with structured bindings
    std::cout << "All entries:" << std::endl;
    for (const auto& [key, value] : mm) {
        std::cout << "{" << key << ": " << value << "} ";
    }
    std::cout << std::endl;

    // Iterate over specific key
    std::cout << "\nAll values for key 1:" << std::endl;
    for (auto it = mm.lower_bound(1); it != mm.upper_bound(1); ++it) {
        std::cout << "  " << it->second << std::endl;
    }

    // Count unique keys
    int uniqueKeys = 0;
    auto it = mm.begin();
    while (it != mm.end()) {
        int currentKey = it->first;
        uniqueKeys++;
        // Skip all values for current key
        it = mm.upper_bound(currentKey);
    }
    std::cout << "\nUnique keys: " << uniqueKeys << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 5: Erase Operations
 * @complexity Time: O(log n + k) where k is elements erased
 */
void example5_EraseOperations() {
    std::cout << "--- Erase Operations ---" << std::endl;

    std::multimap<std::string, int> mm = {
        {"A", 1}, {"B", 2}, {"A", 3}, {"C", 4}, {"A", 5}
    };

    std::cout << "Initial: ";
    for (const auto& [k, v] : mm) {
        std::cout << "{" << k << ":" << v << "} ";
    }
    std::cout << " (size: " << mm.size() << ")" << std::endl;

    // Erase by key - removes ALL values for that key
    size_t erased = mm.erase("A");
    std::cout << "After erase('A') - removed " << erased << " pairs: ";
    for (const auto& [k, v] : mm) {
        std::cout << "{" << k << ":" << v << "} ";
    }
    std::cout << std::endl;

    // Add back some values
    mm.insert({"D", 6});
    mm.insert({"D", 7});
    mm.insert({"D", 8});

    // Erase single element by iterator
    auto it = mm.find("D");
    if (it != mm.end()) {
        mm.erase(it);  // Removes only one value
        std::cout << "After erasing one 'D' value: ";
        for (const auto& [k, v] : mm) {
            std::cout << "{" << k << ":" << v << "} ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 6: Real-World - Phone Book
 * @complexity Time: O(n log n) for construction
 */
void example6_PhoneBook() {
    std::cout << "--- Phone Book Application ---" << std::endl;

    std::multimap<std::string, std::string> phoneBook;

    // People can have multiple phone numbers
    phoneBook.insert({"Alice", "555-1234"});
    phoneBook.insert({"Alice", "555-5678"});
    phoneBook.insert({"Bob", "555-8765"});
    phoneBook.insert({"Charlie", "555-4321"});
    phoneBook.insert({"Alice", "555-9999"});
    phoneBook.insert({"Bob", "555-1111"});

    std::cout << "Complete phone book:" << std::endl;
    auto it = phoneBook.begin();
    while (it != phoneBook.end()) {
        std::string name = it->first;
        std::cout << name << ":" << std::endl;

        // Print all numbers for this person
        auto [first, last] = phoneBook.equal_range(name);
        for (auto numIt = first; numIt != last; ++numIt) {
            std::cout << "  " << numIt->second << std::endl;
        }

        // Move to next person
        it = last;
    }

    // Lookup specific person
    std::cout << "\nLooking up Alice's numbers:" << std::endl;
    auto range = phoneBook.equal_range("Alice");
    int count = 0;
    for (auto phoneIt = range.first; phoneIt != range.second; ++phoneIt) {
        count++;
        std::cout << "  Phone " << count << ": " << phoneIt->second << std::endl;
    }

    // Add new number
    std::cout << "\nAdding new number for Charlie..." << std::endl;
    phoneBook.insert({"Charlie", "555-7777"});

    std::cout << "Charlie's updated numbers:" << std::endl;
    auto charlieRange = phoneBook.equal_range("Charlie");
    for (auto it = charlieRange.first; it != charlieRange.second; ++it) {
        std::cout << "  " << it->second << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Multimap Comprehensive Examples   " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_MultipleValuesPerKey();
    example3_EqualRange();
    example4_Iteration();
    example5_EraseOperations();
    example6_PhoneBook();

    std::cout << "========================================" << std::endl;
    std::cout << "  All multimap examples completed!      " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 MultimapExample.cpp -o MultimapExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 MultimapExample.cpp -o MultimapExample
 *
 * Run:
 *   ./MultimapExample       (Linux/Mac)
 *   .\MultimapExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. Multimap allows multiple values per key (one-to-many)
 * 2. Keys are sorted, multiple values for same key stored together
 * 3. equal_range() efficiently finds all values for a key
 * 4. erase(key) removes ALL values, erase(iterator) removes one
 * 5. No operator[] (would be ambiguous with multiple values)
 * 6. Perfect for representing one-to-many relationships
 */

