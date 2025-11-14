/**
 * @file TransformExample.cpp
 * @brief Examples of std::transform
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Transform Algorithm" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    // Unary transform
    std::cout << "--- Unary transform (x * 2) ---" << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> result(vec.size());

    std::transform(vec.begin(), vec.end(), result.begin(), [](int x) { return x * 2; });

    std::cout << "Result: ";
    for (int x : result) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    // Binary transform
    std::cout << "--- Binary transform (addition) ---" << std::endl;
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {10, 20, 30, 40, 50};
    std::vector<int> sum(v1.size());

    std::transform(v1.begin(), v1.end(), v2.begin(), sum.begin(), std::plus<int>());

    std::cout << "Sum: ";
    for (int x : sum) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 TransformExample.cpp -o TransformExample */

