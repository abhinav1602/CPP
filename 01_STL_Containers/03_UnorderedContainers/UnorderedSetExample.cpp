/**
 * @file UnorderedSetExample.cpp
 * @brief Comprehensive examples of std::unordered_set usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Hash-based set with O(1) average operations
 * - Bucket interface and load factor
 * - Custom hash functions
 * - Comparison with std::set
 */

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

void example1_BasicOperations();
void example2_HashAndBuckets();
void example3_LoadFactorRehash();
void example4_CustomHashFunction();
void example5_ComparisonWithSet();
void example6_DuplicateDetection();

/**
 * @brief Example 1: Basic Unordered Set Operations
 * @complexity Time: O(1) average for insert/find/erase
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Unordered Set Operations ---" << std::endl;

    std::unordered_set<int> us = {5, 2, 8, 1, 9};  // No specific order

    std::cout << "Unordered set: ";
    for (int val : us) std::cout << val << " ";
    std::cout << " (no guaranteed order)" << std::endl;

    // Insert
    auto [it, inserted] = us.insert(3);
    std::cout << "Insert 3: " << (inserted ? "success" : "failed") << std::endl;

    us.insert(5);  // Duplicate
    std::cout << "Insert 5 (duplicate): ignored" << std::endl;

    // Find - O(1) average
    if (us.find(8) != us.end()) {
        std::cout << "Found 8 in set" << std::endl;
    }

    // Count
    std::cout << "Count of 9: " << us.count(9) << std::endl;

    // Erase
    us.erase(2);
    std::cout << "After erasing 2: ";
    for (int val : us) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: Hash and Buckets
 * @complexity Time: O(1) average
 */
void example2_HashAndBuckets() {
    std::cout << "--- Hash and Buckets ---" << std::endl;

    std::unordered_set<std::string> words = {"apple", "banana", "cherry", "date"};

    std::cout << "Number of buckets: " << words.bucket_count() << std::endl;
    std::cout << "Max buckets: " << words.max_bucket_count() << std::endl;
    std::cout << "Load factor: " << words.load_factor() << std::endl;
    std::cout << "Max load factor: " << words.max_load_factor() << std::endl;

    std::cout << "\nBucket distribution:" << std::endl;
    for (size_t i = 0; i < words.bucket_count(); ++i) {
        if (words.bucket_size(i) > 0) {
            std::cout << "Bucket " << i << ": " << words.bucket_size(i) << " elements" << std::endl;
        }
    }

    // Which bucket contains a key
    std::cout << "\n'apple' is in bucket: " << words.bucket("apple") << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 3: Load Factor and Rehashing
 * @complexity Time: O(n) for rehash
 */
void example3_LoadFactorRehash() {
    std::cout << "--- Load Factor and Rehashing ---" << std::endl;

    std::unordered_set<int> us;

    std::cout << "Initial buckets: " << us.bucket_count() << std::endl;

    // Add many elements
    for (int i = 0; i < 20; ++i) {
        us.insert(i);
        if (i % 5 == 0) {
            std::cout << "After " << i << " inserts: "
                      << "buckets=" << us.bucket_count()
                      << ", load=" << us.load_factor() << std::endl;
        }
    }

    // Manual rehash
    std::cout << "\nBefore rehash: " << us.bucket_count() << " buckets" << std::endl;
    us.rehash(50);
    std::cout << "After rehash(50): " << us.bucket_count() << " buckets" << std::endl;
    std::cout << "New load factor: " << us.load_factor() << std::endl;

    // Reserve
    us.reserve(100);  // Reserves space for 100 elements
    std::cout << "After reserve(100): " << us.bucket_count() << " buckets" << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 4: Custom Hash Function
 * @complexity Time: O(1) average
 */
void example4_CustomHashFunction() {
    std::cout << "--- Custom Hash Function ---" << std::endl;

    struct Point {
        int x, y;
        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
    };

    struct PointHash {
        size_t operator()(const Point& p) const {
            // Combine hash values
            return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
        }
    };

    std::unordered_set<Point, PointHash> points;

    points.insert({1, 2});
    points.insert({3, 4});
    points.insert({1, 2});  // Duplicate

    std::cout << "Points in set: " << points.size() << std::endl;

    Point search = {3, 4};
    if (points.find(search) != points.end()) {
        std::cout << "Found point (3, 4)" << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 5: Comparison with std::set
 * @complexity Time: varies
 */
void example5_ComparisonWithSet() {
    std::cout << "--- Comparison with std::set ---" << std::endl;

    std::cout << "unordered_set vs set:" << std::endl;
    std::cout << "\nunordered_set:" << std::endl;
    std::cout << "+ O(1) average search/insert/delete" << std::endl;
    std::cout << "+ Faster for pure lookups" << std::endl;
    std::cout << "- No ordering" << std::endl;
    std::cout << "- Higher memory usage" << std::endl;
    std::cout << "- Worst case O(n)" << std::endl;

    std::cout << "\nset:" << std::endl;
    std::cout << "+ Sorted order maintained" << std::endl;
    std::cout << "+ Predictable O(log n)" << std::endl;
    std::cout << "+ Range queries (lower/upper_bound)" << std::endl;
    std::cout << "- Slower than hash for lookups" << std::endl;

    std::cout << "\nUse unordered_set when:" << std::endl;
    std::cout << "- Order doesn't matter" << std::endl;
    std::cout << "- Need fastest possible lookups" << std::endl;
    std::cout << "- No range queries needed" << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Duplicate Detection
 * @complexity Time: O(n) average
 */
void example6_DuplicateDetection() {
    std::cout << "--- Duplicate Detection ---" << std::endl;

    std::vector<int> data = {1, 2, 3, 2, 4, 5, 3, 6, 1, 7};
    std::unordered_set<int> seen;
    std::vector<int> duplicates;

    std::cout << "Data: ";
    for (int val : data) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "\nDetecting duplicates:" << std::endl;
    for (int val : data) {
        if (seen.count(val)) {
            std::cout << "Duplicate found: " << val << std::endl;
            duplicates.push_back(val);
        } else {
            seen.insert(val);
        }
    }

    std::cout << "\nUnique elements: " << seen.size() << std::endl;
    std::cout << "Duplicates found: " << duplicates.size() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << " STL Unordered Set Comprehensive Examples" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_HashAndBuckets();
    example3_LoadFactorRehash();
    example4_CustomHashFunction();
    example5_ComparisonWithSet();
    example6_DuplicateDetection();

    std::cout << "========================================" << std::endl;
    std::cout << "  All unordered_set examples completed! " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 UnorderedSetExample.cpp -o UnorderedSetExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 UnorderedSetExample.cpp -o UnorderedSetExample
 *
 * Run:
 *   ./UnorderedSetExample       (Linux/Mac)
 *   .\UnorderedSetExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. unordered_set uses hash table for O(1) average operations
 * 2. No ordering - elements stored by hash value
 * 3. Need custom hash function for custom types
 * 4. Monitor load factor for performance
 * 5. Use when speed > ordering
 * 6. Perfect for existence checks, duplicate detection
 */

