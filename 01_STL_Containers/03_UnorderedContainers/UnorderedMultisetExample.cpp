/**
 * @file UnorderedMultisetExample.cpp
 * @brief Examples of std::unordered_multiset usage
 * @date 2025-11-14
 */

#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::cout << "=== Unordered Multiset Examples ===" << std::endl << std::endl;

    // Basic operations - allows duplicates
    std::unordered_multiset<int> ums = {1, 2, 2, 3, 3, 3, 4};

    std::cout << "Multiset (unordered, with duplicates): ";
    for (int v : ums) std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "Size: " << ums.size() << std::endl;
    std::cout << "Count of 3: " << ums.count(3) << std::endl;

    // Insert more duplicates
    ums.insert(2);
    ums.insert(2);
    std::cout << "\nAfter inserting two more 2s:" << std::endl;
    std::cout << "Count of 2: " << ums.count(2) << std::endl;

    // equal_range - find all occurrences
    auto [first, last] = ums.equal_range(3);
    std::cout << "\nAll occurrences of 3: ";
    for (auto it = first; it != last; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Erase by value - removes ALL occurrences
    size_t erased = ums.erase(2);
    std::cout << "\nErased " << erased << " occurrences of 2" << std::endl;
    std::cout << "New size: " << ums.size() << std::endl;

    // Erase single element by iterator
    auto it = ums.find(3);
    if (it != ums.end()) {
        ums.erase(it);  // Removes only one
        std::cout << "Erased one occurrence of 3" << std::endl;
        std::cout << "Count of 3 now: " << ums.count(3) << std::endl;
    }

    std::cout << "\n=== All examples completed ===" << std::endl;
    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 UnorderedMultisetExample.cpp -o UnorderedMultisetExample
 *
 * Key Takeaways:
 * 1. Allows duplicate elements (like multiset)
 * 2. No ordering (like unordered_set)
 * 3. O(1) average for operations
 * 4. erase(value) removes ALL, erase(iterator) removes one
 * 5. Use for fast duplicate counting without order
 */

