/**
 * @file CopyExample.cpp
 * @brief Examples of std::copy algorithms
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

void example1_BasicCopy();
void example2_CopyIf();
void example3_CopyN();
void example4_CopyBackward();

void example1_BasicCopy() {
    std::cout << "--- std::copy ---" << std::endl;
    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dest(src.size());

    std::copy(src.begin(), src.end(), dest.begin());

    std::cout << "Copied: ";
    for (int x : dest) std::cout << x << " ";
    std::cout << std::endl << std::endl;
}

void example2_CopyIf() {
    std::cout << "--- std::copy_if ---" << std::endl;
    std::vector<int> src = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> dest;

    std::copy_if(src.begin(), src.end(), std::back_inserter(dest), [](int x) { return x % 2 == 0; });

    std::cout << "Even numbers: ";
    for (int x : dest) std::cout << x << " ";
    std::cout << std::endl << std::endl;
}

void example3_CopyN() {
    std::cout << "--- std::copy_n ---" << std::endl;
    std::vector<int> src = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> dest;

    std::copy_n(src.begin(), 3, std::back_inserter(dest));

    std::cout << "First 3 elements: ";
    for (int x : dest) std::cout << x << " ";
    std::cout << std::endl << std::endl;
}

void example4_CopyBackward() {
    std::cout << "--- std::copy_backward ---" << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5, 0, 0, 0};

    std::copy_backward(vec.begin(), vec.begin() + 5, vec.end());

    std::cout << "After copy_backward: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Copy Algorithms" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    example1_BasicCopy();
    example2_CopyIf();
    example3_CopyN();
    example4_CopyBackward();

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 CopyExample.cpp -o CopyExample */

