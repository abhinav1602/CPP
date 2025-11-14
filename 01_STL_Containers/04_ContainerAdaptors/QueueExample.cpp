/**
 * @file QueueExample.cpp
 * @brief Comprehensive examples of std::queue usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - FIFO (First-In-First-Out) operations
 * - Queue operations: push, pop, front, back
 * - Use cases: task scheduling, BFS
 * - Underlying container selection
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>

void example1_BasicOperations();
void example2_FIFODemonstration();
void example3_TaskScheduler();
void example4_BFSSimulation();
void example5_UnderlyingContainer();
void example6_PrintQueue();

/**
 * @brief Example 1: Basic Queue Operations
 * @complexity Time: O(1) for all operations
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Queue Operations ---" << std::endl;

    std::queue<int> q;

    std::cout << "Empty? " << (q.empty() ? "yes" : "no") << std::endl;

    // Push elements (enqueue)
    q.push(10);
    q.push(20);
    q.push(30);
    q.emplace(40);

    std::cout << "After pushing 10, 20, 30, 40:" << std::endl;
    std::cout << "Size: " << q.size() << std::endl;
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    // Pop element (dequeue)
    q.pop();
    std::cout << "After pop():" << std::endl;
    std::cout << "Size: " << q.size() << std::endl;
    std::cout << "Front: " << q.front() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: FIFO Demonstration
 * @complexity Time: O(n)
 */
void example2_FIFODemonstration() {
    std::cout << "--- FIFO Demonstration ---" << std::endl;

    std::queue<std::string> customers;

    // Customers arrive
    customers.push("Alice");
    customers.push("Bob");
    customers.push("Charlie");
    customers.push("Diana");

    std::cout << "Customers in queue:" << std::endl;
    std::cout << "1. Alice (first)" << std::endl;
    std::cout << "2. Bob" << std::endl;
    std::cout << "3. Charlie" << std::endl;
    std::cout << "4. Diana (last)" << std::endl;

    std::cout << "\nServing customers (First In, First Out):" << std::endl;
    while (!customers.empty()) {
        std::cout << "Serving: " << customers.front() << std::endl;
        customers.pop();
    }

    std::cout << std::endl;
}

/**
 * @brief Example 3: Task Scheduler Simulation
 * @complexity Time: O(n)
 */
void example3_TaskScheduler() {
    std::cout << "--- Task Scheduler ---" << std::endl;

    struct Task {
        int id;
        std::string description;
    };

    std::queue<Task> taskQueue;

    // Add tasks
    taskQueue.push({1, "Process data"});
    taskQueue.push({2, "Send email"});
    taskQueue.push({3, "Update database"});
    taskQueue.push({4, "Generate report"});

    std::cout << "Tasks in queue: " << taskQueue.size() << std::endl;

    // Process tasks
    std::cout << "\nProcessing tasks in order:" << std::endl;
    int processed = 0;
    while (!taskQueue.empty() && processed < 3) {
        Task current = taskQueue.front();
        taskQueue.pop();

        std::cout << "Task " << current.id << ": " << current.description << std::endl;
        processed++;

        // Simulate: some tasks spawn new tasks
        if (current.id == 2) {
            taskQueue.push({5, "Verify email sent"});
            std::cout << "  -> Added new task: Verify email sent" << std::endl;
        }
    }

    std::cout << "\nRemaining tasks: " << taskQueue.size() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 4: BFS (Breadth-First Search) Simulation
 * @complexity Time: O(V + E) for graph with V vertices and E edges
 */
void example4_BFSSimulation() {
    std::cout << "--- BFS Simulation ---" << std::endl;

    // Simple tree: 1 has children 2,3; 2 has children 4,5; 3 has child 6
    std::vector<std::vector<int>> tree = {
        {},           // 0 (not used)
        {2, 3},       // 1
        {4, 5},       // 2
        {6},          // 3
        {},           // 4
        {},           // 5
        {}            // 6
    };

    std::queue<int> q;
    std::vector<bool> visited(7, false);

    int start = 1;
    q.push(start);
    visited[start] = true;

    std::cout << "BFS traversal starting from node " << start << ":" << std::endl;
    std::cout << "Visit order: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        std::cout << current << " ";

        // Add children to queue
        for (int child : tree[current]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 5: Underlying Container Selection
 * @complexity Time: O(1)
 */
void example5_UnderlyingContainer() {
    std::cout << "--- Underlying Container Selection ---" << std::endl;

    // Default: deque
    std::queue<int> q1;

    // Using list
    std::queue<int, std::list<int>> q2;

    std::cout << "Queue can use different underlying containers:" << std::endl;
    std::cout << "1. std::queue<int> - uses deque (default)" << std::endl;
    std::cout << "2. std::queue<int, std::list<int>> - uses list" << std::endl;

    std::cout << "\nRecommendation: Use default (deque) for best performance" << std::endl;

    // Both work the same way
    for (int i = 1; i <= 3; ++i) {
        q1.push(i);
        q2.push(i);
    }

    std::cout << "\nBoth queues front element: " << q1.front() << ", " << q2.front() << std::endl;
    std::cout << "Both queues back element: " << q1.back() << ", " << q2.back() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Print Queue Simulation
 * @complexity Time: O(n)
 */
void example6_PrintQueue() {
    std::cout << "--- Print Queue Simulation ---" << std::endl;

    struct PrintJob {
        std::string document;
        int pages;
    };

    std::queue<PrintJob> printQueue;

    // Add print jobs
    printQueue.push({"Report.pdf", 10});
    printQueue.push({"Letter.docx", 1});
    printQueue.push({"Presentation.pptx", 25});
    printQueue.push({"Invoice.pdf", 2});

    std::cout << "Print queue has " << printQueue.size() << " jobs" << std::endl;

    int totalPages = 0;
    std::cout << "\nProcessing print jobs:" << std::endl;

    while (!printQueue.empty()) {
        PrintJob job = printQueue.front();
        printQueue.pop();

        std::cout << "Printing: " << job.document << " (" << job.pages << " pages)" << std::endl;
        totalPages += job.pages;

        // Simulate printing time
        if (job.pages > 20) {
            std::cout << "  [Long job - may take a while]" << std::endl;
        }
    }

    std::cout << "\nAll jobs completed!" << std::endl;
    std::cout << "Total pages printed: " << totalPages << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "    STL Queue Comprehensive Examples    " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_FIFODemonstration();
    example3_TaskScheduler();
    example4_BFSSimulation();
    example5_UnderlyingContainer();
    example6_PrintQueue();

    std::cout << "========================================" << std::endl;
    std::cout << "  All queue examples completed!         " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 QueueExample.cpp -o QueueExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 QueueExample.cpp -o QueueExample
 *
 * Run:
 *   ./QueueExample       (Linux/Mac)
 *   .\QueueExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. Queue provides FIFO (First-In-First-Out) access
 * 2. Can access both front and back elements
 * 3. No iteration support
 * 4. All operations are O(1)
 * 5. Perfect for task scheduling, BFS, buffering
 * 6. Always check empty() before front(), back(), or pop()
 */

