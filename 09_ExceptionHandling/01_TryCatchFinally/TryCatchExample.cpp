/**
 * @file TryCatchExample.cpp
 * @brief Demonstrates try/catch blocks and exception propagation.
 * @date 2025-11-15
 */
#include <iostream>
#include <stdexcept>

int risky(int x){ if(x==0) throw std::runtime_error("zero!"); return 100/x; }

int main(){
    try { std::cout<<risky(5)<<'\n'; std::cout<<risky(0)<<'\n'; }
    catch(const std::exception& e){ std::cout<<"Caught: "<<e.what()<<'\n'; }
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 TryCatchExample.cpp -o TryCatchExample */
