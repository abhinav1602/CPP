#include <iostream>
#include <memory>
int main() {
    std::cout << "Custom Allocator Example" << std::endl;
    std::allocator<int> alloc;
    int* p = alloc.allocate(1);
    alloc.construct(p, 42);
    std::cout << "Value: " << *p << std::endl;
    alloc.destroy(p);
    alloc.deallocate(p, 1);
    return 0;
}
