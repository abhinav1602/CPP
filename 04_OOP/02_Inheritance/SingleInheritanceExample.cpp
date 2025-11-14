/**
 * @file SingleInheritanceExample.cpp
 * @brief Simple base/derived demonstration.
 * @date 2025-11-15
 */
#include <iostream>
class Animal { public: void speak() const { std::cout<<"Animal sound\n"; } };
class Dog : public Animal { public: void speak() const { std::cout<<"Woof\n"; } };

int main(){ Dog d; d.speak(); d.Animal::speak(); return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 SingleInheritanceExample.cpp -o SingleInheritanceExample */

