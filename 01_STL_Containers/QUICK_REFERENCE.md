# 📋 STL Containers - Quick Reference

## 🔥 One-Page Cheat Sheet

### Sequence Containers

#### vector - Dynamic Array
```cpp
#include <vector>
std::vector<int> vec = {1, 2, 3};
vec.push_back(4);              // Add to end - O(1) amortized
vec.pop_back();                // Remove from end - O(1)
vec[0] = 10;                   // Random access - O(1)
vec.at(0) = 10;                // Bounds-checked access - O(1)
vec.insert(vec.begin(), 5);    // Insert at position - O(n)
vec.erase(vec.begin());        // Erase at position - O(n)
vec.size();                    // Number of elements
vec.capacity();                // Allocated capacity
vec.reserve(100);              // Reserve capacity
vec.shrink_to_fit();           // Release unused memory
vec.clear();                   // Remove all elements
vec.empty();                   // Check if empty
```

#### deque - Double-Ended Queue
```cpp
#include <deque>
std::deque<int> dq = {1, 2, 3};
dq.push_back(4);               // Add to end - O(1)
dq.push_front(0);              // Add to front - O(1)
dq.pop_back();                 // Remove from end - O(1)
dq.pop_front();                // Remove from front - O(1)
dq[0] = 10;                    // Random access - O(1)
```

#### list - Doubly-Linked List
```cpp
#include <list>
std::list<int> lst = {1, 2, 3};
lst.push_back(4);              // Add to end - O(1)
lst.push_front(0);             // Add to front - O(1)
lst.pop_back();                // Remove from end - O(1)
lst.pop_front();               // Remove from front - O(1)
lst.insert(it, 5);             // Insert at iterator - O(1)
lst.erase(it);                 // Erase at iterator - O(1)
lst.sort();                    // Sort - O(n log n)
lst.reverse();                 // Reverse - O(n)
lst.unique();                  // Remove consecutive duplicates - O(n)
lst.merge(other_list);         // Merge sorted lists - O(n)
```

#### forward_list - Singly-Linked List
```cpp
#include <forward_list>
std::forward_list<int> flst = {1, 2, 3};
flst.push_front(0);            // Add to front - O(1)
flst.pop_front();              // Remove from front - O(1)
flst.insert_after(it, 5);      // Insert after iterator - O(1)
flst.erase_after(it);          // Erase after iterator - O(1)
```

#### array - Fixed-Size Array
```cpp
#include <array>
std::array<int, 5> arr = {1, 2, 3, 4, 5};
arr[0] = 10;                   // Random access - O(1)
arr.at(0) = 10;                // Bounds-checked access - O(1)
arr.front();                   // First element
arr.back();                    // Last element
arr.size();                    // Always compile-time constant
arr.fill(0);                   // Fill with value
```

### Associative Containers (Ordered - Red-Black Tree)

#### set - Unique Sorted Elements
```cpp
#include <set>
std::set<int> s = {3, 1, 4, 1, 5};  // {1, 3, 4, 5} - duplicates removed
s.insert(2);                   // Insert element - O(log n)
s.erase(3);                    // Remove element - O(log n)
s.count(4);                    // Count occurrences (0 or 1) - O(log n)
s.find(5);                     // Find element - O(log n), returns iterator
s.lower_bound(3);              // First >= key - O(log n)
s.upper_bound(3);              // First > key - O(log n)
s.empty();                     // Check if empty
s.size();                      // Number of elements
s.clear();                     // Remove all elements
```

#### map - Key-Value Pairs (Unique Keys)
```cpp
#include <map>
std::map<std::string, int> m = {{"one", 1}, {"two", 2}};
m["three"] = 3;                // Insert or update - O(log n)
m.insert({"four", 4});         // Insert - O(log n)
m.erase("one");                // Remove by key - O(log n)
m.count("two");                // Check existence (0 or 1) - O(log n)
m.find("three");               // Find by key - O(log n)
m.at("two");                   // Access with bounds check
// C++17 structured bindings
for (const auto& [key, value] : m) { /* ... */ }
```

#### multiset - Sorted Elements (Duplicates Allowed)
```cpp
#include <set>
std::multiset<int> ms = {1, 2, 2, 3, 3, 3};
ms.insert(2);                  // Insert - O(log n)
ms.erase(2);                   // Remove ALL 2s - O(log n + k)
ms.count(3);                   // Count occurrences - O(log n + k)
auto range = ms.equal_range(3);// Get range of elements - O(log n)
```

#### multimap - Key-Value Pairs (Duplicate Keys Allowed)
```cpp
#include <map>
std::multimap<std::string, int> mm;
mm.insert({"key", 1});         // Insert - O(log n)
mm.insert({"key", 2});         // Same key allowed
mm.count("key");               // Count keys - O(log n + k)
auto range = mm.equal_range("key");  // Get all values for key - O(log n)
```

### Unordered Containers (Hash-Based)

#### unordered_set - Hash Set
```cpp
#include <unordered_set>
std::unordered_set<int> us = {1, 2, 3};
us.insert(4);                  // Insert - O(1) average
us.erase(2);                   // Remove - O(1) average
us.count(3);                   // Check existence - O(1) average
us.find(4);                    // Find - O(1) average
us.bucket_count();             // Number of buckets
us.load_factor();              // Average elements per bucket
us.rehash(100);                // Set bucket count
us.reserve(100);               // Reserve capacity
```

#### unordered_map - Hash Map
```cpp
#include <unordered_map>
std::unordered_map<std::string, int> um = {{"one", 1}};
um["two"] = 2;                 // Insert or update - O(1) average
um.insert({"three", 3});       // Insert - O(1) average
um.erase("one");               // Remove - O(1) average
um.count("two");               // Check existence - O(1) average
um.find("three");              // Find - O(1) average
um.at("two");                  // Access with bounds check
// Custom hash function
struct MyHash {
    size_t operator()(const MyKey& k) const { return std::hash<int>()(k.value); }
};
std::unordered_map<MyKey, int, MyHash> custom_map;
```

#### unordered_multiset & unordered_multimap
```cpp
#include <unordered_set>
#include <unordered_map>
std::unordered_multiset<int> ums = {1, 1, 2, 3};
std::unordered_multimap<std::string, int> umm;
// Similar API to multiset/multimap but with O(1) average operations
```

### Container Adaptors

#### stack - LIFO (Last-In-First-Out)
```cpp
#include <stack>
std::stack<int> stk;
stk.push(1);                   // Push element - O(1)
stk.pop();                     // Pop element - O(1)
stk.top();                     // Access top - O(1)
stk.empty();                   // Check if empty
stk.size();                    // Number of elements
// Default underlying: deque, can use vector or list
std::stack<int, std::vector<int>> vec_stack;
```

#### queue - FIFO (First-In-First-Out)
```cpp
#include <queue>
std::queue<int> q;
q.push(1);                     // Enqueue - O(1)
q.pop();                       // Dequeue - O(1)
q.front();                     // Access front - O(1)
q.back();                      // Access back - O(1)
q.empty();                     // Check if empty
q.size();                      // Number of elements
// Default underlying: deque
```

#### priority_queue - Max-Heap (Default)
```cpp
#include <queue>
std::priority_queue<int> pq;   // Max-heap by default
pq.push(3);                    // Insert - O(log n)
pq.push(1);
pq.push(5);
pq.top();                      // Access max - O(1) → returns 5
pq.pop();                      // Remove max - O(log n)

// Min-heap
std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
min_pq.push(3);
min_pq.top();                  // Returns minimum

// Custom comparator
auto cmp = [](int a, int b) { return a > b; };
std::priority_queue<int, std::vector<int>, decltype(cmp)> custom_pq(cmp);
```

## 🎯 Container Selection Decision Tree

```cpp
// Need random access? → vector or array
if (need_random_access) {
    if (fixed_size) return std::array;
    else return std::vector;
}

// Need fast insertions/deletions at both ends? → deque
if (need_both_ends) return std::deque;

// Need fast insertions/deletions anywhere? → list
if (need_middle_insert) return std::list;

// Need key-based lookup?
if (need_lookup) {
    if (need_sorted) {
        if (unique_keys) return std::set;  // or std::map
        else return std::multiset;         // or std::multimap
    } else {
        if (unique_keys) return std::unordered_set;  // or unordered_map
        else return std::unordered_multiset;         // or unordered_multimap
    }
}

// Need LIFO? → stack
if (need_lifo) return std::stack;

// Need FIFO? → queue
if (need_fifo) return std::queue;

// Need priority? → priority_queue
if (need_priority) return std::priority_queue;
```

## 📊 Quick Performance Reference

| Container | Access | Insert (end) | Insert (middle) | Search | Notes |
|-----------|--------|--------------|-----------------|--------|-------|
| `vector` | O(1) | O(1)* | O(n) | O(n) | Best default choice |
| `deque` | O(1) | O(1) | O(n) | O(n) | Good for both ends |
| `list` | O(n) | O(1) | O(1) | O(n) | Use when splicing |
| `forward_list` | O(n) | - | O(1) | O(n) | Most memory efficient |
| `array` | O(1) | - | - | O(n) | Fixed size |
| `set/map` | - | O(log n) | O(log n) | O(log n) | Sorted order |
| `unordered_set/map` | - | O(1)† | O(1)† | O(1)† | Fast lookup |
| `stack` | O(1) | O(1) | - | - | LIFO only |
| `queue` | O(1) | O(1) | - | - | FIFO only |
| `priority_queue` | O(1) | O(log n) | - | - | Heap operations |

*Amortized | †Average case

## 💡 Modern C++ Idioms

```cpp
// Range-based for loop (C++11)
for (const auto& elem : container) { /* read */ }
for (auto& elem : container) { /* modify */ }

// Structured bindings (C++17)
for (const auto& [key, value] : map) { /* ... */ }

// Emplace operations (C++11)
vec.emplace_back(args...);     // Construct in-place
map.emplace(key, value);       // More efficient than insert

// Uniform initialization (C++11)
std::vector<int> vec = {1, 2, 3};
std::map<int, std::string> map = {{1, "one"}, {2, "two"}};

// Move semantics (C++11)
std::vector<int> vec2 = std::move(vec1);  // Transfer ownership

// Iterator helpers (C++11/14)
auto it = std::begin(container);
auto end = std::end(container);

// Algorithms with lambdas (C++11)
std::sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
```

## 🔍 Common Patterns

```cpp
// 1. Remove elements from vector
vec.erase(std::remove_if(vec.begin(), vec.end(), 
    [](int x) { return x % 2 == 0; }), vec.end());

// 2. Check if key exists in map
if (map.find(key) != map.end()) { /* exists */ }
// Or (C++20):
if (map.contains(key)) { /* exists */ }

// 3. Safe map access with default value
int value = map.count(key) ? map[key] : default_value;
// Or:
int value = map.find(key) != map.end() ? map.at(key) : default_value;

// 4. Iterate with index
for (size_t i = 0; i < vec.size(); ++i) {
    // Use vec[i]
}

// 5. Reverse iteration
for (auto it = vec.rbegin(); it != vec.rend(); ++it) { /* ... */ }

// 6. Transform container
std::vector<int> result;
std::transform(input.begin(), input.end(), std::back_inserter(result),
    [](int x) { return x * 2; });

// 7. Accumulate/reduce
int sum = std::accumulate(vec.begin(), vec.end(), 0);

// 8. Find element
auto it = std::find(vec.begin(), vec.end(), target);
if (it != vec.end()) { /* found */ }

// 9. Copy container
std::vector<int> copy = original;  // Deep copy
std::vector<int> moved = std::move(original);  // Move

// 10. Clear and shrink
vec.clear();
vec.shrink_to_fit();  // Release memory
```

## ⚠️ Iterator Invalidation Rules

| Container | Insert | Erase | Other |
|-----------|--------|-------|-------|
| `vector` | All after insertion | All after erasure | `reserve()`, `resize()` |
| `deque` | All | All except ends | - |
| `list` | None | Only erased | - |
| `forward_list` | None | Only erased | - |
| `set/map` | None | Only erased | - |
| `unordered_*` | All if rehash | Only erased | `rehash()`, `reserve()` |

---

**💡 Pro Tip:** When in doubt, use `vector`. It's the fastest container for most use cases due to cache locality!

**📚 Full Documentation:** See [README.md](README.md) for detailed explanations and [INDEX.md](INDEX.md) for complete navigation.

