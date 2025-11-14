/**
 * @file QueueImplementation.cpp
 * @brief Circular buffer queue implementation.
 * @date 2025-11-15
 */

#include <iostream>
#include <vector>

class Queue {
    std::vector<int> buf;
    std::size_t head = 0, tail = 0, count = 0;
public:
    explicit Queue(std::size_t capacity = 8) : buf(capacity) {}
    bool empty() const { return count == 0; }
    bool full() const { return count == buf.size(); }
    void enqueue(int v) {
        if (full()) return; // simple
        buf[tail] = v;
        tail = (tail + 1) % buf.size();
        ++count;
    }
    void dequeue() {
        if (empty()) return;
        head = (head + 1) % buf.size();
        --count;
    }
    int front() const { return buf[head]; }
};

int main() {
    Queue q(5);
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    std::cout << "Front=" << q.front() << '\n';
    q.dequeue();
    std::cout << "Front after dequeue=" << q.front() << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 QueueImplementation.cpp -o QueueImplementation */

