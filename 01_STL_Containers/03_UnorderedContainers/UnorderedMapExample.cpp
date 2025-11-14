/**
 * @file UnorderedMapExample.cpp
 * @brief Comprehensive examples of std::unordered_map usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Hash-based map with O(1) average operations
 * - Fast key-value lookups
 * - Custom hash functions
 * - Real-world caching use case
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

void example1_BasicOperations();
void example2_ElementAccess();
void example3_HashBuckets();
void example4_CustomHash();
void example5_FrequencyCounter();
void example6_SimpleCache();

void example1_BasicOperations() {
    std::cout << "--- Basic Operations ---" << std::endl;

    std::unordered_map<std::string, int> ages;
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages.insert({"Charlie", 35});
    ages.emplace("Diana", 28);

    std::cout << "Map (unordered): ";
    for (const auto& [name, age] : ages) {
        std::cout << "{" << name << ":" << age << "} ";
    }
    std::cout << std::endl;

    if (ages.find("Bob") != ages.end()) {
        std::cout << "Found Bob, age: " << ages["Bob"] << std::endl;
    }

    std::cout << "Size: " << ages.size() << std::endl;
    std::cout << std::endl;
}

void example2_ElementAccess() {
    std::cout << "--- Element Access ---" << std::endl;

    std::unordered_map<std::string, int> scores = {{"Math", 90}, {"Science", 85}};

    std::cout << "Math: " << scores["Math"] << std::endl;
    std::cout << "English (creates with 0): " << scores["English"] << std::endl;
    std::cout << "Size after []: " << scores.size() << std::endl;

    try {
        std::cout << "Science: " << scores.at("Science") << std::endl;
        scores.at("History");  // Throws
    } catch (const std::out_of_range& e) {
        std::cout << "History not found (exception)" << std::endl;
    }

    std::cout << std::endl;
}

void example3_HashBuckets() {
    std::cout << "--- Hash and Buckets ---" << std::endl;

    std::unordered_map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

    std::cout << "Buckets: " << map.bucket_count() << std::endl;
    std::cout << "Load factor: " << map.load_factor() << std::endl;
    std::cout << "Max load factor: " << map.max_load_factor() << std::endl;

    for (const auto& [key, val] : map) {
        std::cout << "Key " << key << " is in bucket " << map.bucket(key) << std::endl;
    }

    std::cout << std::endl;
}

void example4_CustomHash() {
    std::cout << "--- Custom Hash ---" << std::endl;

    struct Pair {
        int x, y;
        bool operator==(const Pair& other) const {
            return x == other.x && y == other.y;
        }
    };

    struct PairHash {
        size_t operator()(const Pair& p) const {
            return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
        }
    };

    std::unordered_map<Pair, std::string, PairHash> map;
    map[{1, 2}] = "Point A";
    map[{3, 4}] = "Point B";

    std::cout << "Custom hash map size: " << map.size() << std::endl;
    std::cout << "Value at (1,2): " << map[{1, 2}] << std::endl;

    std::cout << std::endl;
}

void example5_FrequencyCounter() {
    std::cout << "--- Word Frequency Counter ---" << std::endl;

    std::string text = "the quick brown fox jumps over the lazy dog the fox";
    std::unordered_map<std::string, int> freq;

    std::string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                freq[word]++;
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) freq[word]++;

    std::cout << "Word frequencies:" << std::endl;
    for (const auto& [w, count] : freq) {
        std::cout << "'" << w << "': " << count << std::endl;
    }

    std::cout << std::endl;
}

void example6_SimpleCache() {
    std::cout << "--- Simple Cache ---" << std::endl;

    std::unordered_map<int, int> cache;  // Fibonacci cache

    auto fib = [&](int n, auto& fib_ref) -> int {
        if (n <= 1) return n;

        if (cache.count(n)) {
            std::cout << "Cache hit for fib(" << n << ")" << std::endl;
            return cache[n];
        }

        std::cout << "Computing fib(" << n << ")" << std::endl;
        int result = fib_ref(n-1, fib_ref) + fib_ref(n-2, fib_ref);
        cache[n] = result;
        return result;
    };

    std::cout << "fib(10) = " << fib(10, fib) << std::endl;
    std::cout << "\nCache size: " << cache.size() << std::endl;
    std::cout << "Computing fib(10) again:" << std::endl;
    std::cout << "fib(10) = " << fib(10, fib) << std::endl;

    std::cout << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << " STL Unordered Map Comprehensive Examples" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_ElementAccess();
    example3_HashBuckets();
    example4_CustomHash();
    example5_FrequencyCounter();
    example6_SimpleCache();

    std::cout << "========================================" << std::endl;
    std::cout << "  All unordered_map examples completed! " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 UnorderedMapExample.cpp -o UnorderedMapExample
 *
 * Key Takeaways:
 * 1. O(1) average lookup/insert/delete
 * 2. operator[] creates element if missing
 * 3. at() throws for missing keys
 * 4. Perfect for caching, frequency counting
 * 5. Custom hash needed for custom types
 */

