/**
 * @file UnorderedMultimapExample.cpp
 * @brief Examples of std::unordered_multimap usage
 * @date 2025-11-14
 */

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::cout << "=== Unordered Multimap Examples ===" << std::endl << std::endl;

    // Basic operations - allows duplicate keys
    std::unordered_multimap<std::string, int> umm;

    umm.insert({"Alice", 555-1234});
    umm.insert({"Alice", 555-5678});  // Duplicate key OK
    umm.insert({"Bob", 555-8765});
    umm.insert({"Alice", 555-9999});  // Another duplicate

    std::cout << "Multimap contents:" << std::endl;
    for (const auto& [name, phone] : umm) {
        std::cout << name << ": " << phone << std::endl;
    }

    std::cout << "\nCount of 'Alice': " << umm.count("Alice") << std::endl;

    // equal_range - find all values for a key
    std::cout << "\nAll phone numbers for Alice:" << std::endl;
    auto [first, last] = umm.equal_range("Alice");
    for (auto it = first; it != last; ++it) {
        std::cout << "  " << it->second << std::endl;
    }

    // Erase by key - removes ALL values for that key
    size_t erased = umm.erase("Alice");
    std::cout << "\nErased " << erased << " entries for Alice" << std::endl;
    std::cout << "New size: " << umm.size() << std::endl;

    // Add more data
    umm.insert({"Charlie", 555-1111});
    umm.insert({"Charlie", 555-2222});

    // Erase single entry by iterator
    auto it = umm.find("Charlie");
    if (it != umm.end()) {
        umm.erase(it);  // Removes only one
        std::cout << "\nErased one entry for Charlie" << std::endl;
        std::cout << "Count of 'Charlie': " << umm.count("Charlie") << std::endl;
    }

    std::cout << "\n=== All examples completed ===" << std::endl;
    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 UnorderedMultimapExample.cpp -o UnorderedMultimapExample
 *
 * Key Takeaways:
 * 1. Allows multiple values per key (like multimap)
 * 2. No ordering (like unordered_map)
 * 3. O(1) average for operations
 * 4. equal_range() to find all values for a key
 * 5. erase(key) removes ALL, erase(iterator) removes one
 * 6. Use for one-to-many relationships with fast access
 */

