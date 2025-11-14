/**
 * @file BinaryFileExample.cpp
 * @brief Demonstrates binary file write/read using std::ofstream/ifstream.
 * @date 2025-11-15
 */
#include <iostream>
#include <fstream>
#include <vector>

int main(){
    std::vector<int> nums{1,2,3,4,5};
    {
        std::ofstream out("data.bin", std::ios::binary);
        out.write(reinterpret_cast<const char*>(nums.data()), nums.size()*sizeof(int));
    }
    std::vector<int> loaded(5);
    {
        std::ifstream in("data.bin", std::ios::binary);
        in.read(reinterpret_cast<char*>(loaded.data()), loaded.size()*sizeof(int));
    }
    std::cout << "Loaded: "; for(int v: loaded) std::cout<<v<<' '; std::cout<<'\n';
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 BinaryFileExample.cpp -o BinaryFileExample */
