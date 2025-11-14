/**
 * @file AccumulateExample.cpp
 * @brief Examples of std::accumulate
 * @date 2025-11-15
 */

#include <iostream>
#include <numeric>
#include <vector>
#include <functional>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Accumulate Algorithm" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Sum
    std::cout << "--- Sum ---" << std::endl;
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum: " << sum << std::endl << std::endl;

    // Product
    std::cout << "--- Product ---" << std::endl;
    int product = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
    std::cout << "Product: " << product << std::endl << std::endl;

    // Custom operation
    std::cout << "--- Custom (concatenate) ---" << std::endl;
    std::vector<std::string> words = {"Hello", " ", "World", "!"};
    std::string result = std::accumulate(words.begin(), words.end(), std::string(""));
    std::cout << "Result: " << result << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 AccumulateExample.cpp -o AccumulateExample */

