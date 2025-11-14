/**
 * @file MultipleInheritanceExample.cpp
 * @brief Multiple inheritance with interface-style bases.
 * @date 2025-11-15
 */
#include <iostream>

struct Printable { virtual void print() const =0; virtual ~Printable()=default; };
struct Identifiable { virtual int id() const =0; virtual ~Identifiable()=default; };

class Item : public Printable, public Identifiable {
    int value;
public:
    explicit Item(int v):value(v){}
    void print() const override { std::cout<<"Item("<<value<<")\n"; }
    int id() const override { return value; }
};

int main(){ Item it{42}; it.print(); std::cout << it.id() << '\n'; return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 MultipleInheritanceExample.cpp -o MultipleInheritanceExample */
