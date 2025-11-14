/**
 * @file HashTableImplementation.cpp
 * @brief Simple open addressing hash table (linear probing).
 * @date 2025-11-15
 */

#include <iostream>
#include <vector>
#include <optional>

class HashTable {
    struct Entry { int key; bool occupied=false; };
    std::vector<Entry> table;
    std::size_t count = 0;
    std::size_t hash(int k) const { return static_cast<std::size_t>(k) % table.size(); }
public:
    explicit HashTable(std::size_t cap = 11) : table(cap) {}
    bool insert(int k) {
        if (count == table.size()) return false;
        std::size_t idx = hash(k);
        while (table[idx].occupied) idx = (idx + 1) % table.size();
        table[idx].key = k; table[idx].occupied = true; ++count; return true;
    }
    bool contains(int k) const {
        std::size_t idx = hash(k);
        std::size_t start = idx;
        while (table[idx].occupied) {
            if (table[idx].key == k) return true;
            idx = (idx + 1) % table.size();
            if (idx == start) break;
        }
        return false;
    }
};

int main() {
    HashTable ht;
    for (int k : {5,16,27,38}) ht.insert(k);
    std::cout << "Contains 16? " << ht.contains(16) << '\n';
    std::cout << "Contains 99? " << ht.contains(99) << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 HashTableImplementation.cpp -o HashTableImplementation */

