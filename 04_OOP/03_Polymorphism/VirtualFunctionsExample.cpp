/**
 * @file VirtualFunctionsExample.cpp
 * @brief Virtual dispatch demonstration.
 * @date 2025-11-15
 */
#include <iostream>
#include <memory>

struct Shape { virtual double area() const =0; virtual ~Shape()=default; };
struct Circle : Shape { double r; explicit Circle(double rr):r(rr){} double area() const override { return 3.14159*r*r; } };
struct Square : Shape { double s; explicit Square(double ss):s(ss){} double area() const override { return s*s; } };

int main(){ std::unique_ptr<Shape> s1 = std::make_unique<Circle>(2.0); std::unique_ptr<Shape> s2 = std::make_unique<Square>(3.0); std::cout<<s1->area()<<' '<<s2->area()<<'\n'; return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 VirtualFunctionsExample.cpp -o VirtualFunctionsExample */
