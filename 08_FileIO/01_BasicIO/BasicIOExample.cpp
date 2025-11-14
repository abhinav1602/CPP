/**
 * @file BasicIOExample.cpp
 * @brief Basic IO
 * @date 2025-11-15
 */

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream out("test.txt");
    out << "Hello File IO!" << std::endl;
    out.close();

    std::ifstream in("test.txt");
    std::string line;
    std::getline(in, line);
    std::cout << "Read: " << line << std::endl;
    in.close();
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 BasicIOExample.cpp -o  */
