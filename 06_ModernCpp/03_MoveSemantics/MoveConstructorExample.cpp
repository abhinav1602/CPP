/**
 * @file MoveConstructorExample.cpp
 * @brief Demonstrates user-defined move constructor performance.
 * @date 2025-11-15
 */
#include <iostream>
#include <utility>
#include <vector>

class Buffer {
    std::vector<int> data;
public:
    Buffer(){ std::cout<<"default ctor\n"; }
    explicit Buffer(int n):data(n){ std::cout<<"size ctor\n"; }
    Buffer(const Buffer& o):data(o.data){ std::cout<<"copy ctor\n"; }
    Buffer(Buffer&& o) noexcept : data(std::move(o.data)){ std::cout<<"move ctor\n"; }
};

int main(){ Buffer a(1000); Buffer b = a; Buffer c = std::move(a); return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 MoveConstructorExample.cpp -o MoveConstructorExample */
