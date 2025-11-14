/**
 * @file StringStreamExample.cpp
 * @brief Demonstrates istringstream, ostringstream parsing and formatting.
 * @date 2025-11-15
 */

#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::cout << "=== String Stream Parsing ===\n";
    std::string line = "42 3.14 hello";
    std::istringstream iss(line);
    int i; double d; std::string s;
    iss >> i >> d >> s;
    std::cout << "Parsed: i=" << i << " d=" << d << " s=" << s << '\n';

    std::ostringstream oss;
    oss << "Value=" << i << ", Double=" << d << ", Word=" << s;
    std::cout << "Composed: " << oss.str() << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 StringStreamExample.cpp -o StringStreamExample */

