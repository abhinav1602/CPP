/**
 * @file ClassTemplateExample.cpp
 * @brief Class Templates
 * @date 2025-11-15
 */

#include <iostream>
template<typename T>
class Container {
    T value;
public:
    Container(T v) : value(v) {}
    T get() const { return value; }
};

int main() {
    Container<int> ci(42);
    Container<double> cd(3.14);
    std::cout << "Int: " << ci.get() << ", Double: " << cd.get() << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 ClassTemplateExample.cpp -o  */
