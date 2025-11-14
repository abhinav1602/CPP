/**
 * @file VirtualInheritanceExample.cpp
 * @brief Diamond problem resolved with virtual inheritance.
 * @date 2025-11-15
 */
#include <iostream>

struct Base { int v{1}; };
struct Left : virtual Base { Left(){ v=2; } };
struct Right : virtual Base { Right(){ v=3; } };
struct Derived : Left, Right { Derived(){ v=4; } };

int main(){ Derived d; std::cout << d.v << '\n'; return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 VirtualInheritanceExample.cpp -o VirtualInheritanceExample */
