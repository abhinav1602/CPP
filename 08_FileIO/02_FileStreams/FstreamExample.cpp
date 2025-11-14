/**
 * @file FstreamExample.cpp
 * @brief Demonstrates std::fstream read/write text.
 * @date 2025-11-15
 */
#include <iostream>
#include <fstream>
#include <string>
int main(){
    std::fstream fs("sample.txt", std::ios::out);
    fs << "Line1" << '\n' << "Line2" << '\n';
    fs.close();
    std::fstream in("sample.txt", std::ios::in);
    std::string line; std::cout << "File contents:\n";
    while(std::getline(in,line)) std::cout << line << '\n';
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 FstreamExample.cpp -o FstreamExample */

