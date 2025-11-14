#include <iostream>
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};
class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double area() const override { return 3.14159 * r * r; }
};
int main() {
    Shape* s = new Circle(5.0);
    std::cout << "Area: " << s->area() << std::endl;
    delete s;
    return 0;
}
