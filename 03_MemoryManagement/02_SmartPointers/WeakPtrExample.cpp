/**
 * @file WeakPtrExample.cpp
 * @brief Demonstrates std::weak_ptr usage to observe shared objects without affecting lifetime.
 * @date 2025-11-15
 */

#include <iostream>
#include <memory>

struct Payload {
    int id;
    explicit Payload(int i) : id(i) { std::cout << "Payload(" << id << ") constructed\n"; }
    ~Payload() { std::cout << "Payload(" << id << ") destroyed\n"; }
};

int main() {
    std::weak_ptr<Payload> observer; // Empty
    {
        auto sp = std::make_shared<Payload>(10);
        observer = sp; // weak observation
        std::cout << "Inside scope: expired? " << std::boolalpha << observer.expired() << '\n';
        if (auto locked = observer.lock()) {
            std::cout << "  Locked id=" << locked->id << '\n';
        }
    } // sp destroyed here

    std::cout << "Outside scope: expired? " << std::boolalpha << observer.expired() << '\n';
    if (auto locked = observer.lock()) {
        std::cout << "Should not print (object still alive) id=" << locked->id << '\n';
    } else {
        std::cout << "  Cannot lock (object destroyed)." << '\n';
    }
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 WeakPtrExample.cpp -o WeakPtrExample */

