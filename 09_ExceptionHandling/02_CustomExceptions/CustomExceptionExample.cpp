/**
 * @file CustomExceptionExample.cpp
 * @brief Demonstrates custom exception class deriving from std::exception.
 * @date 2025-11-15
 */
#include <iostream>
#include <exception>
#include <string>

class MyError : public std::exception {
    std::string msg;
public:
    explicit MyError(std::string m):msg(std::move(m)){}
    const char* what() const noexcept override { return msg.c_str(); }
};

int main(){
    try { throw MyError("Something failed"); }
    catch(const MyError& e){ std::cout<<"Custom caught: "<<e.what()<<'\n'; }
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 CustomExceptionExample.cpp -o CustomExceptionExample */
