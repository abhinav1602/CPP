/**
 * @file TrieImplementation.cpp
 * @brief Basic Trie (prefix tree) insert & search.
 * @date 2025-11-15
 */

#include <iostream>
#include <array>
#include <string>
#include <memory>

struct TrieNode {
    std::array<std::unique_ptr<TrieNode>,26> children{};
    bool terminal = false;
};

class Trie {
    std::unique_ptr<TrieNode> root = std::make_unique<TrieNode>();
public:
    void insert(const std::string& word) {
        TrieNode* node = root.get();
        for (char ch : word) {
            if (ch < 'a' || ch > 'z') continue;
            std::size_t idx = static_cast<std::size_t>(ch - 'a');
            if (!node->children[idx]) node->children[idx] = std::make_unique<TrieNode>();
            node = node->children[idx].get();
        }
        node->terminal = true;
    }
    bool contains(const std::string& word) const {
        const TrieNode* node = root.get();
        for (char ch : word) {
            if (ch < 'a' || ch > 'z') return false;
            std::size_t idx = static_cast<std::size_t>(ch - 'a');
            if (!node->children[idx]) return false;
            node = node->children[idx].get();
        }
        return node->terminal;
    }
};

int main() {
    Trie t;
    t.insert("hello");
    t.insert("help");
    std::cout << "Contains 'hello'? " << t.contains("hello") << '\n';
    std::cout << "Contains 'hel'? " << t.contains("hel") << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 TrieImplementation.cpp -o TrieImplementation */

