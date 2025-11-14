/**
 * @file OperatorOverloadingExample.cpp
 * @brief Demonstrates operator overloading (+=, +, <<) for custom type.
 * @date 2025-11-15
 */
#include <iostream>

class Vector2 {
    double x{}, y{};
public:
    Vector2()=default; Vector2(double xx,double yy):x(xx),y(yy){}
    Vector2& operator+=(const Vector2& o){ x+=o.x; y+=o.y; return *this; }
    friend Vector2 operator+(Vector2 a,const Vector2& b){ a+=b; return a; }
    friend std::ostream& operator<<(std::ostream& os,const Vector2& v){ return os<<'('<<v.x<<','<<v.y<<')'; }
};

int main(){ Vector2 a{1,2}, b{3,4}; std::cout << (a+b) << '\n'; return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 OperatorOverloadingExample.cpp -o OperatorOverloadingExample */
