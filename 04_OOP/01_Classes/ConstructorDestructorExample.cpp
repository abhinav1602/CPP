/**
 * @file ConstructorDestructorExample.cpp
 * @brief Demonstrates user-defined constructors, destructor, initialization list.
 * @date 2025-11-15
 */
#include <iostream>
#include <string>
class Logger {
    std::string name;
public:
    Logger():name("default"){ std::cout<<"Logger default ctor\n"; }
    explicit Logger(std::string n):name(std::move(n)){ std::cout<<"Logger param ctor("<<name<<")\n"; }
    Logger(const Logger& o):name(o.name){ std::cout<<"Logger copy ctor\n"; }
    ~Logger(){ std::cout<<"Logger dtor("<<name<<")\n"; }
};

int main(){
    Logger a; Logger b{"Session"}; Logger c{b};
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 ConstructorDestructorExample.cpp -o ConstructorDestructorExample */

