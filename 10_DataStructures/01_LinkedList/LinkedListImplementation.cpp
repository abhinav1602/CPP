/**
 * @file LinkedListImplementation.cpp
 * @brief Singly linked list with push_front, push_back, find, remove.
 * @date 2025-11-15
 */

#include <iostream>
#include <memory>

struct Node {
    int value;
    std::unique_ptr<Node> next;
    explicit Node(int v) : value(v) {}
};

class LinkedList {
    std::unique_ptr<Node> head;
    Node* tail = nullptr;
public:
    void push_front(int v) {
        auto newNode = std::make_unique<Node>(v);
        if (!head) { tail = newNode.get(); }
        else { newNode->next = std::move(head); }
        head = std::move(newNode);
    }
    void push_back(int v) {
        auto newNode = std::make_unique<Node>(v);
        Node* raw = newNode.get();
        if (!head) {
            head = std::move(newNode);
            tail = raw;
        } else {
            tail->next = std::move(newNode);
            tail = raw;
        }
    }
    bool remove(int v) {
        Node* prev = nullptr;
        Node* curr = head.get();
        while (curr) {
            if (curr->value == v) {
                if (prev == nullptr) { // head removal
                    head = std::move(curr->next);
                    if (!head) tail = nullptr;
                } else {
                    prev->next = std::move(curr->next);
                    if (prev->next.get() == nullptr) tail = prev;
                }
                return true;
            }
            prev = curr;
            curr = curr->next.get();
        }
        return false;
    }
    void print() const {
        Node* curr = head.get();
        while (curr) { std::cout << curr->value << ' '; curr = curr->next.get(); }
        std::cout << '\n';
    }
};

int main() {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.push_back(3);
    list.print();
    list.remove(2);
    list.print();
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 LinkedListImplementation.cpp -o LinkedListImplementation */

