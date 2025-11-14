/**
 * @file PointerArithmeticExample.cpp
 * @brief Focused deep-dive on pointer arithmetic patterns, offsets, strides, and safety considerations.
 * @author Learning Module
 * @date 2025-11-15
 */

#include <iostream>
#include <cstddef>
#include <iomanip>

void walkForward(const int* begin, const int* end) {
    std::cout << "  Forward: ";
    for (auto p = begin; p < end; ++p) std::cout << *p << ' ';
    std::cout << '\n';
}

void walkBackward(const int* begin, const int* end) {
    std::cout << "  Backward: ";
    for (auto p = end; p-- != begin; ) std::cout << *p << ' ';
    std::cout << *begin << '\n';
}

int main() {
    std::cout << "========================================" << '\n';
    std::cout << "  Pointer Arithmetic Deep Dive" << '\n';
    std::cout << "========================================" << '\n' << '\n';

    int data[8] = {10,20,30,40,50,60,70,80};
    int* begin = data;
    int* end   = data + 8; // one-past-last

    walkForward(begin, end);
    walkBackward(begin, end);

    // Offset access
    std::cout << "\n  Access offsets:" << '\n';
    for (std::size_t i = 0; i < 8; ++i) {
        std::cout << "    *(begin+" << i << ") = " << *(begin + i) << '\n';
    }

    // Strided access (every other element)
    std::cout << "\n  Strided (step=2): ";
    for (int* p = begin; p < end; p += 2) std::cout << *p << ' ';
    std::cout << '\n';

    // Difference between pointers
    std::cout << "\n  Pointer differences:" << '\n';
    int* mid = begin + 4;
    std::ptrdiff_t diff = mid - begin;
    std::cout << "    mid - begin = " << diff << " elements" << '\n';

    // Danger demonstration (do NOT dereference out-of-bounds!)
    std::cout << "\n  Safety: never dereference p >= end or p < begin" << '\n';

    std::cout << "\n========================================" << '\n';
    std::cout << "  Completed pointer arithmetic examples" << '\n';
    std::cout << "========================================" << '\n';
    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 PointerArithmeticExample.cpp -o PointerArithmeticExample
 */

