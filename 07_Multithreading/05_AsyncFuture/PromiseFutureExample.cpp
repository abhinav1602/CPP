/**
 * @file PromiseFutureExample.cpp
 * @brief Demonstrates std::promise and std::future synchronization.
 * @date 2025-11-15
 */

#include <iostream>
#include <thread>
#include <future>

void produce(std::promise<int> p) {
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    p.set_value(99);
}

int main() {
    std::cout << "=== Promise/Future Example ===\n";
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::thread t(produce, std::move(p));
    std::cout << "Waiting for value...\n";
    std::cout << "Got value=" << f.get() << '\n';
    t.join();
    return 0;
}

/* Compilation: g++ -std=c++17 -pthread -Wall -Wextra -O2 PromiseFutureExample.cpp -o PromiseFutureExample */

