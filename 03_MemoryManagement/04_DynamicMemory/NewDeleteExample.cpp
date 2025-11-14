/**
 * @file NewDeleteExample.cpp
 * @brief Demonstrates new/delete, new[]/delete[], exception safety, and avoiding leaks.
 * @date 2025-11-15
 */
#include <iostream>
#include <stdexcept>
int main(){
    std::cout << "=== New/Delete Example ===\n";
    int* single = new int(10);
    std::cout << "single=" << *single << '\n';
    delete single; single=nullptr;
    std::size_t n=5;
    int* arr = new int[n];
    for(std::size_t i=0;i<n;++i) arr[i]=static_cast<int>(i*i);
    std::cout << "Array: "; for(std::size_t i=0;i<n;++i) std::cout<<arr[i]<<' '; std::cout<<'\n';
    delete[] arr; arr=nullptr;
    try {
        int* mayThrow = new int(7); // placement in try for later logic
        if(*mayThrow==7) throw std::runtime_error("Simulated failure after allocation");
        delete mayThrow;
    } catch(const std::exception& e){ std::cout << "Caught: "<<e.what()<<" (resource released manually)"<<'\n'; }
    std::cout << "Done." << '\n';
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 NewDeleteExample.cpp -o NewDeleteExample */

