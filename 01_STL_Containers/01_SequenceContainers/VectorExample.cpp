/**
 * @file VectorExample.cpp
 * @brief Comprehensive examples of std::vector usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - Basic vector operations
 * - Capacity management
 * - Iterator usage
 * - Modern C++ features with vectors
 * - Performance considerations
 * - Common use cases and patterns
 * - Best practices and pitfalls
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

// Function prototypes
void example1_BasicOperations();
void example2_CapacityManagement();
void example3_ElementAccess();
void example4_Iterators();
void example5_Modifiers();
void example6_Algorithms();
void example7_TwoDimensionalVector();
void example8_VectorOfCustomObjects();

/**
 * @brief Example 1: Basic Operations
 * @complexity Time: O(1) for most operations, O(n) for initialization
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Operations ---" << std::endl;

    // 1. Different ways to create vectors
    std::vector<int> vec1;                      // Empty vector
    std::vector<int> vec2(5);                   // 5 elements, default-initialized to 0
    std::vector<int> vec3(5, 10);               // 5 elements, all initialized to 10
    std::vector<int> vec4 = {1, 2, 3, 4, 5};    // Initializer list (C++11)
    std::vector<int> vec5(vec4);                // Copy constructor
    std::vector<int> vec6(vec4.begin(), vec4.begin() + 3);  // Range constructor

    // 2. Display vectors
    std::cout << "vec2 (5 default): ";
    for (int val : vec2) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "vec3 (5 of 10): ";
    for (int val : vec3) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "vec4 (initializer): ";
    for (int val : vec4) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "vec6 (range): ";
    for (int val : vec6) std::cout << val << " ";
    std::cout << std::endl;

    // 3. Basic information
    std::cout << "vec4 size: " << vec4.size() << std::endl;
    std::cout << "vec4 empty? " << (vec4.empty() ? "yes" : "no") << std::endl;
    std::cout << "vec4 max_size: " << vec4.max_size() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: Capacity Management
 * @complexity Time: O(1) for capacity operations, O(n) for reserve
 */
void example2_CapacityManagement() {
    std::cout << "--- Capacity Management ---" << std::endl;

    std::vector<int> vec;

    std::cout << "Initial - Size: " << vec.size()
              << ", Capacity: " << vec.capacity() << std::endl;

    // Adding elements shows reallocation
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
        std::cout << "After push_back(" << i << ") - Size: " << vec.size()
                  << ", Capacity: " << vec.capacity() << std::endl;
    }

    // Reserve capacity to avoid reallocations
    std::cout << "\nReserving capacity for 100 elements..." << std::endl;
    vec.reserve(100);
    std::cout << "After reserve(100) - Size: " << vec.size()
              << ", Capacity: " << vec.capacity() << std::endl;

    // Add more elements (no reallocation)
    for (int i = 6; i <= 10; ++i) {
        vec.push_back(i);
    }
    std::cout << "After 5 more push_backs - Size: " << vec.size()
              << ", Capacity: " << vec.capacity() << std::endl;

    // Shrink to fit
    vec.shrink_to_fit();
    std::cout << "After shrink_to_fit() - Size: " << vec.size()
              << ", Capacity: " << vec.capacity() << std::endl;

    // Resize
    vec.resize(15, 99);  // Resize to 15, fill new elements with 99
    std::cout << "After resize(15, 99) - Size: " << vec.size() << std::endl;
    std::cout << "Elements: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 3: Element Access
 * @complexity Time: O(1) for all access methods
 */
void example3_ElementAccess() {
    std::cout << "--- Element Access ---" << std::endl;

    std::vector<int> vec = {10, 20, 30, 40, 50};

    // 1. Using operator[]
    std::cout << "Using operator[]: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 2. Using at() with bounds checking
    std::cout << "Using at(): ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    // 3. Front and back
    std::cout << "Front element: " << vec.front() << std::endl;
    std::cout << "Back element: " << vec.back() << std::endl;

    // 4. Direct access to underlying array
    int* data = vec.data();
    std::cout << "Using data(): " << data[0] << " " << data[1] << std::endl;

    // 5. Exception handling with at()
    try {
        std::cout << "Accessing out of bounds with at()..." << std::endl;
        int val = vec.at(100);  // Will throw exception
        std::cout << val << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 4: Iterator Usage
 * @complexity Time: O(n) for full iteration
 */
void example4_Iterators() {
    std::cout << "--- Iterators ---" << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 1. Forward iterator
    std::cout << "Forward iteration: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 2. Const iterator
    std::cout << "Const iterator: ";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 3. Reverse iterator
    std::cout << "Reverse iteration: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 4. Range-based for loop (C++11) - Best practice
    std::cout << "Range-based for: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 5. Modifying through iterators
    std::cout << "Doubling all elements..." << std::endl;
    for (auto& val : vec) {
        val *= 2;
    }
    std::cout << "After doubling: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 5: Modifiers
 * @complexity Time: varies by operation
 */
void example5_Modifiers() {
    std::cout << "--- Modifiers ---" << std::endl;

    std::vector<int> vec = {1, 2, 3};

    // 1. push_back and pop_back - O(1) amortized
    std::cout << "Initial: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    vec.push_back(4);
    vec.push_back(5);
    std::cout << "After push_back(4, 5): ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    vec.pop_back();
    std::cout << "After pop_back(): ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 2. emplace_back - constructs in place (C++11) - O(1) amortized
    vec.emplace_back(6);
    std::cout << "After emplace_back(6): ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 3. insert - O(n)
    vec.insert(vec.begin() + 2, 99);  // Insert 99 at index 2
    std::cout << "After insert at index 2: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 4. erase - O(n)
    vec.erase(vec.begin() + 2);  // Erase element at index 2
    std::cout << "After erase at index 2: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 5. clear - O(n)
    vec.clear();
    std::cout << "After clear: size = " << vec.size() << std::endl;

    // 6. assign - O(n)
    vec.assign(5, 100);  // Assign 5 elements with value 100
    std::cout << "After assign(5, 100): ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Using STL Algorithms with Vectors
 * @complexity Time: varies by algorithm
 */
void example6_Algorithms() {
    std::cout << "--- Algorithms with Vectors ---" << std::endl;

    std::vector<int> vec = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    std::cout << "Original: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 1. Sort - O(n log n)
    std::sort(vec.begin(), vec.end());
    std::cout << "After sort: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 2. Reverse - O(n)
    std::reverse(vec.begin(), vec.end());
    std::cout << "After reverse: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;

    // 3. Find - O(n)
    auto it = std::find(vec.begin(), vec.end(), 5);
    if (it != vec.end()) {
        std::cout << "Found 5 at index: " << (it - vec.begin()) << std::endl;
    }

    // 4. Count - O(n)
    int count = std::count(vec.begin(), vec.end(), 5);
    std::cout << "Count of 5: " << count << std::endl;

    // 5. Accumulate (sum) - O(n)
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of all elements: " << sum << std::endl;

    // 6. Transform - O(n)
    std::vector<int> doubled(vec.size());
    std::transform(vec.begin(), vec.end(), doubled.begin(),
                   [](int x) { return x * 2; });
    std::cout << "Doubled vector: ";
    for (int val : doubled) std::cout << val << " ";
    std::cout << std::endl;

    // 7. Remove-erase idiom - O(n)
    std::vector<int> vec2 = {1, 2, 3, 2, 4, 2, 5};
    std::cout << "Before removing 2s: ";
    for (int val : vec2) std::cout << val << " ";
    std::cout << std::endl;

    vec2.erase(std::remove(vec2.begin(), vec2.end(), 2), vec2.end());
    std::cout << "After removing 2s: ";
    for (int val : vec2) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 7: 2D Vector (Matrix)
 * @complexity Time: O(rows * cols) for initialization
 */
void example7_TwoDimensionalVector() {
    std::cout << "--- 2D Vector (Matrix) ---" << std::endl;

    // Create a 3x4 matrix
    int rows = 3, cols = 4;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

    // Fill matrix
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value++;
        }
    }

    // Display matrix
    std::cout << "3x4 Matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Jagged array (different row sizes)
    std::vector<std::vector<int>> jagged;
    jagged.push_back({1});
    jagged.push_back({2, 3});
    jagged.push_back({4, 5, 6});

    std::cout << "\nJagged Array:" << std::endl;
    for (const auto& row : jagged) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Simple class for demonstrating vector of custom objects
 */
class Student {
public:
    std::string name;
    int age;
    double gpa;

    Student(std::string n, int a, double g) : name(n), age(a), gpa(g) {}

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << std::endl;
    }
};

/**
 * @brief Example 8: Vector of Custom Objects
 * @complexity Time: O(n) for operations on n objects
 */
void example8_VectorOfCustomObjects() {
    std::cout << "--- Vector of Custom Objects ---" << std::endl;

    std::vector<Student> students;

    // Add students using push_back
    students.push_back(Student("Alice", 20, 3.8));
    students.push_back(Student("Bob", 21, 3.5));

    // Add students using emplace_back (more efficient - constructs in place)
    students.emplace_back("Charlie", 22, 3.9);
    students.emplace_back("Diana", 20, 3.7);

    // Display all students
    std::cout << "All students:" << std::endl;
    for (const auto& student : students) {
        student.display();
    }

    // Sort by GPA
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) { return a.gpa > b.gpa; });

    std::cout << "\nSorted by GPA (descending):" << std::endl;
    for (const auto& student : students) {
        student.display();
    }

    // Find student with GPA > 3.8
    auto it = std::find_if(students.begin(), students.end(),
                          [](const Student& s) { return s.gpa > 3.8; });

    if (it != students.end()) {
        std::cout << "\nFirst student with GPA > 3.8: " << std::endl;
        it->display();
    }

    std::cout << std::endl;
}

/**
 * @brief Main function demonstrating all vector examples
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "     STL Vector Comprehensive Examples  " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_CapacityManagement();
    example3_ElementAccess();
    example4_Iterators();
    example5_Modifiers();
    example6_Algorithms();
    example7_TwoDimensionalVector();
    example8_VectorOfCustomObjects();

    std::cout << "========================================" << std::endl;
    std::cout << "  All vector examples completed!        " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 VectorExample.cpp -o VectorExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 VectorExample.cpp -o VectorExample
 *
 * Run:
 *   ./VectorExample       (Linux/Mac)
 *   .\VectorExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. Vector is the default choice for most containers
 * 2. Reserve capacity when final size is known
 * 3. Use emplace_back for efficiency with complex objects
 * 4. Iterators can be invalidated by modifications
 * 5. Range-based for loops are the modern way to iterate
 */

