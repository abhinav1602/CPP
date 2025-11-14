/**
 * @file PerfectForwardingExample.cpp
 * @brief Demonstrates perfect forwarding with templates and std::forward.
 * @date 2025-11-15
 */
#include <iostream>
#include <utility>

void process(const int& x){ std::cout<<"lvalue int: "<<x<<'\n'; }
void process(int&& x){ std::cout<<"rvalue int: "<<x<<'\n'; }

template<typename T>
void forwarder(T&& value){ process(std::forward<T>(value)); }

int main(){ int a=5; forwarder(a); forwarder(10); return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 PerfectForwardingExample.cpp -o PerfectForwardingExample */
