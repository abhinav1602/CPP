/**
 * @file PriorityQueueExample.cpp
 * @brief Comprehensive examples of std::priority_queue usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Heap-based priority queue operations
 * - Max-heap and min-heap configurations
 * - Custom comparators for priorities
 * - Use cases: Dijkstra, event scheduling, Top K
 */

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>

void example1_BasicOperations();
void example2_MaxHeapMinHeap();
void example3_CustomComparator();
void example4_EventScheduler();
void example5_TopKElements();
void example6_MergeSortedArrays();
void example7_TaskPriority();

/**
 * @brief Example 1: Basic Priority Queue Operations
 * @complexity Time: O(log n) for insert/remove, O(1) for top
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Priority Queue Operations ---" << std::endl;

    std::priority_queue<int> pq;  // Max-heap by default

    std::cout << "Empty? " << (pq.empty() ? "yes" : "no") << std::endl;

    // Push elements
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.emplace(40);

    std::cout << "After pushing 30, 10, 50, 20, 40:" << std::endl;
    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top (max): " << pq.top() << std::endl;

    // Pop top element
    pq.pop();
    std::cout << "After pop():" << std::endl;
    std::cout << "New top: " << pq.top() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: Max-Heap vs Min-Heap
 * @complexity Time: O(n log n)
 */
void example2_MaxHeapMinHeap() {
    std::cout << "--- Max-Heap vs Min-Heap ---" << std::endl;

    std::vector<int> data = {30, 10, 50, 20, 40};

    // Max-heap (default)
    std::priority_queue<int> maxHeap(data.begin(), data.end());

    std::cout << "Max-Heap (largest first): ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;

    // Min-heap (using greater comparator)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(data.begin(), data.end());

    std::cout << "Min-Heap (smallest first): ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 3: Custom Comparator
 * @complexity Time: O(log n) per operation
 */
void example3_CustomComparator() {
    std::cout << "--- Custom Comparator ---" << std::endl;

    struct Person {
        std::string name;
        int age;
    };

    // Priority by age (older has higher priority)
    auto cmp = [](const Person& a, const Person& b) {
        return a.age < b.age;  // Max-heap based on age
    };

    std::priority_queue<Person, std::vector<Person>, decltype(cmp)> pq(cmp);

    pq.push({"Alice", 25});
    pq.push({"Bob", 30});
    pq.push({"Charlie", 20});
    pq.push({"Diana", 35});

    std::cout << "Priority by age (oldest first):" << std::endl;
    while (!pq.empty()) {
        Person p = pq.top();
        pq.pop();
        std::cout << p.name << " (age " << p.age << ")" << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 4: Event Scheduler
 * @complexity Time: O(n log n)
 */
void example4_EventScheduler() {
    std::cout << "--- Event Scheduler ---" << std::endl;

    struct Event {
        int time;      // Minutes from now
        std::string description;

        bool operator<(const Event& other) const {
            return time > other.time;  // Min-heap (soonest first)
        }
    };

    std::priority_queue<Event> scheduler;

    scheduler.push({60, "Meeting with team"});
    scheduler.push({15, "Coffee break"});
    scheduler.push({120, "Lunch"});
    scheduler.push({5, "Quick call"});
    scheduler.push({30, "Code review"});

    std::cout << "Upcoming events (chronological order):" << std::endl;
    while (!scheduler.empty()) {
        Event e = scheduler.top();
        scheduler.pop();
        std::cout << "In " << e.time << " min: " << e.description << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 5: Top K Elements
 * @complexity Time: O(n log k)
 */
void example5_TopKElements() {
    std::cout << "--- Top K Elements ---" << std::endl;

    std::vector<int> data = {12, 5, 23, 8, 42, 15, 37, 19, 3, 28};
    int k = 3;

    std::cout << "Data: ";
    for (int val : data) std::cout << val << " ";
    std::cout << std::endl;

    // Use min-heap of size k to find top k elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int val : data) {
        minHeap.push(val);
        if (minHeap.size() > static_cast<size_t>(k)) {
            minHeap.pop();
        }
    }

    std::cout << "Top " << k << " elements: ";
    std::vector<int> topK;
    while (!minHeap.empty()) {
        topK.push_back(minHeap.top());
        minHeap.pop();
    }

    // Print in descending order
    for (int i = topK.size() - 1; i >= 0; --i) {
        std::cout << topK[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Merge K Sorted Arrays
 * @complexity Time: O(n log k) where n = total elements, k = arrays
 */
void example6_MergeSortedArrays() {
    std::cout << "--- Merge K Sorted Arrays ---" << std::endl;

    std::vector<std::vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    struct Element {
        int value;
        int arrayIndex;
        int elementIndex;

        bool operator<(const Element& other) const {
            return value > other.value;  // Min-heap
        }
    };

    std::priority_queue<Element> pq;
    std::vector<int> merged;

    // Add first element from each array
    for (size_t i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            pq.push({arrays[i][0], static_cast<int>(i), 0});
        }
    }

    // Extract min and add next from same array
    while (!pq.empty()) {
        Element e = pq.top();
        pq.pop();
        merged.push_back(e.value);

        // Add next element from same array
        if (e.elementIndex + 1 < static_cast<int>(arrays[e.arrayIndex].size())) {
            pq.push({
                arrays[e.arrayIndex][e.elementIndex + 1],
                e.arrayIndex,
                e.elementIndex + 1
            });
        }
    }

    std::cout << "Input arrays:" << std::endl;
    for (size_t i = 0; i < arrays.size(); ++i) {
        std::cout << "Array " << i << ": ";
        for (int val : arrays[i]) std::cout << val << " ";
        std::cout << std::endl;
    }

    std::cout << "Merged sorted array: ";
    for (int val : merged) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 7: Task Priority System
 * @complexity Time: O(log n) per operation
 */
void example7_TaskPriority() {
    std::cout << "--- Task Priority System ---" << std::endl;

    struct Task {
        std::string name;
        int priority;  // Higher number = higher priority

        bool operator<(const Task& other) const {
            return priority < other.priority;  // Max-heap by priority
        }
    };

    std::priority_queue<Task> taskQueue;

    taskQueue.push({"Write docs", 2});
    taskQueue.push({"Fix critical bug", 5});
    taskQueue.push({"Code review", 3});
    taskQueue.push({"Coffee", 1});
    taskQueue.push({"Security patch", 5});

    std::cout << "Tasks by priority:" << std::endl;
    int taskNum = 1;
    while (!taskQueue.empty()) {
        Task t = taskQueue.top();
        taskQueue.pop();
        std::cout << taskNum++ << ". [Priority " << t.priority << "] "
                  << t.name << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << " STL Priority Queue Comprehensive Examples" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_MaxHeapMinHeap();
    example3_CustomComparator();
    example4_EventScheduler();
    example5_TopKElements();
    example6_MergeSortedArrays();
    example7_TaskPriority();

    std::cout << "========================================" << std::endl;
    std::cout << "  All priority_queue examples completed!" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 PriorityQueueExample.cpp -o PriorityQueueExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 PriorityQueueExample.cpp -o PriorityQueueExample
 *
 * Run:
 *   ./PriorityQueueExample       (Linux/Mac)
 *   .\PriorityQueueExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. Priority queue is a max-heap by default (largest on top)
 * 2. Use std::greater<T> for min-heap (smallest on top)
 * 3. Insert and remove are O(log n), top is O(1)
 * 4. Perfect for scheduling, Top K problems, Dijkstra's algorithm
 * 5. Custom comparators allow flexible priority definitions
 * 6. No iteration support - extract elements by priority
 * 7. Always check empty() before top() or pop()
 */

