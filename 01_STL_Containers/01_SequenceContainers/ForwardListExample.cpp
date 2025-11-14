/**
 * @file ForwardListExample.cpp
 * @brief Comprehensive examples of std::forward_list usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Singly-linked list operations
 * - Memory efficiency over list
 * - Forward-only iteration
 * - insert_after and erase_after operations
 * - When to use forward_list
 */

#include <iostream>
#include <forward_list>
#include <algorithm>

void example1_BasicOperations();
void example2_InsertAfterEraseAfter();
void example3_FrontOperations();
void example4_SortingAndOthers();
void example5_ComparisonWithList();
void example6_MemoryEfficiency();

/**
 * @brief Example 1: Basic Forward List Operations
 * @complexity Time: O(1) for most operations
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Forward List Operations ---" << std::endl;

    std::forward_list<int> flst1;                      // Empty
    std::forward_list<int> flst2(5, 10);               // 5 elements, all 10
    std::forward_list<int> flst3 = {1, 2, 3, 4, 5};    // Initializer list

    std::cout << "flst3: ";
    for (int val : flst3) std::cout << val << " ";
    std::cout << std::endl;

    // Note: forward_list has NO size() method!
    // No back(), no push_back(), no size()
    std::cout << "Front element: " << flst3.front() << std::endl;

    // Check if empty
    std::cout << "Empty? " << (flst3.empty() ? "yes" : "no") << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: insert_after and erase_after
 * @complexity Time: O(1) for operations
 */
void example2_InsertAfterEraseAfter() {
    std::cout << "--- insert_after and erase_after ---" << std::endl;

    std::forward_list<int> flst = {1, 2, 4, 5};

    std::cout << "Initial: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Insert after first element
    auto it = flst.begin();
    flst.insert_after(it, 99);
    std::cout << "After insert_after begin: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Insert multiple elements after position
    it = flst.begin();
    std::advance(it, 2);
    flst.insert_after(it, {10, 20, 30});
    std::cout << "After inserting {10,20,30}: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Erase after position
    it = flst.begin();
    std::advance(it, 1);
    flst.erase_after(it);
    std::cout << "After erase_after: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 3: Front Operations
 * @complexity Time: O(1)
 */
void example3_FrontOperations() {
    std::cout << "--- Front Operations ---" << std::endl;

    std::forward_list<int> flst = {2, 3, 4};

    std::cout << "Initial: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // push_front - O(1)
    flst.push_front(1);
    flst.push_front(0);
    std::cout << "After push_front(1, 0): ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // emplace_front - constructs in place
    flst.emplace_front(-1);
    std::cout << "After emplace_front(-1): ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // pop_front - O(1)
    flst.pop_front();
    std::cout << "After pop_front: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Note: NO push_back, pop_back, or back() methods!

    std::cout << std::endl;
}

/**
 * @brief Example 4: Sorting and Other Operations
 * @complexity Time: O(n log n) for sort, O(n) for others
 */
void example4_SortingAndOthers() {
    std::cout << "--- Sorting and Other Operations ---" << std::endl;

    std::forward_list<int> flst = {5, 2, 8, 1, 9};

    std::cout << "Before sort: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Sort
    flst.sort();
    std::cout << "After sort: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Reverse
    flst.reverse();
    std::cout << "After reverse: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Add duplicates
    flst.push_front(9);
    flst.push_front(9);
    std::cout << "After adding duplicates: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Remove consecutive duplicates
    flst.unique();
    std::cout << "After unique: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Remove all elements with value
    flst.remove(5);
    std::cout << "After remove(5): ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Remove if (predicate)
    flst.remove_if([](int x) { return x % 2 == 0; });
    std::cout << "After remove_if (even): ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 5: Comparison with List
 * @complexity Time: N/A (informational)
 */
void example5_ComparisonWithList() {
    std::cout << "--- Forward List vs List ---" << std::endl;

    std::cout << "Forward List characteristics:" << std::endl;
    std::cout << "+ Singly-linked (only forward pointers)" << std::endl;
    std::cout << "+ Lower memory overhead (1 pointer per node vs 2)" << std::endl;
    std::cout << "+ Operations: push_front, pop_front, insert_after, erase_after" << std::endl;
    std::cout << "- No size() method (would be O(n))" << std::endl;
    std::cout << "- No back(), push_back(), pop_back()" << std::endl;
    std::cout << "- Forward iteration only" << std::endl;

    std::cout << "\nList characteristics:" << std::endl;
    std::cout << "+ Doubly-linked (forward and backward pointers)" << std::endl;
    std::cout << "+ Has size() method - O(1)" << std::endl;
    std::cout << "+ Operations at both ends: push_front, push_back, etc." << std::endl;
    std::cout << "+ Bidirectional iteration" << std::endl;
    std::cout << "- Higher memory overhead (2 pointers per node)" << std::endl;

    std::cout << "\nWhen to use forward_list:" << std::endl;
    std::cout << "1. Memory is constrained" << std::endl;
    std::cout << "2. Only forward iteration needed" << std::endl;
    std::cout << "3. Only insertions/deletions after known position" << std::endl;
    std::cout << "4. Don't need size() frequently" << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Memory Efficiency Demonstration
 * @complexity Time: O(n)
 */
void example6_MemoryEfficiency() {
    std::cout << "--- Memory Efficiency ---" << std::endl;

    // Conceptual demonstration
    std::cout << "Memory per node (approximate):" << std::endl;
    std::cout << "forward_list: data + 1 pointer = "
              << sizeof(int) + sizeof(void*) << " bytes" << std::endl;
    std::cout << "list: data + 2 pointers = "
              << sizeof(int) + 2*sizeof(void*) << " bytes" << std::endl;

    std::forward_list<int> flst;
    for (int i = 0; i < 10; ++i) {
        flst.push_front(i);
    }

    std::cout << "\nforward_list with 10 elements: ";
    for (int val : flst) std::cout << val << " ";
    std::cout << std::endl;

    // Calculate size manually (since no size() method)
    int count = 0;
    for ([[maybe_unused]] auto& val : flst) {
        ++count;
    }
    std::cout << "Manual count: " << count << " elements" << std::endl;

    // Alternative: use std::distance
    count = std::distance(flst.begin(), flst.end());
    std::cout << "Using std::distance: " << count << " elements" << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Forward List Comprehensive Examples" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_InsertAfterEraseAfter();
    example3_FrontOperations();
    example4_SortingAndOthers();
    example5_ComparisonWithList();
    example6_MemoryEfficiency();

    std::cout << "========================================" << std::endl;
    std::cout << "  All forward_list examples completed!  " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 ForwardListExample.cpp -o ForwardListExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 ForwardListExample.cpp -o ForwardListExample
 *
 * Run:
 *   ./ForwardListExample       (Linux/Mac)
 *   .\ForwardListExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. forward_list is most memory-efficient sequence container
 * 2. No size() method - use std::distance if needed
 * 3. No back operations - only front operations
 * 4. Use insert_after and erase_after (not insert/erase)
 * 5. Good for algorithms that only need forward iteration
 * 6. About 50% memory overhead reduction compared to list
 */

