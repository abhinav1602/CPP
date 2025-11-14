/**
 * @file UniquePtrExample.cpp
 * @brief Demonstrates std::unique_ptr ownership transfer, custom deleter, arrays.
 * @date 2025-11-15
 */

#include <iostream>
#include <memory>
#include <utility>

struct Widget {
    int id;
    explicit Widget(int i) : id(i) { std::cout << "Widget(" << id << ") constructed\n"; }
    ~Widget() { std::cout << "Widget(" << id << ") destroyed\n"; }
};

int main() {
    std::cout << "=== unique_ptr Examples ===\n\n";

    // Basic unique_ptr
    std::unique_ptr<Widget> w1 = std::make_unique<Widget>(1);
    std::cout << "w1->id=" << w1->id << '\n';

    // Transfer ownership via std::move
    std::unique_ptr<Widget> w2 = std::move(w1);
    std::cout << "Ownership moved: w1 is " << (w1 ? "not null" : "null") << ", w2->id=" << w2->id << '\n';

    // Custom deleter
    std::unique_ptr<Widget, void(*)(Widget*)> w3(new Widget(3), [](Widget* p){
        std::cout << "Custom deleter invoked for Widget(" << p->id << ")\n";
        delete p;
    });

    // unique_ptr for dynamic arrays (C++23 removed implicit .get()[i] indexing for some types)
    std::unique_ptr<int[]> arr(new int[5]);
    for (int i = 0; i < 5; ++i) arr[i] = i * 10;
    std::cout << "Array contents: ";
    for (int i = 0; i < 5; ++i) std::cout << arr[i] << ' ';
    std::cout << '\n';

    std::cout << "\n=== End unique_ptr examples ===\n";
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 UniquePtrExample.cpp -o UniquePtrExample */

