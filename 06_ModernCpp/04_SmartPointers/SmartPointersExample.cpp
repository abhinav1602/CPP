/**
 * @file SmartPointersExample.cpp
 * @brief Modern C++ smart pointer patterns (unique_ptr, shared_ptr, weak_ptr) with best practices.
 * @date 2025-11-15
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>

struct Resource {
    std::string name;
    explicit Resource(std::string n) : name(std::move(n)) {
        std::cout << "Resource(" << name << ") acquired\n";
    }
    ~Resource() { std::cout << "Resource(" << name << ") released\n"; }
};

std::unique_ptr<Resource> makeUnique(const std::string& n) {
    return std::make_unique<Resource>(n);
}

void sharedOwnershipDemo() {
    auto r1 = std::make_shared<Resource>("SharedA");
    {
        auto r2 = r1; // increment ref count
        std::cout << "  r1.use_count=" << r1.use_count() << '\n';
    }
    std::cout << "  After inner scope r1.use_count=" << r1.use_count() << '\n';
}

void weakObservationDemo() {
    std::weak_ptr<Resource> weak;
    {
        auto sp = std::make_shared<Resource>("Observed");
        weak = sp;
        std::cout << "  Inside: expired=" << std::boolalpha << weak.expired() << '\n';
    }
    std::cout << "  Outside: expired=" << std::boolalpha << weak.expired() << '\n';
}

int main() {
    std::cout << "========================================\n";
    std::cout << "  Modern Smart Pointer Patterns\n";
    std::cout << "========================================\n\n";

    std::cout << "[1] unique_ptr factory" << '\n';
    auto u = makeUnique("UniqueA");
    std::cout << "  Using resource: " << u->name << '\n';

    std::cout << "\n[2] shared_ptr ownership counting" << '\n';
    sharedOwnershipDemo();

    std::cout << "\n[3] weak_ptr observation" << '\n';
    weakObservationDemo();

    std::cout << "\n========================================\n";
    std::cout << "  Smart pointer examples complete\n";
    std::cout << "========================================\n";
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 SmartPointersExample.cpp -o SmartPointersExample */

