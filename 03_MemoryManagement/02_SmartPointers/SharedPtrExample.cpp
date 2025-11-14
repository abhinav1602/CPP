/**
 * @file SharedPtrExample.cpp
 * @brief Demonstrates std::shared_ptr reference counting, cycles, and weak_ptr fix.
 * @date 2025-11-15
 */

#include <iostream>
#include <memory>
#include <vector>

struct Node {
    int value;
    std::shared_ptr<Node> next;         // Creates potential cycle risk in other designs
    std::weak_ptr<Node>  prev;         // Use weak_ptr to break cycles
    explicit Node(int v) : value(v) {}
    ~Node() { std::cout << "Node(" << value << ") destroyed\n"; }
};

int main() {
    std::cout << "=== shared_ptr & weak_ptr Examples ===\n\n";

    // Basic shared_ptr
    auto a = std::make_shared<Node>(1);
    auto b = std::make_shared<Node>(2);
    a->next = b;
    b->prev = a; // weak_ptr prevents cycle keeping both alive forever

    std::cout << "a.use_count=" << a.use_count() << ", b.use_count=" << b.use_count() << '\n';

    // Vector of shared_ptrs
    std::vector<std::shared_ptr<Node>> nodes;
    for (int i = 3; i <= 5; ++i) {
        nodes.push_back(std::make_shared<Node>(i));
    }
    std::cout << "Vector populated, last node use_count=" << nodes.back().use_count() << '\n';

    // Reset one
    nodes[0].reset();
    std::cout << "After reset first element, nodes[1] use_count=" << nodes[1].use_count() << '\n';

    std::cout << "\n=== End shared_ptr examples ===\n";
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 SharedPtrExample.cpp -o SharedPtrExample */

