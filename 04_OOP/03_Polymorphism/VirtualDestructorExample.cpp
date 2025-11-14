/**
 * @file VirtualDestructorExample.cpp
 * @brief Demonstrates importance of virtual destructor.
 * @date 2025-11-15
 */
#include <iostream>

struct Base { virtual ~Base(){ std::cout<<"Base dtor\n"; } };
struct Derived : Base { ~Derived(){ std::cout<<"Derived dtor\n"; } };

int main(){ Base* b = new Derived(); delete b; return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 VirtualDestructorExample.cpp -o VirtualDestructorExample */
