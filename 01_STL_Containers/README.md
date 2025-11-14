# 📦 STL Containers Module

![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-blue.svg)
![Status](https://img.shields.io/badge/Status-Complete-green.svg)
![Examples](https://img.shields.io/badge/Examples-17-brightgreen.svg)

## 📋 Table of Contents
- [Overview](#overview)
- [Learning Objectives](#learning-objectives)
- [Directory Structure](#directory-structure)
- [Quick Start](#quick-start)
- [Learning Path](#learning-path)
- [Container Decision Guide](#container-decision-guide)
- [Performance Comparison](#performance-comparison)
- [Best Practices](#best-practices)
- [Prerequisites](#prerequisites)
- [Contributing](#contributing)

## 🎯 Overview

The **STL Containers** module provides comprehensive coverage of C++ Standard Template Library containers, which are essential data structures for efficient data management. This module covers all major container types, their characteristics, use cases, and performance considerations.

**What You'll Learn:**
- All STL container types and their internal implementations
- When to use which container for optimal performance
- Time and space complexity analysis
- Modern C++ container features (C++11/14/17/20)
- Real-world applications and best practices
- Common pitfalls and how to avoid them

## 🎓 Learning Objectives

By completing this module, you will be able to:

1. ✅ **Understand** the characteristics and trade-offs of each STL container
2. ✅ **Choose** the appropriate container for specific use cases
3. ✅ **Implement** efficient algorithms using STL containers
4. ✅ **Analyze** time and space complexity of container operations
5. ✅ **Apply** modern C++ features with containers (auto, range-based for, etc.)
6. ✅ **Optimize** code performance through proper container selection
7. ✅ **Debug** common container-related issues

## 📁 Directory Structure

```
01_STL_Containers/
│
├── README.md                          # This file
├── QUICK_REFERENCE.md                 # One-page cheat sheet
├── PROJECT_SUMMARY.md                 # Statistics & metrics
├── INDEX.md                           # Complete navigation
├── STRUCTURE.md                       # Annotated directory tree
├── TESTING.md                         # Build & test instructions
├── CMakeLists.txt                     # CMake build configuration
├── compile_all.sh                     # Bash compilation script
├── compile_all.ps1                    # PowerShell compilation script
│
├── 01_SequenceContainers/             # Linear data structures
│   ├── README.md                      # Sequence containers overview
│   ├── VectorExample.cpp              # Dynamic array - most commonly used
│   ├── DequeExample.cpp               # Double-ended queue
│   ├── ListExample.cpp                # Doubly-linked list
│   ├── ForwardListExample.cpp         # Singly-linked list
│   └── ArrayExample.cpp               # Fixed-size array
│
├── 02_AssociativeContainers/          # Ordered key-based structures
│   ├── README.md                      # Associative containers overview
│   ├── SetExample.cpp                 # Ordered unique keys
│   ├── MapExample.cpp                 # Ordered key-value pairs
│   ├── MultisetExample.cpp            # Ordered keys with duplicates
│   └── MultimapExample.cpp            # Ordered key-value with duplicate keys
│
├── 03_UnorderedContainers/            # Hash-based structures
│   ├── README.md                      # Unordered containers overview
│   ├── UnorderedSetExample.cpp        # Hash set
│   ├── UnorderedMapExample.cpp        # Hash map
│   ├── UnorderedMultisetExample.cpp   # Hash multiset
│   └── UnorderedMultimapExample.cpp   # Hash multimap
│
└── 04_ContainerAdaptors/              # Specialized interfaces
    ├── README.md                      # Container adaptors overview
    ├── StackExample.cpp               # LIFO structure
    ├── QueueExample.cpp               # FIFO structure
    └── PriorityQueueExample.cpp       # Heap-based priority queue
```

## 🚀 Quick Start

### Compilation

**Using g++:**
```bash
# Compile a single example
g++ -std=c++17 -Wall -Wextra -O2 01_SequenceContainers/VectorExample.cpp -o VectorExample
./VectorExample

# Compile all examples (Linux/Mac)
chmod +x compile_all.sh
./compile_all.sh
```

**Using clang++:**
```bash
clang++ -std=c++17 -Wall -Wextra -O2 01_SequenceContainers/VectorExample.cpp -o VectorExample
./VectorExample
```

**Using PowerShell (Windows):**
```powershell
# Compile a single example
g++ -std=c++17 -Wall -Wextra -O2 01_SequenceContainers/VectorExample.cpp -o VectorExample.exe
./VectorExample.exe

# Compile all examples
./compile_all.ps1
```

**Using CMake:**
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Running Examples

Each example is self-contained and produces formatted output:
```bash
./VectorExample
# Output shows various vector operations with explanations
```

## 🗺️ Learning Path

### 👶 **Beginner Path** (Start Here)
1. **vector** → Most commonly used, dynamic array
2. **array** → Fixed-size alternative to C arrays
3. **stack** → Simple LIFO operations
4. **queue** → Simple FIFO operations

### 🧑 **Intermediate Path**
5. **deque** → Double-ended operations
6. **set** → Ordered unique elements
7. **map** → Key-value pairs
8. **priority_queue** → Heap-based priority management

### 👨‍💼 **Advanced Path**
9. **list** → Efficient insertions/deletions anywhere
10. **forward_list** → Memory-efficient singly-linked list
11. **unordered_set** → Fast lookups with hashing
12. **unordered_map** → Fast key-value lookups
13. **multiset/multimap** → Duplicate key handling
14. **unordered_multiset/unordered_multimap** → Fast duplicate key handling

## 🤔 Container Decision Guide

### When to Use Each Container

```
Need random access? ──┬─ Yes → Fixed size? ──┬─ Yes → array
                      │                       └─ No ─→ vector
                      │
                      └─ No ─→ Need frequent insertions/deletions?
                                │
                                ├─ At ends only ────→ deque
                                ├─ Anywhere ────────→ list
                                └─ At front only ───→ forward_list

Need key-based lookup? ──┬─ Unique keys? ──┬─ Yes → Ordered? ──┬─ Yes → set/map
                         │                  │                    └─ No ─→ unordered_set/unordered_map
                         │                  │
                         │                  └─ No ─→ Ordered? ──┬─ Yes → multiset/multimap
                         │                                       └─ No ─→ unordered_multiset/unordered_multimap
                         │
                         └─ Need LIFO? ─────────→ stack
                         └─ Need FIFO? ─────────→ queue
                         └─ Need priority? ─────→ priority_queue
```

### Use Case Recommendations

| Use Case | Recommended Container | Why? |
|----------|----------------------|------|
| General-purpose collection | `vector` | Best overall performance, cache-friendly |
| Fixed-size data | `array` | No dynamic allocation, compile-time size |
| Frequent insertions at both ends | `deque` | O(1) push/pop at both ends |
| Frequent insertions in middle | `list` | O(1) insertion anywhere with iterator |
| Lookup by key (frequent) | `unordered_map` | O(1) average lookup time |
| Lookup by key (ordered iteration) | `map` | O(log n) lookup, sorted order |
| Unique sorted elements | `set` | Automatic sorting and uniqueness |
| Function call stack simulation | `stack` | LIFO operations |
| Task queue | `queue` | FIFO operations |
| Event scheduling | `priority_queue` | Efficient min/max extraction |
| Cache implementation | `list` + `unordered_map` | LRU cache pattern |
| Graph adjacency list | `vector<vector<int>>` | Efficient storage and access |

## 📊 Performance Comparison

### Time Complexity Cheat Sheet

| Operation | vector | deque | list | set/map | unordered_set/map |
|-----------|--------|-------|------|---------|-------------------|
| **Access** | O(1) | O(1) | O(n) | O(log n) | O(1) avg |
| **Search** | O(n) | O(n) | O(n) | O(log n) | O(1) avg |
| **Insert at end** | O(1)* | O(1) | O(1) | O(log n) | O(1) avg |
| **Insert at beginning** | O(n) | O(1) | O(1) | O(log n) | O(1) avg |
| **Insert in middle** | O(n) | O(n) | O(1) | O(log n) | O(1) avg |
| **Delete at end** | O(1) | O(1) | O(1) | O(log n) | O(1) avg |
| **Delete at beginning** | O(n) | O(1) | O(1) | O(log n) | O(1) avg |
| **Delete in middle** | O(n) | O(n) | O(1) | O(log n) | O(1) avg |

*O(1) amortized - occasionally O(n) when reallocation occurs

### Space Overhead

| Container | Memory Overhead | Cache Efficiency |
|-----------|----------------|------------------|
| `vector` | Minimal (~50% extra capacity) | ⭐⭐⭐⭐⭐ Excellent |
| `array` | None | ⭐⭐⭐⭐⭐ Excellent |
| `deque` | Moderate (multiple blocks) | ⭐⭐⭐⭐ Good |
| `list` | High (2 pointers per element) | ⭐⭐ Poor |
| `forward_list` | Moderate (1 pointer per element) | ⭐⭐ Poor |
| `set/map` | High (3 pointers + color bit) | ⭐⭐ Poor |
| `unordered_set/map` | High (buckets + linked lists) | ⭐⭐⭐ Fair |

## 🔥 Best Practices

### Modern C++ Container Usage (⭐ C++11/14/17/20)

```cpp
// ✅ Use auto for iterators (C++11)
for (auto it = vec.begin(); it != vec.end(); ++it) { }

// ✅ Even better: range-based for loop (C++11)
for (const auto& elem : vec) { }

// ✅ Use emplace instead of push for in-place construction (C++11)
vec.emplace_back(arg1, arg2);  // Constructs in-place
// Instead of: vec.push_back(MyClass(arg1, arg2));

// ✅ Use uniform initialization (C++11)
std::vector<int> vec = {1, 2, 3, 4, 5};
std::map<std::string, int> map = {{"one", 1}, {"two", 2}};

// ✅ Use structured bindings for maps (C++17)
for (const auto& [key, value] : map) {
    std::cout << key << ": " << value << std::endl;
}

// ✅ Reserve capacity for vectors when size is known
vec.reserve(1000);  // Prevents multiple reallocations

// ✅ Use shrink_to_fit to release unused memory
vec.shrink_to_fit();

// ✅ Check empty() instead of size() == 0
if (vec.empty()) { /* more efficient */ }

// ✅ Use const& to avoid copies
void processVector(const std::vector<int>& vec);

// ✅ Use move semantics for large objects (C++11)
std::vector<int> source = {1, 2, 3};
std::vector<int> dest = std::move(source);  // Efficient transfer
```

### General Guidelines

1. **Default to `vector`** - Use unless you have a specific reason not to
2. **Prefer `emplace` over `push`** - More efficient for complex objects
3. **Reserve capacity** - When final size is known or estimable
4. **Use the right container** - Performance matters in tight loops
5. **Avoid premature optimization** - Profile before optimizing
6. **Be aware of iterator invalidation** - Different rules for each container
7. **Use const correctness** - const references for read-only access
8. **Consider cache locality** - Contiguous containers (vector, array) are faster

## ⚠️ Common Pitfalls

1. ❌ **Not reserving vector capacity** → Multiple reallocations
2. ❌ **Using list when vector would work** → Poor cache performance
3. ❌ **Forgetting iterator invalidation** → Undefined behavior
4. ❌ **Using `at()` instead of `[]` unnecessarily** → Exception overhead
5. ❌ **Not using const references** → Unnecessary copies
6. ❌ **Comparing floating-point keys in maps** → Precision issues
7. ❌ **Not providing custom hash functions** → Poor hash distribution
8. ❌ **Modifying container during iteration** → Iterator invalidation

## 📚 Prerequisites

### Required Knowledge
- Basic C++ syntax
- Functions and control structures
- Pointers and references
- Basic template syntax

### Recommended Knowledge
- C++ classes and objects
- Iterators concept
- Template basics
- Time/space complexity analysis

### Development Environment
- **Compiler:** g++ 7+ or clang++ 5+ or MSVC 19.14+
- **C++ Standard:** C++17 minimum, C++20 recommended
- **Build System:** CMake 3.10+ (optional)
- **OS:** Linux, macOS, or Windows

### Installation

**Ubuntu/Debian:**
```bash
sudo apt-get install build-essential cmake
```

**macOS:**
```bash
xcode-select --install
brew install cmake
```

**Windows:**
- Install MinGW-w64 or MSYS2
- Or use Visual Studio 2019+

## 🤝 Contributing

Contributions are welcome! Please follow these guidelines:

1. **Code Style:** Follow C++ Core Guidelines
2. **Comments:** Use clear, concise comments
3. **Formatting:** Consistent indentation (4 spaces)
4. **Testing:** Ensure all examples compile and run
5. **Documentation:** Update README files as needed

## 📖 Further Reading

- [cppreference.com - Containers library](https://en.cppreference.com/w/cpp/container)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [Effective STL by Scott Meyers](https://www.aristeia.com/books.html)
- [STL Tutorial and Reference Guide](https://www.oreilly.com/library/view/c-standard-library/9780321623218/)

## 📄 License

This educational module is provided for learning purposes. Feel free to use, modify, and distribute.

---

**Next Steps:** 
1. Start with [01_SequenceContainers](01_SequenceContainers/README.md)
2. Check the [QUICK_REFERENCE.md](QUICK_REFERENCE.md) for a syntax cheat sheet
3. Review [INDEX.md](INDEX.md) for complete navigation

**Happy Learning! 🚀**

