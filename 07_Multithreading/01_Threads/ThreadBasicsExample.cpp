/**
 * @file ThreadBasicsExample.cpp
 * @brief Demonstrates basic std::thread creation, join, detach.
 * @date 2025-11-15
 */

#include <iostream>
#include <thread>
#include <chrono>

void worker(int id) {
    std::cout << "Worker " << id << " starting" << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Worker " << id << " finished" << '\n';
}

int main() {
    std::cout << "=== Thread Basics ===\n";
    std::thread t1(worker,1);
    std::thread t2(worker,2);
    t1.join();
    t2.join();

    std::thread detached([](){
        std::cout << "Detached thread running" << '\n';
    });
    detached.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Main done" << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -pthread -Wall -Wextra -O2 ThreadBasicsExample.cpp -o ThreadBasicsExample */

