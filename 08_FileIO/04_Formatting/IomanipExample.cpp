/**
 * @file IomanipExample.cpp
 * @brief Demonstrates formatting with <iomanip>: setw, setfill, fixed, setprecision.
 * @date 2025-11-15
 */

#include <iostream>
#include <iomanip>

int main() {
    std::cout << "=== Formatting with iomanip ===\n";
    double val = 3.1415926535;
    std::cout << "Default: " << val << '\n';
    std::cout << std::fixed << std::setprecision(2) << "Fixed(2): " << val << '\n';
    std::cout << std::setw(10) << std::setfill('.') << "Aligned" << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 IomanipExample.cpp -o IomanipExample */

