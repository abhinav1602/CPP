/**
 * @file StackExample.cpp
 * @brief Stack Implementation
 * @date 2025-11-15
 */

#include <iostream>
#include <vector>

template<typename T>
class Stack {
    std::vector<T> data;
public:
    void push(T value) { data.push_back(value); }
    void pop() { if(!data.empty()) data.pop_back(); }
    T top() const { return data.back(); }
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
};

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "Top: " << s.top() << std::endl;
    s.pop();
    std::cout << "New top: " << s.top() << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 StackExample.cpp -o  */
