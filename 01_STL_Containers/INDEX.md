# 📑 STL Containers - Complete Index

## 🗂️ Navigation Guide

This index provides quick access to all files in the STL Containers module with descriptions and status indicators.

### Legend
- ✅ Complete
- ⭐ Modern C++ (C++11/14/17/20)
- ✓ Tested and validated
- 📖 Documentation
- 💻 Code example

---

## 📚 Module-Level Documentation

| File | Type | Description | Status |
|------|------|-------------|--------|
| [README.md](README.md) | 📖 | Main entry point, learning objectives, decision guides | ✅ ⭐ ✓ |
| [QUICK_REFERENCE.md](QUICK_REFERENCE.md) | 📖 | One-page cheat sheet with all container syntax | ✅ ⭐ ✓ |
| [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md) | 📖 | Statistics, metrics, completion status | ✅ ⭐ ✓ |
| [INDEX.md](INDEX.md) | 📖 | This file - complete navigation | ✅ ⭐ ✓ |
| [STRUCTURE.md](STRUCTURE.md) | 📖 | Annotated directory tree, organization guide | ✅ ⭐ ✓ |
| [TESTING.md](TESTING.md) | 📖 | Build instructions, testing guide, troubleshooting | ✅ ⭐ ✓ |
| [CMakeLists.txt](CMakeLists.txt) | 🔧 | CMake build configuration | ✅ ✓ |
| [compile_all.sh](compile_all.sh) | 🔧 | Bash compilation script (Linux/Mac) | ✅ ✓ |
| [compile_all.ps1](compile_all.ps1) | 🔧 | PowerShell compilation script (Windows) | ✅ ✓ |

---

## 📦 01_SequenceContainers

**Purpose:** Linear data structures providing sequential access to elements

| File | Lines | Description | Key Features | Status |
|------|-------|-------------|--------------|--------|
| [README.md](01_SequenceContainers/README.md) | 📖 | Overview of sequence containers, comparison | Comprehensive guide | ✅ ⭐ ✓ |
| [VectorExample.cpp](01_SequenceContainers/VectorExample.cpp) | 💻 300+ | Dynamic array - most commonly used | Random access, dynamic sizing | ✅ ⭐ ✓ |
| [DequeExample.cpp](01_SequenceContainers/DequeExample.cpp) | 💻 280+ | Double-ended queue | Fast insertions at both ends | ✅ ⭐ ✓ |
| [ListExample.cpp](01_SequenceContainers/ListExample.cpp) | 💻 290+ | Doubly-linked list | Fast insertions anywhere | ✅ ⭐ ✓ |
| [ForwardListExample.cpp](01_SequenceContainers/ForwardListExample.cpp) | 💻 270+ | Singly-linked list | Memory efficient | ✅ ⭐ ✓ |
| [ArrayExample.cpp](01_SequenceContainers/ArrayExample.cpp) | 💻 250+ | Fixed-size array | Compile-time size, no overhead | ✅ ⭐ ✓ |

### VectorExample.cpp Topics
1. ✅ Basic operations (push_back, pop_back, access)
2. ✅ Capacity management (reserve, shrink_to_fit)
3. ✅ Iterator usage (begin, end, rbegin, rend)
4. ✅ Algorithms with vectors
5. ✅ Performance analysis
6. ✅ 2D vectors
7. ✅ Vector of custom objects
8. ✅ Common pitfalls

### DequeExample.cpp Topics
1. ✅ Basic operations (push_front, push_back)
2. ✅ Random access
3. ✅ Comparison with vector
4. ✅ Use cases (sliding window)
5. ✅ Iterator usage
6. ✅ Performance characteristics
7. ✅ Memory layout
8. ✅ When to use deque

### ListExample.cpp Topics
1. ✅ Basic operations (insert, erase)
2. ✅ Splice operations
3. ✅ Sorting and merging
4. ✅ Unique and reverse
5. ✅ Comparison with vector
6. ✅ Node-based structure benefits
7. ✅ Iterator stability
8. ✅ Use cases

### ForwardListExample.cpp Topics
1. ✅ Single-direction operations
2. ✅ Insert_after, erase_after
3. ✅ Memory efficiency
4. ✅ Comparison with list
5. ✅ Iterator limitations
6. ✅ Use cases
7. ✅ Performance benefits
8. ✅ Best practices

### ArrayExample.cpp Topics
1. ✅ Fixed-size array usage
2. ✅ Comparison with C arrays
3. ✅ Compile-time features
4. ✅ Zero overhead
5. ✅ Standard algorithms
6. ✅ Multi-dimensional arrays
7. ✅ Modern C++ integration
8. ✅ When to use array

---

## 🔑 02_AssociativeContainers

**Purpose:** Ordered, key-based data structures implemented as Red-Black Trees

| File | Lines | Description | Key Features | Status |
|------|-------|-------------|--------------|--------|
| [README.md](02_AssociativeContainers/README.md) | 📖 | Overview of associative containers | Tree-based structures | ✅ ⭐ ✓ |
| [SetExample.cpp](02_AssociativeContainers/SetExample.cpp) | 💻 280+ | Ordered unique elements | Sorted, O(log n) operations | ✅ ⭐ ✓ |
| [MapExample.cpp](02_AssociativeContainers/MapExample.cpp) | 💻 320+ | Key-value pairs (unique keys) | Dictionary operations | ✅ ⭐ ✓ |
| [MultisetExample.cpp](02_AssociativeContainers/MultisetExample.cpp) | 💻 270+ | Ordered elements with duplicates | Duplicate handling | ✅ ⭐ ✓ |
| [MultimapExample.cpp](02_AssociativeContainers/MultimapExample.cpp) | 💻 280+ | Key-value pairs (duplicate keys) | One-to-many mapping | ✅ ⭐ ✓ |

### SetExample.cpp Topics
1. ✅ Basic operations (insert, erase, find)
2. ✅ Set operations (union, intersection, difference)
3. ✅ Lower_bound, upper_bound
4. ✅ Custom comparators
5. ✅ Iterator usage
6. ✅ Use cases (unique sorted collection)
7. ✅ Performance analysis
8. ✅ Comparison with unordered_set

### MapExample.cpp Topics
1. ✅ Basic operations (insert, erase, find)
2. ✅ Element access ([], at)
3. ✅ Iteration techniques
4. ✅ Structured bindings (C++17)
5. ✅ Custom comparators
6. ✅ Use cases (dictionary, counting)
7. ✅ Performance characteristics
8. ✅ Comparison with unordered_map

### MultisetExample.cpp Topics
1. ✅ Duplicate element handling
2. ✅ Count operations
3. ✅ Equal_range
4. ✅ Use cases (frequency counting)
5. ✅ Iterator ranges
6. ✅ Comparison with set
7. ✅ Performance analysis
8. ✅ Real-world applications

### MultimapExample.cpp Topics
1. ✅ Multiple values per key
2. ✅ Equal_range usage
3. ✅ Iteration strategies
4. ✅ Use cases (one-to-many relations)
5. ✅ Comparison with map
6. ✅ Performance characteristics
7. ✅ Custom comparators
8. ✅ Best practices

---

## #️⃣ 03_UnorderedContainers

**Purpose:** Hash-based data structures for O(1) average-case operations

| File | Lines | Description | Key Features | Status |
|------|-------|-------------|--------------|--------|
| [README.md](03_UnorderedContainers/README.md) | 📖 | Overview of unordered containers | Hash table implementation | ✅ ⭐ ✓ |
| [UnorderedSetExample.cpp](03_UnorderedContainers/UnorderedSetExample.cpp) | 💻 290+ | Hash set | Fast lookups, unique elements | ✅ ⭐ ✓ |
| [UnorderedMapExample.cpp](03_UnorderedContainers/UnorderedMapExample.cpp) | 💻 320+ | Hash map | Fast key-value lookups | ✅ ⭐ ✓ |
| [UnorderedMultisetExample.cpp](03_UnorderedContainers/UnorderedMultisetExample.cpp) | 💻 270+ | Hash multiset | Fast lookups with duplicates | ✅ ⭐ ✓ |
| [UnorderedMultimapExample.cpp](03_UnorderedContainers/UnorderedMultimapExample.cpp) | 💻 280+ | Hash multimap | Fast lookups, duplicate keys | ✅ ⭐ ✓ |

### UnorderedSetExample.cpp Topics
1. ✅ Basic operations (insert, erase, find)
2. ✅ Hash function basics
3. ✅ Bucket interface
4. ✅ Load factor management
5. ✅ Custom hash functions
6. ✅ Comparison with set
7. ✅ Performance characteristics
8. ✅ Use cases

### UnorderedMapExample.cpp Topics
1. ✅ Basic operations (insert, erase, find)
2. ✅ Element access ([], at)
3. ✅ Custom hash functions
4. ✅ Custom equality functions
5. ✅ Bucket management
6. ✅ Rehashing operations
7. ✅ Performance optimization
8. ✅ Real-world applications

### UnorderedMultisetExample.cpp Topics
1. ✅ Duplicate handling with hashing
2. ✅ Count operations
3. ✅ Equal_range with buckets
4. ✅ Custom hash functions
5. ✅ Performance characteristics
6. ✅ Comparison with multiset
7. ✅ Use cases
8. ✅ Best practices

### UnorderedMultimapExample.cpp Topics
1. ✅ Multiple values per key (hashed)
2. ✅ Equal_range usage
3. ✅ Custom hash and equality
4. ✅ Bucket operations
5. ✅ Performance optimization
6. ✅ Comparison with multimap
7. ✅ Use cases
8. ✅ Implementation details

---

## 🔄 04_ContainerAdaptors

**Purpose:** Specialized interfaces built on underlying containers

| File | Lines | Description | Key Features | Status |
|------|-------|-------------|--------------|--------|
| [README.md](04_ContainerAdaptors/README.md) | 📖 | Overview of container adaptors | LIFO, FIFO, Priority patterns | ✅ ⭐ ✓ |
| [StackExample.cpp](04_ContainerAdaptors/StackExample.cpp) | 💻 260+ | LIFO structure | Push, pop, top operations | ✅ ⭐ ✓ |
| [QueueExample.cpp](04_ContainerAdaptors/QueueExample.cpp) | 💻 260+ | FIFO structure | Enqueue, dequeue operations | ✅ ⭐ ✓ |
| [PriorityQueueExample.cpp](04_ContainerAdaptors/PriorityQueueExample.cpp) | 💻 300+ | Heap-based priority queue | Max/min heap, custom priority | ✅ ⭐ ✓ |

### StackExample.cpp Topics
1. ✅ Basic operations (push, pop, top)
2. ✅ LIFO demonstration
3. ✅ Use cases (function call stack, expression evaluation)
4. ✅ Underlying container selection
5. ✅ Custom container adaptor
6. ✅ Performance characteristics
7. ✅ Real-world applications
8. ✅ Best practices

### QueueExample.cpp Topics
1. ✅ Basic operations (push, pop, front, back)
2. ✅ FIFO demonstration
3. ✅ Use cases (task scheduling, BFS)
4. ✅ Underlying container selection
5. ✅ Custom queue implementation
6. ✅ Performance characteristics
7. ✅ Real-world applications
8. ✅ Best practices

### PriorityQueueExample.cpp Topics
1. ✅ Max-heap operations
2. ✅ Min-heap configuration
3. ✅ Custom comparators
4. ✅ Priority management
5. ✅ Use cases (Dijkstra, event scheduling)
6. ✅ Heap properties
7. ✅ Performance characteristics
8. ✅ Advanced applications

---

## 🔍 Quick File Lookup

### By Complexity Level

**Beginner (Start Here):**
- VectorExample.cpp
- ArrayExample.cpp
- StackExample.cpp
- QueueExample.cpp

**Intermediate:**
- DequeExample.cpp
- SetExample.cpp
- MapExample.cpp
- UnorderedSetExample.cpp
- UnorderedMapExample.cpp
- PriorityQueueExample.cpp

**Advanced:**
- ListExample.cpp
- ForwardListExample.cpp
- MultisetExample.cpp
- MultimapExample.cpp
- UnorderedMultisetExample.cpp
- UnorderedMultimapExample.cpp

### By Use Case

**General Purpose Collection:**
- VectorExample.cpp ⭐ Most common

**Fast Lookup:**
- UnorderedMapExample.cpp (unordered)
- MapExample.cpp (ordered)
- UnorderedSetExample.cpp (unordered)
- SetExample.cpp (ordered)

**Frequent Insertions/Deletions:**
- ListExample.cpp (anywhere)
- DequeExample.cpp (both ends)
- ForwardListExample.cpp (memory efficient)

**Special Operations:**
- StackExample.cpp (LIFO)
- QueueExample.cpp (FIFO)
- PriorityQueueExample.cpp (priority-based)

**Duplicate Handling:**
- MultisetExample.cpp (ordered)
- MultimapExample.cpp (ordered)
- UnorderedMultisetExample.cpp (unordered)
- UnorderedMultimapExample.cpp (unordered)

---

## 📊 Learning Path by File

### Week 1: Fundamentals
**Day 1-2:** VectorExample.cpp, ArrayExample.cpp
**Day 3-4:** DequeExample.cpp
**Day 5-6:** StackExample.cpp, QueueExample.cpp
**Day 7:** Review and practice

### Week 2: Ordered Containers
**Day 1-2:** SetExample.cpp
**Day 3-4:** MapExample.cpp
**Day 5:** MultisetExample.cpp
**Day 6:** MultimapExample.cpp
**Day 7:** Review and practice

### Week 3: Hash-Based Containers
**Day 1-2:** UnorderedSetExample.cpp
**Day 3-4:** UnorderedMapExample.cpp
**Day 5:** UnorderedMultisetExample.cpp
**Day 6:** UnorderedMultimapExample.cpp
**Day 7:** Review and practice

### Week 4: Advanced Topics
**Day 1-2:** ListExample.cpp
**Day 3-4:** ForwardListExample.cpp
**Day 5-6:** PriorityQueueExample.cpp
**Day 7:** Final review and projects

---

## 🎯 Interview Preparation Guide

### Must-Know Files (80% of interviews)
1. ✅ VectorExample.cpp - Most common container
2. ✅ MapExample.cpp - Key-value operations
3. ✅ UnorderedMapExample.cpp - Fast lookups
4. ✅ SetExample.cpp - Unique elements
5. ✅ StackExample.cpp - LIFO operations
6. ✅ QueueExample.cpp - FIFO operations
7. ✅ PriorityQueueExample.cpp - Heap operations

### Important Files (15% of interviews)
8. ✅ DequeExample.cpp - Double-ended operations
9. ✅ UnorderedSetExample.cpp - Fast set operations
10. ✅ ListExample.cpp - Linked list operations

### Advanced Files (5% of interviews)
11. ✅ MultisetExample.cpp
12. ✅ MultimapExample.cpp
13. ✅ ForwardListExample.cpp

---

## 🛠️ Build Files Reference

| File | Purpose | Platform | Status |
|------|---------|----------|--------|
| CMakeLists.txt | CMake build configuration | All | ✅ |
| compile_all.sh | Bash compilation script | Linux/Mac | ✅ |
| compile_all.ps1 | PowerShell compilation script | Windows | ✅ |

---

## 📖 Documentation Files Reference

| File | Purpose | Audience | Length |
|------|---------|----------|--------|
| README.md | Main entry, learning path | All | Long |
| QUICK_REFERENCE.md | Syntax cheat sheet | Quick lookup | Medium |
| PROJECT_SUMMARY.md | Statistics and metrics | Overview | Medium |
| INDEX.md | Navigation guide | All | Long |
| STRUCTURE.md | Directory organization | All | Short |
| TESTING.md | Build and test instructions | Developers | Medium |

---

## 🔗 Cross-References

### Related Topics in Other Modules
- **STL Algorithms:** Works extensively with these containers
- **Memory Management:** Understanding container memory allocation
- **Templates:** Containers are template-based
- **Modern C++:** Modern features used throughout

### Prerequisites
- Basic C++ syntax
- Pointers and references
- Template basics

### Next Steps After This Module
1. STL Algorithms module (uses these containers)
2. Modern C++ module (advanced container features)
3. Memory Management module (custom allocators)

---

**Last Updated:** 2025-11-14

**Total Files:** 23 (17 .cpp + 6 docs)

**Estimated Study Time:** 4 weeks (2-3 hours/day)

**Difficulty:** Beginner to Advanced

**Completion Rate:** 100% ✅

