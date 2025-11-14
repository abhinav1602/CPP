/**
 * @file AtomicExample.cpp
 * @brief Demonstrates std::atomic for thread-safe increments.
 * @date 2025-11-15
 */

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter{0};

void incrementMany(int times) {
    for (int i = 0; i < times; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::cout << "=== Atomic Increment ===\n";
    std::thread t1(incrementMany, 10000);
    std::thread t2(incrementMany, 10000);
    t1.join();
    t2.join();
    std::cout << "Counter=" << counter.load() << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -pthread -Wall -Wextra -O2 AtomicExample.cpp -o AtomicExample */

