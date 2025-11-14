/**
 * @file StructuredBindingsExample.cpp
 * @brief Demonstrates structured bindings (C++17) with pairs, tuples, arrays, and custom structs.
 * @date 2025-11-15
 */

#include <iostream>
#include <tuple>
#include <array>
#include <utility>

struct Point { int x; int y; };

Point makePoint() { return {10, 20}; }

int main() {
    std::pair<int,std::string> p{1,"one"};
    auto [id, name] = p; // structured binding
    std::cout << "pair -> id=" << id << ", name=" << name << '\n';

    std::tuple<int,double,char> t{42,3.14,'Z'};
    auto [a,b,c] = t;
    std::cout << "tuple -> a=" << a << ", b=" << b << ", c=" << c << '\n';

    std::array<int,3> arr{5,6,7};
    auto [x,y,z] = arr;
    std::cout << "array -> x=" << x << ", y=" << y << ", z=" << z << '\n';

    auto [px,py] = makePoint();
    std::cout << "Point -> x=" << px << ", y=" << py << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 StructuredBindingsExample.cpp -o StructuredBindingsExample */

