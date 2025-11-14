/**
 * @file SpecializationExample.cpp
 * @brief Template Specialization
 * @date 2025-11-15
 */

#include <iostream>
template<typename T>
class Printer {
public:
    void print(T value) { std::cout << value << std::endl; }
};

template<>
class Printer<bool> {
public:
    void print(bool value) { std::cout << (value ? "true" : "false") << std::endl; }
};

int main() {
    Printer<int> pi;
    Printer<bool> pb;
    pi.print(42);
    pb.print(true);
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 SpecializationExample.cpp -o  */
