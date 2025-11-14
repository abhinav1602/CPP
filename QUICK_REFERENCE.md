# 🚀 C++ Quick Reference Guide

**Complete syntax reference for all 10 modules**

---

## 📋 Table of Contents

1. [STL Containers](#module-01-stl-containers)
2. [STL Algorithms](#module-02-stl-algorithms)
3. [Memory Management](#module-03-memory-management)
4. [OOP](#module-04-oop)
5. [Templates](#module-05-templates)
6. [Modern C++](#module-06-modern-c)
7. [Multithreading](#module-07-multithreading)
8. [File I/O](#module-08-file-io)
9. [Exception Handling](#module-09-exception-handling)
10. [Data Structures](#module-10-data-structures)

---

## Module 01: STL Containers

### Sequence Containers

```cpp
// Vector - dynamic array
std::vector<int> v = {1, 2, 3};
v.push_back(4);           // Add to end
v.pop_back();             // Remove from end
v[0] = 10;                // Access by index
v.size(), v.capacity();   // Size and capacity
v.reserve(100);           // Reserve capacity

// Deque - double-ended queue
std::deque<int> d = {1, 2, 3};
d.push_front(0);          // Add to front
d.push_back(4);           // Add to back
d.pop_front();            // Remove from front

// List - doubly-linked list
std::list<int> l = {1, 2, 3};
l.push_front(0);
l.push_back(4);
l.sort();                 // In-place sort
l.reverse();              // Reverse order

// Array - fixed-size array
std::array<int, 5> arr = {1, 2, 3, 4, 5};
arr.size();               // Always compile-time constant
arr.fill(0);              // Fill with value
```

### Associative Containers (Ordered)

```cpp
// Set - unique sorted elements
std::set<int> s = {3, 1, 4, 1, 5};  // {1, 3, 4, 5}
s.insert(2);              // O(log n)
s.erase(3);               // O(log n)
s.find(4) != s.end();     // Check existence
s.count(5);               // 0 or 1

// Map - key-value pairs
std::map<string, int> m;
m["key"] = 100;           // Insert/update
m.at("key");              // Access with bounds check
m.find("key");            // Find iterator
m.erase("key");           // Remove

// Multiset/Multimap - allow duplicates
std::multiset<int> ms = {1, 1, 2, 2, 3};
ms.count(1);              // Returns 2
auto [first, last] = ms.equal_range(1);  // Range of all 1s
```

### Unordered Containers (Hash-based)

```cpp
// Unordered Set - O(1) average
std::unordered_set<int> us = {1, 2, 3};
us.insert(4);             // O(1) average
us.find(2);               // O(1) average
us.bucket_count();        // Number of buckets
us.load_factor();         // Average elements per bucket

// Unordered Map - O(1) average
std::unordered_map<string, int> um;
um["key"] = 100;          // O(1) average
um.at("key");             // O(1) average with bounds check
```

### Container Adaptors

```cpp
// Stack - LIFO
std::stack<int> stk;
stk.push(10);
stk.top();                // Access top
stk.pop();                // Remove top

// Queue - FIFO
std::queue<int> q;
q.push(10);
q.front();                // Access front
q.back();                 // Access back
q.pop();                  // Remove front

// Priority Queue - Max heap by default
std::priority_queue<int> pq;
pq.push(10);
pq.top();                 // Largest element
pq.pop();                 // Remove largest

// Min heap
std::priority_queue<int, vector<int>, greater<int>> minPQ;
```

---

## Module 02: STL Algorithms

### Non-Modifying Algorithms

```cpp
#include <algorithm>

std::vector<int> v = {1, 2, 3, 4, 5};

// Find
auto it = std::find(v.begin(), v.end(), 3);

// Count
int cnt = std::count(v.begin(), v.end(), 3);

// All/Any/None
bool all = std::all_of(v.begin(), v.end(), [](int x){ return x > 0; });
bool any = std::any_of(v.begin(), v.end(), [](int x){ return x > 3; });
bool none = std::none_of(v.begin(), v.end(), [](int x){ return x < 0; });
```

### Modifying Algorithms

```cpp
// Copy
std::vector<int> dest(v.size());
std::copy(v.begin(), v.end(), dest.begin());

// Transform
std::transform(v.begin(), v.end(), v.begin(), [](int x){ return x * 2; });

// Replace
std::replace(v.begin(), v.end(), 3, 99);

// Remove-erase idiom
v.erase(std::remove(v.begin(), v.end(), 3), v.end());

// Fill
std::fill(v.begin(), v.end(), 0);
```

### Sorting Algorithms

```cpp
// Sort
std::sort(v.begin(), v.end());                    // Ascending
std::sort(v.begin(), v.end(), std::greater<>());  // Descending

// Stable sort (preserves relative order)
std::stable_sort(v.begin(), v.end());

// Partial sort
std::partial_sort(v.begin(), v.begin() + 3, v.end());

// Nth element
std::nth_element(v.begin(), v.begin() + 5, v.end());

// Binary search (requires sorted range)
bool found = std::binary_search(v.begin(), v.end(), 3);
```

### Numeric Algorithms

```cpp
#include <numeric>

// Accumulate (sum)
int sum = std::accumulate(v.begin(), v.end(), 0);

// Inner product (dot product)
int dotProduct = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);

// Adjacent difference
std::adjacent_difference(v.begin(), v.end(), dest.begin());

// Iota (fill with incrementing values)
std::iota(v.begin(), v.end(), 0);  // 0, 1, 2, 3, ...
```

---

## Module 03: Memory Management

### Raw Pointers

```cpp
int* ptr = new int(10);        // Allocate
*ptr = 20;                     // Dereference
delete ptr;                    // Deallocate

int* arr = new int[10];        // Array allocation
delete[] arr;                  // Array deallocation

// Function pointers
int (*funcPtr)(int, int) = &add;
int result = funcPtr(5, 3);
```

### Smart Pointers

```cpp
#include <memory>

// Unique pointer - exclusive ownership
std::unique_ptr<int> up1 = std::make_unique<int>(10);
std::unique_ptr<int> up2 = std::move(up1);  // Transfer ownership

// Shared pointer - shared ownership
std::shared_ptr<int> sp1 = std::make_shared<int>(10);
std::shared_ptr<int> sp2 = sp1;  // Reference count = 2
sp1.use_count();                 // Get reference count

// Weak pointer - non-owning reference
std::weak_ptr<int> wp = sp1;
if (auto sp = wp.lock()) {       // Convert to shared_ptr
    // Use sp
}

// Custom deleter
auto deleter = [](FILE* f){ fclose(f); };
std::unique_ptr<FILE, decltype(deleter)> fp(fopen("file.txt", "r"), deleter);
```

### RAII Pattern

```cpp
class ResourceGuard {
    Resource* res;
public:
    ResourceGuard() : res(acquire()) {}
    ~ResourceGuard() { release(res); }
    
    // Delete copy
    ResourceGuard(const ResourceGuard&) = delete;
    ResourceGuard& operator=(const ResourceGuard&) = delete;
};
```

---

## Module 04: OOP

### Classes

```cpp
class MyClass {
private:
    int data;
    static int count;
    
public:
    // Constructor
    MyClass(int d) : data(d) { ++count; }
    
    // Methods
    int getData() const { return data; }
    void setData(int d) { data = d; }
    
    // Static method
    static int getCount() { return count; }
};

int MyClass::count = 0;
```

### Inheritance

```cpp
// Single inheritance
class Derived : public Base {
public:
    void method() override;
};

// Multiple inheritance
class Derived : public Base1, public Base2 {
};

// Virtual inheritance (diamond problem)
class Derived : virtual public Base {
};
```

### Polymorphism

```cpp
class Base {
public:
    virtual void method() = 0;  // Pure virtual (abstract)
    virtual ~Base() {}          // Virtual destructor
};

class Derived : public Base {
public:
    void method() override {    // Override keyword (C++11)
        // Implementation
    }
};

Base* ptr = new Derived();
ptr->method();                  // Dynamic dispatch
delete ptr;
```

### Operator Overloading

```cpp
class Complex {
    double real, imag;
public:
    // Binary operators
    Complex operator+(const Complex& other) const {
        return {real + other.real, imag + other.imag};
    }
    
    // Comparison
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }
    
    // Stream operators (friend functions)
    friend ostream& operator<<(ostream& os, const Complex& c) {
        return os << c.real << " + " << c.imag << "i";
    }
};
```

### Rule of Five

```cpp
class MyClass {
public:
    // 1. Destructor
    ~MyClass();
    
    // 2. Copy constructor
    MyClass(const MyClass& other);
    
    // 3. Copy assignment
    MyClass& operator=(const MyClass& other);
    
    // 4. Move constructor
    MyClass(MyClass&& other) noexcept;
    
    // 5. Move assignment
    MyClass& operator=(MyClass&& other) noexcept;
};
```

---

## Module 05: Templates

### Function Templates

```cpp
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int x = max(10, 20);           // T deduced as int
double y = max(1.5, 2.5);      // T deduced as double
```

### Class Templates

```cpp
template<typename T>
class Container {
    T data;
public:
    Container(T d) : data(d) {}
    T get() const { return data; }
};

Container<int> c1(10);
Container<string> c2("hello");
```

### Template Specialization

```cpp
// Primary template
template<typename T>
class Wrapper {
    T value;
};

// Full specialization
template<>
class Wrapper<bool> {
    unsigned char value;
};

// Partial specialization
template<typename T>
class Wrapper<T*> {
    T* ptr;
};
```

### Variadic Templates

```cpp
// Base case
void print() {}

// Recursive case
template<typename T, typename... Args>
void print(T first, Args... args) {
    cout << first << " ";
    print(args...);
}

print(1, 2.5, "hello", 'c');

// C++17 fold expressions
template<typename... Args>
auto sum(Args... args) {
    return (args + ...);
}
```

### Concepts (C++20)

```cpp
template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

template<Numeric T>
T add(T a, T b) {
    return a + b;
}
```

---

## Module 06: Modern C++

### Auto & Decltype

```cpp
auto x = 10;                   // int
auto y = 3.14;                 // double
auto z = "hello";              // const char*

decltype(x) a = 20;            // Same type as x
decltype(auto) b = (x);        // Reference if x is lvalue
```

### Lambda Expressions

```cpp
// Basic lambda
auto lambda = [](int x) { return x * 2; };

// Capture by value
int y = 10;
auto lambda2 = [y](int x) { return x + y; };

// Capture by reference
auto lambda3 = [&y](int x) { y = x; };

// Capture all by value/reference
auto lambda4 = [=](int x) { /* ... */ };
auto lambda5 = [&](int x) { /* ... */ };

// Generic lambda (C++14)
auto lambda6 = [](auto x, auto y) { return x + y; };

// Constexpr lambda (C++17)
constexpr auto lambda7 = [](int x) { return x * 2; };
```

### Move Semantics

```cpp
// Move constructor/assignment
class MyClass {
    int* data;
public:
    MyClass(MyClass&& other) noexcept 
        : data(other.data) {
        other.data = nullptr;
    }
    
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};

// std::move
MyClass obj1;
MyClass obj2 = std::move(obj1);  // Move, not copy

// Perfect forwarding
template<typename T>
void wrapper(T&& arg) {
    function(std::forward<T>(arg));
}
```

### Structured Bindings (C++17)

```cpp
std::pair<int, string> p = {1, "hello"};
auto [id, name] = p;           // Decompose pair

std::map<int, string> m = {{1, "one"}, {2, "two"}};
for (const auto& [key, value] : m) {
    cout << key << ": " << value << endl;
}

std::array<int, 3> arr = {1, 2, 3};
auto [a, b, c] = arr;
```

### Constexpr

```cpp
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

constexpr int x = factorial(5);  // Computed at compile time

// constexpr if (C++17)
template<typename T>
auto getValue(T t) {
    if constexpr (std::is_pointer_v<T>)
        return *t;
    else
        return t;
}
```

---

## Module 07: Multithreading

### Threads

```cpp
#include <thread>

void function() { /* ... */ }

std::thread t1(function);      // Create thread
std::thread t2([]{ /* ... */ }); // With lambda

t1.join();                     // Wait for completion
t2.detach();                   // Run independently

// With parameters
std::thread t3(function, arg1, arg2);
```

### Synchronization

```cpp
#include <mutex>

std::mutex mtx;

// Lock guard (RAII)
{
    std::lock_guard<std::mutex> lock(mtx);
    // Critical section
}

// Unique lock (more flexible)
std::unique_lock<std::mutex> lock(mtx);
lock.unlock();
lock.lock();

// Scoped lock (multiple mutexes, C++17)
std::scoped_lock lock(mtx1, mtx2);
```

### Condition Variables

```cpp
#include <condition_variable>

std::condition_variable cv;
std::mutex mtx;
bool ready = false;

// Wait
std::unique_lock<std::mutex> lock(mtx);
cv.wait(lock, []{ return ready; });

// Notify
{
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
}
cv.notify_one();   // or notify_all()
```

### Atomic

```cpp
#include <atomic>

std::atomic<int> counter(0);
counter++;                     // Atomic increment
counter.fetch_add(1);          // Explicit atomic add
counter.load();                // Atomic load
counter.store(10);             // Atomic store

// Compare and swap
int expected = 5;
counter.compare_exchange_strong(expected, 10);
```

### Async & Futures

```cpp
#include <future>

// Async
std::future<int> result = std::async(std::launch::async, []{ 
    return 42; 
});
int value = result.get();      // Block until ready

// Promise & Future
std::promise<int> prom;
std::future<int> fut = prom.get_future();
prom.set_value(42);
int val = fut.get();

// Packaged task
std::packaged_task<int()> task([]{ return 42; });
std::future<int> fut2 = task.get_future();
task();
```

---

## Module 08: File I/O

### Basic I/O

```cpp
#include <iostream>

std::cout << "Hello" << std::endl;
std::cin >> variable;
std::cerr << "Error" << std::endl;
```

### File Streams

```cpp
#include <fstream>

// Output file
std::ofstream out("file.txt");
out << "Hello, World!" << std::endl;
out.close();

// Input file
std::ifstream in("file.txt");
std::string line;
std::getline(in, line);
in.close();

// Binary file
std::ofstream binOut("file.bin", std::ios::binary);
int data = 42;
binOut.write(reinterpret_cast<char*>(&data), sizeof(data));
```

### String Streams

```cpp
#include <sstream>

// Output string stream
std::ostringstream oss;
oss << "Value: " << 42;
std::string str = oss.str();

// Input string stream
std::istringstream iss("42 3.14 hello");
int i;
double d;
std::string s;
iss >> i >> d >> s;
```

### Formatting

```cpp
#include <iomanip>

std::cout << std::setw(10) << std::setfill('0') << 42;  // 0000000042
std::cout << std::fixed << std::setprecision(2) << 3.14159;  // 3.14
std::cout << std::hex << 255;  // ff
```

---

## Module 09: Exception Handling

### Try-Catch

```cpp
try {
    // Code that might throw
    throw std::runtime_error("Error message");
} catch (const std::runtime_error& e) {
    std::cerr << "Caught: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Generic exception: " << e.what() << std::endl;
} catch (...) {
    std::cerr << "Unknown exception" << std::endl;
}
```

### Custom Exceptions

```cpp
class MyException : public std::exception {
    std::string message;
public:
    MyException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

throw MyException("Custom error");
```

### Noexcept

```cpp
void function() noexcept {
    // Guaranteed not to throw
}

void conditionalNoexcept() noexcept(sizeof(int) == 4) {
    // Noexcept if condition is true
}

// Check if noexcept
static_assert(noexcept(function()));
```

---

## Module 10: Data Structures

### Linked List

```cpp
struct Node {
    int data;
    Node* next;
};

// Insert at beginning
void insertFront(Node** head, int data) {
    Node* newNode = new Node{data, *head};
    *head = newNode;
}

// Traverse
void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}
```

### Binary Search Tree

```cpp
struct TreeNode {
    int data;
    TreeNode *left, *right;
};

// Insert
TreeNode* insert(TreeNode* root, int data) {
    if (!root) return new TreeNode{data, nullptr, nullptr};
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Inorder traversal
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
```

### Graph (Adjacency List)

```cpp
#include <vector>
#include <queue>

using Graph = std::vector<std::vector<int>>;

// BFS
void bfs(const Graph& g, int start) {
    std::vector<bool> visited(g.size(), false);
    std::queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        
        for (int neighbor : g[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

---

## 🔗 Quick Links

- [Full Documentation](README.md)
- [Module 01: STL Containers](01_STL_Containers/QUICK_REFERENCE.md)
- [Contributing](CONTRIBUTING.md)
- [License](LICENSE)

---

*Last Updated: November 14, 2025*

