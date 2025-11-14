/**
 * @file ThreadLifecycleExample.cpp
 * @brief Demonstrates thread creation, join, detach lifecycle considerations.
 * @date 2025-11-15
 */
#include <iostream>
#include <thread>
#include <chrono>

void task(){ std::cout<<"Task running"<<'\n'; }

int main(){
    std::thread t(task);
    std::cout << "Joinable? " << t.joinable() << '\n';
    t.join();
    std::cout << "After join joinable? " << t.joinable() << '\n';
    std::thread td(task);
    td.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Detached thread may finish independently" << '\n';
    return 0;
}
/* Compilation: g++ -std=c++17 -pthread -Wall -Wextra -O2 ThreadLifecycleExample.cpp -o ThreadLifecycleExample */
