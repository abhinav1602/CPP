#include <iostream>
int main() {
    std::cout << "Dynamic Memory Example" << std::endl;
    int* p = new int(42);
    std::cout << "Value: " << *p << std::endl;
    delete p;
    return 0;
}
