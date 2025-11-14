# 🚀 Module 02: STL Algorithms

[![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-blue.svg)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/Status-In%20Progress-yellow.svg)](.)
[![Examples](https://img.shields.io/badge/Examples-16%2B-brightgreen.svg)](.)

> **A comprehensive guide to the C++ Standard Template Library (STL) algorithms, covering non-modifying, modifying, sorting, numeric, and set operations.**

---

## 📋 Table of Contents

- [Overview](#overview)
- [Module Structure](#module-structure)
- [Learning Path](#learning-path)
- [Quick Start](#quick-start)
- [Key Concepts](#key-concepts)
- [Algorithm Categories](#algorithm-categories)
- [Prerequisites](#prerequisites)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)

---

## 🎯 Overview

This module provides a deep dive into the C++ STL algorithms library, a powerful set of tools for processing sequences of elements. By mastering these algorithms, you can write more expressive, efficient, and maintainable code.

### 🌟 Key Features

- ✅ **16+ Runnable Examples** - Each demonstrating a specific algorithm or category
- ✅ **Modern C++ Practices** - Lambdas, predicates, and C++17/20 features
- ✅ **Performance Analysis** - Complexity of each algorithm explained
- ✅ **Real-World Use Cases** - Practical applications for data processing
- ✅ **Best Practices** - Iterator usage, remove-erase idiom, algorithm chaining
- ✅ **Build Automation** - CMake and compilation scripts included

---

## 📚 Module Structure

```
02_STL_Algorithms/
├── 📄 README.md                 # This file
├── 📄 QUICK_REFERENCE.md        # Syntax cheat sheet
├── 📄 PROJECT_SUMMARY.md        # Statistics and progress
├── 📄 INDEX.md                  # File navigation
├── 📄 STRUCTURE.md              # Directory organization
├── 📄 TESTING.md                # Build instructions
├── 🔧 CMakeLists.txt            # CMake configuration
├── 🔧 compile_all.sh            # Bash script
├── 🔧 compile_all.ps1           # PowerShell script
│
├── 📁 01_NonModifyingAlgorithms/
│   ├── 📄 README.md
│   ├── 💻 FindExample.cpp
│   ├── 💻 CountExample.cpp
│   ├── 💻 SearchExample.cpp
│   └── 💻 PredicateExample.cpp
│
├── 📁 02_ModifyingAlgorithms/
│   ├── 📄 README.md
│   ├── 💻 CopyExample.cpp
│   ├── 💻 TransformExample.cpp
│   ├── 💻 ReplaceExample.cpp
│   ├── 💻 RemoveExample.cpp
│   └── 💻 FillExample.cpp
│
├── 📁 03_SortingAlgorithms/
│   ├── 📄 README.md
│   ├── 💻 SortExample.cpp
│   ├── 💻 PartialSortExample.cpp
│   ├── 💻 PartitionExample.cpp
│   └── 💻 BinarySearchExample.cpp
│
├── 📁 04_NumericAlgorithms/
│   ├── 📄 README.md
│   ├── 💻 AccumulateExample.cpp
│   ├── 💻 InnerProductExample.cpp
│   └── 💻 IotaExample.cpp
│
└── 📁 05_SetOperations/
    ├── 📄 README.md
    ├── 💻 SetUnionExample.cpp
    └── 💻 SetIntersectionExample.cpp
```

---

## 🗺️ Learning Path

### 🟢 Beginner Path

1. **Non-Modifying Algorithms:**
   - `FindExample.cpp` - Learn to find elements
   - `CountExample.cpp` - Learn to count occurrences

2. **Modifying Algorithms:**
   - `CopyExample.cpp` - Learn to copy sequences
   - `FillExample.cpp` - Learn to fill containers

3. **Sorting Algorithms:**
   - `SortExample.cpp` - Learn to sort sequences

### 🟡 Intermediate Path

1. **Advanced Non-Modifying:**
   - `SearchExample.cpp` - Find subsequences
   - `PredicateExample.cpp` - Use predicates with `all_of`, `any_of`, `none_of`

2. **Advanced Modifying:**
   - `TransformExample.cpp` - Apply functions to sequences
   - `ReplaceExample.cpp` - Replace elements
   - `RemoveExample.cpp` - Master the remove-erase idiom

3. **Advanced Sorting:**
   - `PartialSortExample.cpp` - Sort a subset of elements
   - `PartitionExample.cpp` - Partition sequences based on a predicate
   - `BinarySearchExample.cpp` - Efficient searching in sorted sequences

### 🔴 Advanced Path

1. **Numeric Algorithms:**
   - `AccumulateExample.cpp` - Summation and custom operations
   - `InnerProductExample.cpp` - Dot products and more
   - `IotaExample.cpp` - Generate sequences

2. **Set Operations:**
   - `SetUnionExample.cpp` - Combine sorted sequences
   - `SetIntersectionExample.cpp` - Find common elements

3. **Performance & Optimization:**
   - Study complexity analysis in each example
   - Compare performance of different algorithms
   - Learn about execution policies (C++17)

---

## 🚀 Quick Start

### Prerequisites

- C++17 compatible compiler
- CMake 3.10+ (recommended)
- Basic knowledge of STL containers (Module 01)

### Compile and Run

```bash
# Navigate to this module
cd 02_STL_Algorithms

# Compile a single example
g++ -std=c++17 -Wall -Wextra -O2 01_NonModifyingAlgorithms/FindExample.cpp -o FindExample

# Run
./FindExample

# Or use the provided scripts
./compile_all.sh        # Linux/Mac
./compile_all.ps1       # Windows (PowerShell)
```

---

## 🔑 Key Concepts

### Iterators

- **Input Iterators:** Read-only, forward-only
- **Output Iterators:** Write-only, forward-only
- **Forward Iterators:** Read/write, multi-pass
- **Bidirectional Iterators:** Forward and backward
- **Random-Access Iterators:** O(1) access to any element

### Predicates

- **Unary Predicate:** A function that takes one argument and returns a boolean
- **Binary Predicate:** A function that takes two arguments and returns a boolean

```cpp
// Unary predicate
bool is_even(int n) { return n % 2 == 0; }

// Binary predicate
bool is_greater(int a, int b) { return a > b; }

// Lambda predicate
auto is_odd = [](int n) { return n % 2 != 0; };
```

### Remove-Erase Idiom

A common pattern for removing elements from a container:

```cpp
std::vector<int> v = {1, 2, 3, 2, 4};

// 1. std::remove moves elements to be removed to the end
auto new_end = std::remove(v.begin(), v.end(), 2);

// 2. v.erase removes the elements from the new end
v.erase(new_end, v.end());
```

---

## 📦 Algorithm Categories

### 1. Non-Modifying Algorithms

These algorithms inspect but do not modify the elements in a sequence.

- **Examples:** `find`, `count`, `search`, `all_of`, `any_of`, `none_of`
- **Key Idea:** Safe to use on any container without side effects

### 2. Modifying Algorithms

These algorithms modify the elements in a sequence.

- **Examples:** `copy`, `transform`, `replace`, `remove`, `fill`
- **Key Idea:** Change the state of the container or an output sequence

### 3. Sorting Algorithms

These algorithms reorder the elements in a sequence.

- **Examples:** `sort`, `stable_sort`, `partial_sort`, `nth_element`, `partition`
- **Key Idea:** Provide different ways to order data

### 4. Numeric Algorithms

These algorithms perform mathematical operations on sequences.

- **Examples:** `accumulate`, `inner_product`, `adjacent_difference`, `iota`
- **Key Idea:** Found in the `<numeric>` header

### 5. Set Operations

These algorithms perform set operations on sorted sequences.

- **Examples:** `set_union`, `set_intersection`, `set_difference`
- **Key Idea:** Require input sequences to be sorted

---

## 🔧 Prerequisites

### Knowledge

- **C++ Fundamentals:** Variables, loops, functions
- **STL Containers:** `std::vector`, `std::list`, `std::map` (from Module 01)
- **Iterators:** Basic understanding of `begin()` and `end()`

### System

- **Compiler:** C++17 support minimum
- **OS:** Linux, macOS, or Windows
- **Memory:** 4GB RAM minimum

---

## 📖 Documentation

| File | Purpose |
|------|---------|
| **README.md** | This file - module overview |
| **QUICK_REFERENCE.md** | Syntax cheat sheet for algorithms |
| **PROJECT_SUMMARY.md** | Statistics and progress |
| **INDEX.md** | Complete file navigation |
| **STRUCTURE.md** | Directory organization |
| **TESTING.md** | Build and test instructions |

---

## 🤝 Contributing

Contributions are welcome! Please see the root [CONTRIBUTING.md](../../CONTRIBUTING.md) for guidelines.

### How to Contribute

1. **Report Issues:** Found a bug? Open an issue.
2. **Suggest Improvements:** Have ideas for new examples?
3. **Submit Code:** Follow the existing style and patterns.

---

## 📜 License

This work is licensed under the **Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License (CC BY-NC-SA 4.0)**.

See the root [LICENSE](../../LICENSE) file for details.

---

## 👨‍💻 Author

**Abhinav**
- GitHub: [@abhinav1602](https://github.com/abhinav1602)
- Repository: [github.com/abhinav1602/CPP](https://github.com/abhinav1602/CPP)

---

**Happy Coding! 🚀**

*Last Updated: November 15, 2025*

