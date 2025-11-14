/**
 * @file AsyncExample.cpp
 * @brief Demonstrates std::async for asynchronous task execution.
 * @date 2025-11-15
 */

#include <iostream>
#include <future>
#include <thread>

int compute(int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    return x * x;
}

int main() {
    std::cout << "=== std::async Example ===\n";
    auto fut = std::async(std::launch::async, compute, 12);
    std::cout << "Doing other work...\n";
    std::cout << "Result=" << fut.get() << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -pthread -Wall -Wextra -O2 AsyncExample.cpp -o AsyncExample */

