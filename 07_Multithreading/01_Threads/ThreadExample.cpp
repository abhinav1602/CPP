/**
 * @file ThreadExample.cpp
 * @brief Basic Threads
 * @date 2025-11-15
 */

#include <iostream>
#include <thread>

void printHello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(printHello);
    t.join();
    std::cout << "Main thread finished" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 ThreadExample.cpp -o  */
