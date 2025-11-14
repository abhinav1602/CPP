/**
 * @file RemoveExample.cpp
 * @brief Examples of std::remove and the remove-erase idiom
 * @date 2025-11-15
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  STL Remove Algorithm & Remove-Erase Idiom" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    // remove (doesn't actually remove, just moves)
    std::cout << "--- std::remove (moves elements) ---" << std::endl;
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    std::cout << "Before: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << " (size=" << vec.size() << ")" << std::endl;

    auto new_end = std::remove(vec.begin(), vec.end(), 2);
    std::cout << "After remove (before erase): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << " (size=" << vec.size() << ")" << std::endl;

    // Remove-erase idiom
    std::cout << "\n--- Remove-Erase Idiom ---" << std::endl;
    vec.erase(new_end, vec.end());
    std::cout << "After erase: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << " (size=" << vec.size() << ")" << std::endl << std::endl;

    // remove_if
    std::cout << "--- std::remove_if with erase ---" << std::endl;
    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec.erase(
        std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; }),
        vec.end()
    );

    std::cout << "After removing odd numbers: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl << std::endl;

    std::cout << "========================================" << std::endl;
    return 0;
}

/*
 * Compilation: g++ -std=c++17 -Wall -Wextra -O2 RemoveExample.cpp -o RemoveExample
 *
 * Key: std::remove doesn't change container size. Use erase to actually remove!
 */

