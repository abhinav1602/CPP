/**
 * @file ConditionVariableExample.cpp
 * @brief Producer-consumer using std::condition_variable.
 * @date 2025-11-15
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> q;
bool done = false;

void producer() {
    for (int i = 1; i <= 5; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            q.push(i);
            std::cout << "Produced " << i << '\n';
        }
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !q.empty() || done; });
        while(!q.empty()) {
            int v = q.front(); q.pop();
            std::cout << "Consumed " << v << '\n';
        }
        if (done) break;
    }
}

int main() {
    std::cout << "=== Condition Variable Producer/Consumer ===\n";
    std::thread p(producer);
    std::thread c(consumer);
    p.join();
    c.join();
    return 0;
}

/* Compilation: g++ -std=c++17 -pthread -Wall -Wextra -O2 ConditionVariableExample.cpp -o ConditionVariableExample */

