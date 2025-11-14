/**
 * @file PlacementNewExample.cpp
 * @brief Demonstrates placement new for manual object lifetime control.
 * @date 2025-11-15
 */
#include <iostream>
#include <new>
#include <utility>
struct Thing { int a; explicit Thing(int v):a(v){ std::cout<<"Thing("<<a<<") ctor\n";} ~Thing(){ std::cout<<"Thing("<<a<<") dtor\n";} };

int main(){
    std::cout << "=== Placement New Example ===\n";
    alignas(Thing) unsigned char buffer[sizeof(Thing)];
    Thing* t = new(buffer) Thing(42); // construct in pre-allocated storage
    std::cout << "Value=" << t->a << '\n';
    t->~Thing(); // manual destruction
    // Reuse storage
    Thing* t2 = new(buffer) Thing(99);
    std::cout << "Value2=" << t2->a << '\n';
    t2->~Thing();
    std::cout << "Finished placement new demo" << '\n';
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 PlacementNewExample.cpp -o PlacementNewExample */

