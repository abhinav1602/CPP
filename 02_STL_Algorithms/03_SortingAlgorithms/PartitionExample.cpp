/**
 * @file PartitionExample.cpp
 * @brief Examples of std::partition
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Partition Algorithm" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    std::cout << "--- std::partition (even first) ---" << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto partition_point = std::partition(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });

    std::cout << "After partition: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\nPartition point at index: " << std::distance(vec.begin(), partition_point) << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 PartitionExample.cpp -o PartitionExample */

