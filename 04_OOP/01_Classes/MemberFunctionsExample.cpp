/**
 * @file MemberFunctionsExample.cpp
 * @brief Demonstrates const member functions, static members, and chaining.
 * @date 2025-11-15
 */
#include <iostream>
class Counter {
    int value{0};
public:
    Counter& increment(){ ++value; return *this; }
    int get() const { return value; }
    static Counter make(int start){ Counter c; c.value=start; return c; }
};

int main(){
    auto c = Counter::make(5);
    c.increment().increment();
    std::cout << "Counter=" << c.get() << '\n';
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 MemberFunctionsExample.cpp -o MemberFunctionsExample */

