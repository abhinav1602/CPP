/**
 * @file StackImplementation.cpp
 * @brief Simple stack implementation using dynamic array growth.
 * @date 2025-11-15
 */

#include <iostream>
#include <vector>

class Stack {
    std::vector<int> data;
public:
    void push(int v) { data.push_back(v); }
    void pop() { if (!data.empty()) data.pop_back(); }
    int top() const { return data.back(); }
    bool empty() const { return data.empty(); }
    std::size_t size() const { return data.size(); }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    std::cout << "Top=" << s.top() << '\n';
    s.pop();
    std::cout << "Top after pop=" << s.top() << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 StackImplementation.cpp -o StackImplementation */

