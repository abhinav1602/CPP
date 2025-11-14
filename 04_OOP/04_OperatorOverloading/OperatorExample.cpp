#include <iostream>
class Complex {
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};
int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}
