/**
 * @file MapExample.cpp
 * @brief Comprehensive examples of std::map usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Key-value pair storage with ordering
 * - Fast O(log n) lookup by key
 * - Automatic sorting by keys
 * - Various access methods
 * - Real-world applications
 */

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

void example1_BasicOperations();
void example2_ElementAccess();
void example3_InsertAndErase();
void example4_FindAndCount();
void example5_Iteration();
void example6_CustomComparator();
void example7_WordFrequencyCounter();

/**
 * @brief Example 1: Basic Map Operations
 * @complexity Time: O(log n) for insert
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Map Operations ---" << std::endl;

    std::map<std::string, int> ages;

    // Different ways to insert
    ages["Alice"] = 25;
    ages.insert({"Bob", 30});
    ages.insert(std::make_pair("Charlie", 35));
    ages.emplace("Diana", 28);

    std::cout << "Map contents (sorted by key):" << std::endl;
    for (const auto& [name, age] : ages) {
        std::cout << name << ": " << age << " years" << std::endl;
    }

    std::cout << "Size: " << ages.size() << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Example 2: Element Access
 * @complexity Time: O(log n)
 */
void example2_ElementAccess() {
    std::cout << "--- Element Access ---" << std::endl;

    std::map<std::string, int> scores = {
        {"Math", 90},
        {"Science", 85},
        {"English", 92}
    };

    // operator[] - creates element if doesn't exist
    std::cout << "Math score: " << scores["Math"] << std::endl;
    std::cout << "History score (new): " << scores["History"] << std::endl;  // Creates with 0
    std::cout << "Map size after operator[]: " << scores.size() << std::endl;

    // at() - throws exception if doesn't exist
    try {
        std::cout << "Science score: " << scores.at("Science") << std::endl;
        std::cout << "Geography score: " << scores.at("Geography") << std::endl;  // Throws
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 3: Insert and Erase
 * @complexity Time: O(log n)
 */
void example3_InsertAndErase() {
    std::cout << "--- Insert and Erase ---" << std::endl;

    std::map<int, std::string> map;

    // insert returns pair<iterator, bool>
    auto [it1, success1] = map.insert({1, "one"});
    std::cout << "Insert {1, one}: " << (success1 ? "success" : "failed") << std::endl;

    auto [it2, success2] = map.insert({1, "ONE"});  // Duplicate key
    std::cout << "Insert {1, ONE}: " << (success2 ? "success" : "failed") << std::endl;
    std::cout << "Value at key 1: " << map[1] << std::endl;  // Still "one"

    map.insert({{2, "two"}, {3, "three"}, {4, "four"}});

    std::cout << "Map: ";
    for (const auto& [k, v] : map) {
        std::cout << "{" << k << ":" << v << "} ";
    }
    std::cout << std::endl;

    // Erase by key
    size_t erased = map.erase(2);
    std::cout << "Erased " << erased << " element(s)" << std::endl;

    // Erase by iterator
    auto it = map.find(3);
    if (it != map.end()) {
        map.erase(it);
    }

    std::cout << "After erasing: ";
    for (const auto& [k, v] : map) {
        std::cout << "{" << k << ":" << v << "} ";
    }
    std::cout << std::endl << std::endl;
}

/**
 * @brief Example 4: Find and Count
 * @complexity Time: O(log n)
 */
void example4_FindAndCount() {
    std::cout << "--- Find and Count ---" << std::endl;

    std::map<std::string, double> prices = {
        {"apple", 0.50},
        {"banana", 0.30},
        {"orange", 0.60}
    };

    // find
    auto it = prices.find("banana");
    if (it != prices.end()) {
        std::cout << "Found: " << it->first << " costs $" << it->second << std::endl;
    }

    if (prices.find("grape") == prices.end()) {
        std::cout << "Grape not found" << std::endl;
    }

    // count (returns 0 or 1 for map)
    std::cout << "Contains apple? " << (prices.count("apple") ? "yes" : "no") << std::endl;
    std::cout << "Contains grape? " << (prices.count("grape") ? "yes" : "no") << std::endl;

    // C++20: contains()
    // std::cout << "Contains apple? " << (prices.contains("apple") ? "yes" : "no") << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 5: Iteration Methods
 * @complexity Time: O(n) for full iteration
 */
void example5_Iteration() {
    std::cout << "--- Iteration Methods ---" << std::endl;

    std::map<int, std::string> map = {{3, "three"}, {1, "one"}, {2, "two"}};

    // Range-based for with structured bindings (C++17)
    std::cout << "Structured bindings: ";
    for (const auto& [key, value] : map) {
        std::cout << "{" << key << ":" << value << "} ";
    }
    std::cout << std::endl;

    // Traditional iterator
    std::cout << "Iterator: ";
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << "{" << it->first << ":" << it->second << "} ";
    }
    std::cout << std::endl;

    // Reverse iteration
    std::cout << "Reverse: ";
    for (auto it = map.rbegin(); it != map.rend(); ++it) {
        std::cout << "{" << it->first << ":" << it->second << "} ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Custom Comparator
 * @complexity Time: O(log n)
 */
void example6_CustomComparator() {
    std::cout << "--- Custom Comparator ---" << std::endl;

    // Descending order
    std::map<int, std::string, std::greater<int>> descMap = {
        {1, "one"}, {5, "five"}, {3, "three"}, {2, "two"}
    };

    std::cout << "Descending by key: ";
    for (const auto& [k, v] : descMap) {
        std::cout << "{" << k << ":" << v << "} ";
    }
    std::cout << std::endl;

    // Custom comparator for strings (case-insensitive)
    auto caseInsensitiveCmp = [](const std::string& a, const std::string& b) {
        return std::lexicographical_compare(
            a.begin(), a.end(), b.begin(), b.end(),
            [](char c1, char c2) { return std::tolower(c1) < std::tolower(c2); }
        );
    };

    std::map<std::string, int, decltype(caseInsensitiveCmp)> caseInsensitiveMap(caseInsensitiveCmp);
    caseInsensitiveMap["apple"] = 1;
    caseInsensitiveMap["Banana"] = 2;
    caseInsensitiveMap["CHERRY"] = 3;

    std::cout << "Case-insensitive keys: ";
    for (const auto& [k, v] : caseInsensitiveMap) {
        std::cout << "{" << k << ":" << v << "} ";
    }
    std::cout << std::endl << std::endl;
}

/**
 * @brief Example 7: Real-World Use Case - Word Frequency Counter
 * @complexity Time: O(n log m) where n = words, m = unique words
 */
void example7_WordFrequencyCounter() {
    std::cout << "--- Word Frequency Counter ---" << std::endl;

    std::string text = "the quick brown fox jumps over the lazy dog the fox";
    std::map<std::string, int> wordCount;

    // Tokenize and count
    std::string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                wordCount[word]++;
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        wordCount[word]++;
    }

    std::cout << "Word frequencies (alphabetically):" << std::endl;
    for (const auto& [word, count] : wordCount) {
        std::cout << word << ": " << count << std::endl;
    }

    // Find most frequent word
    auto maxIt = std::max_element(wordCount.begin(), wordCount.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

    if (maxIt != wordCount.end()) {
        std::cout << "\nMost frequent word: '" << maxIt->first
                  << "' (" << maxIt->second << " times)" << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "     STL Map Comprehensive Examples     " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_ElementAccess();
    example3_InsertAndErase();
    example4_FindAndCount();
    example5_Iteration();
    example6_CustomComparator();
    example7_WordFrequencyCounter();

    std::cout << "========================================" << std::endl;
    std::cout << "  All map examples completed!           " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 MapExample.cpp -o MapExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 MapExample.cpp -o MapExample
 *
 * Run:
 *   ./MapExample       (Linux/Mac)
 *   .\MapExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. Map stores key-value pairs in sorted order by key
 * 2. operator[] creates element if doesn't exist, at() throws
 * 3. All operations are O(log n)
 * 4. Keys are const - cannot be modified after insertion
 * 5. Use structured bindings for clean iteration (C++17)
 * 6. Great for dictionary/lookup operations with ordering
 */

