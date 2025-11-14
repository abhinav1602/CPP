/**
 * @file ListExample.cpp
 * @brief Comprehensive examples of std::list usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Doubly-linked list operations
 * - Fast insertions/deletions anywhere with iterator
 * - Splice operations
 * - Sorting and merging
 * - Iterator stability
 * - When to use list vs vector
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

void example1_BasicOperations();
void example2_InsertionDeletion();
void example3_SpliceOperations();
void example4_SortingAndMerging();
void example5_UniqueAndReverse();
void example6_IteratorStability();
void example7_RealWorldUseCase();

/**
 * @brief Example 1: Basic List Operations
 * @complexity Time: O(1) for most operations
 */
void example1_BasicOperations() {
    std::cout << "--- Basic List Operations ---" << std::endl;

    std::list<int> lst1;                       // Empty list
    std::list<int> lst2(5, 10);                // 5 elements, all 10
    std::list<int> lst3 = {1, 2, 3, 4, 5};     // Initializer list

    std::cout << "lst3: ";
    for (int val : lst3) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Size: " << lst3.size() << std::endl;
    std::cout << "Front: " << lst3.front() << ", Back: " << lst3.back() << std::endl;

    // Note: list has NO random access operator[] or at()
    // Must use iterators
    std::cout << "Third element (via iterator): ";
    auto it = lst3.begin();
    std::advance(it, 2);
    std::cout << *it << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: Fast Insertion and Deletion
 * @complexity Time: O(1) for insert/erase with iterator
 */
void example2_InsertionDeletion() {
    std::cout << "--- Insertion and Deletion ---" << std::endl;

    std::list<int> lst = {1, 2, 3, 4, 5};

    std::cout << "Initial: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Insert at front - O(1)
    lst.push_front(0);
    std::cout << "After push_front(0): ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Insert at back - O(1)
    lst.push_back(6);
    std::cout << "After push_back(6): ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Insert at specific position - O(1) with iterator
    auto it = lst.begin();
    std::advance(it, 3);
    lst.insert(it, 99);
    std::cout << "After insert 99 at position 3: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Erase at specific position - O(1)
    it = lst.begin();
    std::advance(it, 3);
    lst.erase(it);
    std::cout << "After erase at position 3: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Pop front and back - O(1)
    lst.pop_front();
    lst.pop_back();
    std::cout << "After pop_front and pop_back: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 3: Splice Operations (Unique to list)
 * @complexity Time: O(1) for splice
 */
void example3_SpliceOperations() {
    std::cout << "--- Splice Operations ---" << std::endl;

    std::list<int> lst1 = {1, 2, 3};
    std::list<int> lst2 = {4, 5, 6};

    std::cout << "lst1: ";
    for (int val : lst1) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "lst2: ";
    for (int val : lst2) std::cout << val << " ";
    std::cout << std::endl;

    // Splice entire lst2 into lst1 at end - O(1)
    lst1.splice(lst1.end(), lst2);
    std::cout << "After splice lst2 into lst1: ";
    for (int val : lst1) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "lst2 size after splice: " << lst2.size() << std::endl;

    // Splice single element
    std::list<int> lst3 = {10, 20, 30, 40};
    std::list<int> lst4 = {100, 200, 300};

    auto it_src = lst4.begin();
    std::advance(it_src, 1);  // Point to 200

    auto it_dest = lst3.begin();
    std::advance(it_dest, 2);  // Insert before 30

    lst3.splice(it_dest, lst4, it_src);

    std::cout << "\nAfter splicing single element:" << std::endl;
    std::cout << "lst3: ";
    for (int val : lst3) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "lst4: ";
    for (int val : lst4) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 4: Sorting and Merging
 * @complexity Time: O(n log n) for sort, O(n) for merge
 */
void example4_SortingAndMerging() {
    std::cout << "--- Sorting and Merging ---" << std::endl;

    std::list<int> lst = {5, 2, 8, 1, 9};

    std::cout << "Before sort: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // List has its own sort method (better than std::sort for lists)
    lst.sort();
    std::cout << "After sort: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Sort in descending order
    lst.sort(std::greater<int>());
    std::cout << "After sort (descending): ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Merge two sorted lists
    std::list<int> lst1 = {1, 3, 5, 7};
    std::list<int> lst2 = {2, 4, 6, 8};

    std::cout << "\nlst1: ";
    for (int val : lst1) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "lst2: ";
    for (int val : lst2) std::cout << val << " ";
    std::cout << std::endl;

    lst1.merge(lst2);  // lst2 becomes empty
    std::cout << "After merge: ";
    for (int val : lst1) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "lst2 size: " << lst2.size() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 5: Unique and Reverse Operations
 * @complexity Time: O(n)
 */
void example5_UniqueAndReverse() {
    std::cout << "--- Unique and Reverse ---" << std::endl;

    std::list<int> lst = {1, 1, 2, 2, 2, 3, 4, 4, 5};

    std::cout << "Initial: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Remove consecutive duplicates
    lst.unique();
    std::cout << "After unique: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Reverse
    lst.reverse();
    std::cout << "After reverse: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // Remove all elements with specific value
    lst.push_back(2);
    lst.push_back(2);
    std::cout << "After adding 2s: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    lst.remove(2);
    std::cout << "After remove(2): ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Iterator Stability
 * @complexity Time: O(n)
 */
void example6_IteratorStability() {
    std::cout << "--- Iterator Stability ---" << std::endl;

    std::list<int> lst = {1, 2, 3, 4, 5};

    // Save iterators
    auto it1 = lst.begin();
    auto it3 = lst.begin();
    std::advance(it3, 2);

    std::cout << "Initial list: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "it1 points to: " << *it1 << std::endl;
    std::cout << "it3 points to: " << *it3 << std::endl;

    // Insert elements
    lst.insert(it3, 99);

    std::cout << "\nAfter insertion before it3:" << std::endl;
    std::cout << "it1 still points to: " << *it1 << " (stable)" << std::endl;
    std::cout << "it3 still points to: " << *it3 << " (stable)" << std::endl;

    std::cout << "\nList: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "\nNote: Unlike vector, list iterators remain valid" << std::endl;
    std::cout << "after insertions/deletions (except for erased elements)" << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 7: Real-World Use Case - LRU Cache
 * @complexity Time: O(1) for access with hash map (conceptual)
 */
void example7_RealWorldUseCase() {
    std::cout << "--- Real-World: Recent Items List ---" << std::endl;

    std::list<std::string> recentFiles;
    const size_t maxRecent = 5;

    // Function to add recent file
    auto addRecentFile = [&](const std::string& file) {
        // Remove if already exists
        recentFiles.remove(file);

        // Add to front
        recentFiles.push_front(file);

        // Keep only maxRecent items
        if (recentFiles.size() > maxRecent) {
            recentFiles.pop_back();
        }
    };

    // Simulate opening files
    addRecentFile("document1.txt");
    addRecentFile("image.png");
    addRecentFile("data.csv");
    addRecentFile("document1.txt");  // Access again
    addRecentFile("video.mp4");
    addRecentFile("audio.mp3");
    addRecentFile("document2.txt");

    std::cout << "Recent files (most recent first):" << std::endl;
    for (const auto& file : recentFiles) {
        std::cout << "- " << file << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "     STL List Comprehensive Examples    " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_InsertionDeletion();
    example3_SpliceOperations();
    example4_SortingAndMerging();
    example5_UniqueAndReverse();
    example6_IteratorStability();
    example7_RealWorldUseCase();

    std::cout << "========================================" << std::endl;
    std::cout << "  All list examples completed!          " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 ListExample.cpp -o ListExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 ListExample.cpp -o ListExample
 *
 * Run:
 *   ./ListExample       (Linux/Mac)
 *   .\ListExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. List provides O(1) insertion/deletion anywhere with iterator
 * 2. No random access - must use iterators
 * 3. Iterators remain stable after modifications
 * 4. Splice operations are very efficient (O(1))
 * 5. Use list when frequent insertions/deletions in middle are needed
 * 6. List has its own sort/merge methods (don't use std::sort)
 */

