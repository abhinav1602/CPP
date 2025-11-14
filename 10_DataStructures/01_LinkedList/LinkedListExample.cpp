/**
 * @file LinkedListExample.cpp
 * @brief Linked List Implementation
 * @date 2025-11-15
 */

#include <iostream>
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        while(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void print() {
        Node* curr = head;
        while(curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.push(3);
    list.push(2);
    list.push(1);
    list.print();
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 LinkedListExample.cpp -o  */
