/**
 * @file RawPointersExample.cpp
 * @brief Comprehensive examples covering raw pointers, pointer basics, pointer arithmetic, arrays, function pointers, and pitfalls.
 * @author Learning Module
 * @date 2025-11-15
 *
 * This file demonstrates:
 *  - Declaring and initializing raw pointers
 *  - Dereferencing and modifying pointed-to data
 *  - Pointer arithmetic with arrays
 *  - Traversing arrays via pointers
 *  - Function pointers and callback usage
 *  - Common pitfalls: dangling pointers, double delete, memory leaks
 *  - Best practices to avoid raw pointer misuse
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <functional>

// Forward declarations of examples
void example1_BasicDeclaration();
void example2_DynamicAllocation();
void example3_PointerArithmetic();
void example4_FunctionPointers();
void example5_DanglingPointerPitfall();
void example6_MultiDimensionalTraversal();
void example7_PointerVsIndexPerformance();

// Utility function used in example4
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

/**
 * @brief Example 1: Basic declaration & dereference
 * @complexity Time: O(1), Space: O(1)
 */
void example1_BasicDeclaration() {
    std::cout << "[1] Basic Declaration & Dereference" << '\n';
    int value = 42;              // Automatic storage variable
    int* ptr = &value;           // Pointer holds address of value
    std::cout << "  value=" << value << ", *ptr=" << *ptr << '\n';

    *ptr = 100; // Modify through pointer
    std::cout << "  After *ptr=100 -> value=" << value << '\n';

    // Null pointer pattern
    int* nullPtr = nullptr;      // Always initialize pointers
    std::cout << "  nullPtr == nullptr -> " << std::boolalpha << (nullPtr == nullptr) << '\n';
    std::cout << '\n';
}

/**
 * @brief Example 2: Dynamic allocation & manual memory management
 * @complexity Time: O(n) for initialization, Space: O(n)
 */
void example2_DynamicAllocation() {
    std::cout << "[2] Dynamic Allocation" << '\n';
    std::size_t n = 5;
    int* arr = new int[n]; // Allocate raw dynamic array

    // Initialize
    for (std::size_t i = 0; i < n; ++i) {
        arr[i] = static_cast<int>(i * i); // Use index style for clarity
    }

    // Display using pointer iteration
    std::cout << "  Values: ";
    for (int* p = arr; p < arr + n; ++p) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    // ALWAYS delete what you new
    delete[] arr; // Correct matching delete[] for new[]
    std::cout << "  Memory released (delete[])." << '\n';
    std::cout << '\n';
}

/**
 * @brief Example 3: Pointer arithmetic & traversal patterns
 * @complexity Time: O(n), Space: O(1)
 */
void example3_PointerArithmetic() {
    std::cout << "[3] Pointer Arithmetic" << '\n';
    int data[6] = {2,4,6,8,10,12};
    int* begin = data;           // Points to first element
    int* end   = data + 6;       // One-past-last

    std::cout << "  Forward traversal: ";
    for (int* p = begin; p != end; ++p) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    std::cout << "  Backward traversal: ";
    for (int* p = end - 1; p >= begin; --p) {
        std::cout << *p << ' ';
        if (p == begin) break; // Prevent underflow of pointer
    }
    std::cout << '\n';

    // Offset access
    std::cout << "  *(begin+3)=" << *(begin + 3) << " (should be 8)" << '\n';
    std::cout << '\n';
}

/**
 * @brief Example 4: Function pointers & callbacks
 * @complexity Time: O(1) per call, Space: O(1)
 */
void example4_FunctionPointers() {
    std::cout << "[4] Function Pointers" << '\n';

    // Basic function pointer signature
    int (*op)(int,int) = add; // Assign add
    std::cout << "  add(3,4) via pointer = " << op(3,4) << '\n';

    op = multiply;            // Reassign to multiply
    std::cout << "  multiply(3,4) via pointer = " << op(3,4) << '\n';

    // Array of function pointers
    int (*operations[2])(int,int) = {add, multiply};
    std::cout << "  operations[0](5,6)=" << operations[0](5,6) << '\n';
    std::cout << "  operations[1](5,6)=" << operations[1](5,6) << '\n';

    // Modern alternative: std::function
    std::function<int(int,int)> fn = add;
    std::cout << "  std::function add(10,2)=" << fn(10,2) << '\n';
    fn = multiply;
    std::cout << "  std::function multiply(10,2)=" << fn(10,2) << '\n';
    std::cout << '\n';
}

/**
 * @brief Example 5: Dangling pointer pitfall
 * @complexity Time: O(1), Space: O(1)
 */
void example5_DanglingPointerPitfall() {
    std::cout << "[5] Dangling Pointer Pitfall" << '\n';
    int* ptr = new int(55);
    std::cout << "  *ptr before delete = " << *ptr << '\n';
    delete ptr; // Memory freed
    ptr = nullptr; // Mitigate dangling pointer risk
    std::cout << "  Set ptr to nullptr after delete (good practice)." << '\n';
    std::cout << '\n';
}

/**
 * @brief Example 6: Multi-dimensional traversal using pointers
 * @complexity Time: O(rows*cols), Space: O(rows*cols)
 */
void example6_MultiDimensionalTraversal() {
    std::cout << "[6] 2D Array Traversal" << '\n';
    const int ROWS = 3;
    const int COLS = 4;
    int matrix[ROWS][COLS] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    // Treat matrix as contiguous block
    int* raw = &matrix[0][0];
    std::cout << "  Flat traversal: ";
    for (int* p = raw; p < raw + ROWS * COLS; ++p) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    std::cout << "  Row/Col traversal: \n";
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            std::cout << std::setw(3) << matrix[r][c];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

/**
 * @brief Example 7: Pointer vs index traversal small benchmark concept (illustrative only)
 * @complexity Time: O(n)
 */
void example7_PointerVsIndexPerformance() {
    std::cout << "[7] Pointer vs Index Traversal (Illustrative)" << '\n';
    const int N = 10; // Keep small for demo; real benchmark would use large N
    int arr[N];
    for (int i = 0; i < N; ++i) arr[i] = i;

    int sumIndex = 0;
    for (int i = 0; i < N; ++i) sumIndex += arr[i];

    int sumPointer = 0;
    for (int* p = arr; p < arr + N; ++p) sumPointer += *p;

    std::cout << "  sumIndex=" << sumIndex << ", sumPointer=" << sumPointer << '\n';
    std::cout << "  (Performance differences are compiler & context dependent)" << '\n';
    std::cout << '\n';
}

int main() {
    std::cout << "========================================" << '\n';
    std::cout << "  Raw Pointers Comprehensive Examples" << '\n';
    std::cout << "========================================" << '\n' << '\n';

    example1_BasicDeclaration();
    example2_DynamicAllocation();
    example3_PointerArithmetic();
    example4_FunctionPointers();
    example5_DanglingPointerPitfall();
    example6_MultiDimensionalTraversal();
    example7_PointerVsIndexPerformance();

    std::cout << "========================================" << '\n';
    std::cout << "  All raw pointer examples completed." << '\n';
    std::cout << "========================================" << '\n';
    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 RawPointersExample.cpp -o RawPointersExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 RawPointersExample.cpp -o RawPointersExample
 * Run:
 *   ./RawPointersExample
 *
 * Key Takeaways:
 *  1. Always initialize pointers (nullptr if no valid target).
 *  2. Match new[] with delete[] and new with delete.
 *  3. Pointer arithmetic is powerful but easy to misuse—prefer std::array/std::vector.
 *  4. After delete, set pointer to nullptr to avoid dangling usage.
 *  5. Prefer smart pointers for ownership semantics (see SmartPointersExample).
 *  6. Function pointers are flexible; modern code prefers std::function or lambdas.
 */

