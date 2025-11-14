/**
 * @file LambdaExample.cpp
 * @brief Lambda Expressions
 * @date 2025-11-15
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    int sum = 0;
    std::for_each(v.begin(), v.end(), [&sum](int x) { sum += x; });
    std::cout << "Sum: " << sum << std::endl;

    auto multiply = [](int x, int y) { return x * y; };
    std::cout << "Product: " << multiply(3, 4) << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 LambdaExample.cpp -o  */
