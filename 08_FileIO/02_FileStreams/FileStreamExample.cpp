/**
 * @file FileStreamExample.cpp
 * @brief File Streams
 * @date 2025-11-15
 */

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream ofs("data.txt");
    ofs << "Line 1" << std::endl << "Line 2" << std::endl;
    ofs.close();

    std::ifstream ifs("data.txt");
    std::string line;
    while(std::getline(ifs, line)) {
        std::cout << line << std::endl;
    }
    ifs.close();
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 FileStreamExample.cpp -o  */
