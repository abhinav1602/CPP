/**
 * @file NoexceptExample.cpp
 * @brief Demonstrates noexcept specifier and conditional noexcept.
 * @date 2025-11-15
 */

#include <iostream>
#include <utility>
#include <vector>

struct Buffer {
    std::vector<int> data;
    // Move constructor declared noexcept improves performance in containers
    Buffer(Buffer&& other) noexcept : data(std::move(other.data)) {}
    Buffer() = default;
};

// Conditional noexcept - depends on underlying move
template<typename T>
void swapObjects(T& a, T& b) noexcept(noexcept(std::swap(a,b))) {
    using std::swap;
    swap(a,b);
}

int main() {
    std::cout << "=== noexcept Examples ===\n";
    Buffer b1; b1.data = {1,2,3};
    Buffer b2; b2.data = {4,5,6};
    swapObjects(b1,b2);
    std::cout << "b1 first=" << b1.data.front() << " b2 first=" << b2.data.front() << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 NoexceptExample.cpp -o NoexceptExample */

