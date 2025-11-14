/**
 * @file PointersAndArraysExample.cpp
 * @brief Raw pointers with arrays: indexing vs pointer iteration, multi-level pointers, const correctness.
 * @date 2025-11-15
 */
#include <iostream>
#include <cstddef>
void printIndex(const int* a, std::size_t n) {
    for (std::size_t i=0;i<n;++i) std::cout << a[i] << ' '; std::cout << '\n';
}
void printPointer(const int* a, std::size_t n) {
    for (const int* p=a; p<a+n; ++p) std::cout << *p << ' '; std::cout << '\n';
}

int main(){
    std::cout << "=== Pointers And Arrays Example ===\n";
    int arr[6]{1,2,3,4,5,6};
    std::cout << "Index: "; printIndex(arr,6);
    std::cout << "Pointer: "; printPointer(arr,6);
    const int* constPtr = arr; // pointer to const int
    std::cout << "First via const pointer=" << *constPtr << '\n';
    int* p = arr; *(p+2)=99; // modify third element
    std::cout << "After *(p+2)=99: "; printIndex(arr,6);
    int** pp = &p; (*pp)[0] = 42; std::cout << "After double pointer modify first: "; printIndex(arr,6);
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 PointersAndArraysExample.cpp -o PointersAndArraysExample */

