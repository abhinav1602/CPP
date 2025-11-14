/**
 * @file LockGuardExample.cpp
 * @brief Demonstrates std::lock_guard for RAII mutex locking.
 * @date 2025-11-15
 */
#include <iostream>
#include <thread>
#include <mutex>

std::mutex g;
int shared=0;

void safeInc(){
    for(int i=0;i<1000;++i){ std::lock_guard<std::mutex> lk(g); ++shared; }
}

int main(){ std::thread t1(safeInc), t2(safeInc); t1.join(); t2.join(); std::cout<<"shared="<<shared<<'\n'; return 0; }
/* Compilation: g++ -std=c++17 -pthread -Wall -Wextra -O2 LockGuardExample.cpp -o LockGuardExample */
