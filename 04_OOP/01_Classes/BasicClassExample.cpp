/**
 * @file BasicClassExample.cpp
 * @brief Basic class definition, encapsulation, getters/setters.
 * @date 2025-11-15
 */
#include <iostream>
#include <string>
class Person {
    std::string name; int age{};
public:
    Person(std::string n,int a):name(std::move(n)),age(a){}
    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    void setAge(int a){ age=a; }
};

int main(){
    Person p{"Alice",30};
    std::cout << p.getName() << ' ' << p.getAge() << '\n';
    p.setAge(31);
    std::cout << "After birthday: " << p.getAge() << '\n';
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 BasicClassExample.cpp -o BasicClassExample */

