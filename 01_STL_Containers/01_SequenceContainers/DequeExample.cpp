/**
 * @file DequeExample.cpp
 * @brief Comprehensive examples of std::deque usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Basic deque operations
 * - Double-ended insertions and deletions
 * - Random access capabilities
 * - Comparison with vector
 * - Real-world use cases (sliding window, task scheduling)
 * - Performance characteristics
 */

#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

void example1_BasicOperations();
void example2_DoubleEndedOperations();
void example3_RandomAccess();
void example4_ComparisonWithVector();
void example5_SlidingWindowPattern();
void example6_TaskScheduler();

/**
 * @brief Example 1: Basic Deque Operations
 * @complexity Time: O(1) for most operations
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Deque Operations ---" << std::endl;

    // Different ways to create deques
    std::deque<int> dq1;                        // Empty deque
    std::deque<int> dq2(5);                     // 5 elements, default-initialized
    std::deque<int> dq3(5, 10);                 // 5 elements, all 10
    std::deque<int> dq4 = {1, 2, 3, 4, 5};      // Initializer list

    std::cout << "dq4: ";
    for (int val : dq4) std::cout << val << " ";
    std::cout << std::endl;

    // Basic information
    std::cout << "Size: " << dq4.size() << std::endl;
    std::cout << "Empty? " << (dq4.empty() ? "yes" : "no") << std::endl;
    std::cout << "Front: " << dq4.front() << ", Back: " << dq4.back() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: Double-Ended Operations (Key Feature)
 * @complexity Time: O(1) for push/pop at both ends
 */
void example2_DoubleEndedOperations() {
    std::cout << "--- Double-Ended Operations ---" << std::endl;

    std::deque<int> dq = {3, 4, 5};

    std::cout << "Initial: ";
    for (int val : dq) std::cout << val << " ";
    std::cout << std::endl;

    // Push to front - O(1)
    dq.push_front(2);
    dq.push_front(1);
    std::cout << "After push_front(2, 1): ";
    for (int val : dq) std::cout << val << " ";
    std::cout << std::endl;

    // Push to back - O(1)
    dq.push_back(6);
    dq.push_back(7);
    std::cout << "After push_back(6, 7): ";
    for (int val : dq) std::cout << val << " ";
    std::cout << std::endl;

    // Pop from front - O(1)
    dq.pop_front();
    std::cout << "After pop_front(): ";
    for (int val : dq) std::cout << val << " ";
    std::cout << std::endl;

    // Pop from back - O(1)
    dq.pop_back();
    std::cout << "After pop_back(): ";
    for (int val : dq) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 3: Random Access (Like Vector)
 * @complexity Time: O(1) for random access
 */
void example3_RandomAccess() {
    std::cout << "--- Random Access ---" << std::endl;

    std::deque<int> dq = {10, 20, 30, 40, 50};

    // Access using operator[]
    std::cout << "Using operator[]: ";
    for (size_t i = 0; i < dq.size(); ++i) {
        std::cout << dq[i] << " ";
    }
    std::cout << std::endl;

    // Access using at() with bounds checking
    std::cout << "Element at index 2: " << dq.at(2) << std::endl;

    // Modify elements
    dq[2] = 99;
    std::cout << "After dq[2] = 99: ";
    for (int val : dq) std::cout << val << " ";
    std::cout << std::endl;

    // Insert in middle - O(n)
    dq.insert(dq.begin() + 2, 88);
    std::cout << "After insert at index 2: ";
    for (int val : dq) std::cout << val << " ";
    std::cout << std::endl;

    // Erase from middle - O(n)
    dq.erase(dq.begin() + 3);
    std::cout << "After erase at index 3: ";
    for (int val : dq) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 4: Comparison with Vector
 * @complexity Time: varies
 */
void example4_ComparisonWithVector() {
    std::cout << "--- Deque vs Vector ---" << std::endl;

    std::cout << "Deque advantages:" << std::endl;
    std::cout << "1. O(1) insertion/deletion at both ends" << std::endl;
    std::cout << "2. No reallocation (no capacity concept)" << std::endl;
    std::cout << "3. Better for queue operations" << std::endl;

    std::cout << "\nVector advantages:" << std::endl;
    std::cout << "1. Better cache locality (contiguous memory)" << std::endl;
    std::cout << "2. Faster iteration" << std::endl;
    std::cout << "3. Less memory overhead" << std::endl;

    std::cout << "\nDeque memory model:" << std::endl;
    std::cout << "- Non-contiguous storage (chunks/blocks)" << std::endl;
    std::cout << "- No capacity() method" << std::endl;
    std::cout << "- Iterators may be invalidated differently" << std::endl;

    // Demonstrate deque doesn't have capacity
    std::deque<int> dq;
    for (int i = 0; i < 10; ++i) {
        dq.push_back(i);
        // Note: deque has no capacity() method
        std::cout << "Size after push_back(" << i << "): " << dq.size() << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 5: Sliding Window Pattern
 * @complexity Time: O(n) for processing n elements
 */
void example5_SlidingWindowPattern() {
    std::cout << "--- Sliding Window Pattern ---" << std::endl;

    std::deque<int> window;
    std::vector<int> data = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;  // Window size

    std::cout << "Data: ";
    for (int val : data) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "Window size: " << k << std::endl;
    std::cout << "\nMaximum in each window:" << std::endl;

    // Find maximum in each sliding window
    for (size_t i = 0; i < data.size(); ++i) {
        // Remove elements outside current window
        while (!window.empty() && window.front() <= static_cast<int>(i) - k) {
            window.pop_front();
        }

        // Remove elements smaller than current (they won't be max)
        while (!window.empty() && data[window.back()] <= data[i]) {
            window.pop_back();
        }

        window.push_back(i);

        // Start printing when first window is complete
        if (i >= static_cast<size_t>(k - 1)) {
            std::cout << "Window [" << (i - k + 1) << "-" << i << "]: max = "
                      << data[window.front()] << std::endl;
        }
    }

    std::cout << std::endl;
}

/**
 * @brief Example 6: Task Scheduler Simulation
 * @complexity Time: O(n) for n tasks
 */
void example6_TaskScheduler() {
    std::cout << "--- Task Scheduler ---" << std::endl;

    std::deque<std::string> taskQueue;

    // Add tasks
    taskQueue.push_back("Process data");
    taskQueue.push_back("Send email");
    taskQueue.push_back("Update database");

    // High priority task (add to front)
    taskQueue.push_front("Emergency: Fix server");

    std::cout << "Task queue:" << std::endl;
    for (const auto& task : taskQueue) {
        std::cout << "- " << task << std::endl;
    }

    std::cout << "\nProcessing tasks..." << std::endl;
    while (!taskQueue.empty()) {
        std::string currentTask = taskQueue.front();
        taskQueue.pop_front();
        std::cout << "Processing: " << currentTask << std::endl;

        // Simulate: some tasks spawn new tasks
        if (currentTask == "Update database") {
            taskQueue.push_back("Verify database integrity");
            std::cout << "  -> Added: Verify database integrity" << std::endl;
        }
    }

    std::cout << "All tasks completed!" << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "     STL Deque Comprehensive Examples   " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_DoubleEndedOperations();
    example3_RandomAccess();
    example4_ComparisonWithVector();
    example5_SlidingWindowPattern();
    example6_TaskScheduler();

    std::cout << "========================================" << std::endl;
    std::cout << "  All deque examples completed!         " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 DequeExample.cpp -o DequeExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 DequeExample.cpp -o DequeExample
 *
 * Run:
 *   ./DequeExample       (Linux/Mac)
 *   .\DequeExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. Use deque when you need O(1) insertions/deletions at both ends
 * 2. Deque provides random access like vector
 * 3. No capacity management needed (no reallocation)
 * 4. Good for queue/sliding window algorithms
 * 5. Slightly slower iteration than vector due to non-contiguous storage
 */

