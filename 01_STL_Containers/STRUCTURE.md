# 🗂️ STL Containers - Structure Guide

## 📁 Directory Organization

This document explains the complete directory structure of the STL Containers module, including the purpose of each folder and file.

---

## 🌳 Complete Directory Tree

```
01_STL_Containers/
│
├── 📖 README.md                       # Main documentation - START HERE
├── 📖 QUICK_REFERENCE.md              # One-page cheat sheet
├── 📖 PROJECT_SUMMARY.md              # Statistics and metrics
├── 📖 INDEX.md                        # Complete file navigation
├── 📖 STRUCTURE.md                    # This file - directory guide
├── 📖 TESTING.md                      # Build and test instructions
│
├── 🔧 CMakeLists.txt                  # CMake build configuration
├── 🔧 compile_all.sh                  # Bash compilation script (Linux/Mac)
├── 🔧 compile_all.ps1                 # PowerShell script (Windows)
│
├── 📦 01_SequenceContainers/          # Linear data structures
│   │
│   ├── 📖 README.md                   # Sequence containers overview
│   │
│   ├── 💻 VectorExample.cpp           # std::vector - Dynamic array
│   │   │   Purpose: Most commonly used container
│   │   │   Topics: Random access, dynamic sizing, capacity
│   │   │   Lines: 300+
│   │
│   ├── 💻 DequeExample.cpp            # std::deque - Double-ended queue
│   │   │   Purpose: Efficient insertions at both ends
│   │   │   Topics: Push/pop front and back, random access
│   │   │   Lines: 280+
│   │
│   ├── 💻 ListExample.cpp             # std::list - Doubly-linked list
│   │   │   Purpose: Efficient insertions/deletions anywhere
│   │   │   Topics: Splice, merge, sort, bidirectional iteration
│   │   │   Lines: 290+
│   │
│   ├── 💻 ForwardListExample.cpp      # std::forward_list - Singly-linked
│   │   │   Purpose: Memory-efficient linked list
│   │   │   Topics: Forward-only iteration, insert_after
│   │   │   Lines: 270+
│   │
│   └── 💻 ArrayExample.cpp            # std::array - Fixed-size array
│       │   Purpose: C array replacement with STL interface
│       │   Topics: Compile-time size, zero overhead
│       │   Lines: 250+
│
├── 🔑 02_AssociativeContainers/       # Ordered, tree-based structures
│   │
│   ├── 📖 README.md                   # Associative containers overview
│   │
│   ├── 💻 SetExample.cpp              # std::set - Ordered unique elements
│   │   │   Purpose: Sorted unique collection
│   │   │   Topics: Binary search tree, O(log n) operations
│   │   │   Lines: 280+
│   │
│   ├── 💻 MapExample.cpp              # std::map - Key-value pairs
│   │   │   Purpose: Dictionary/associative array
│   │   │   Topics: Key-based lookup, ordered iteration
│   │   │   Lines: 320+
│   │
│   ├── 💻 MultisetExample.cpp         # std::multiset - Duplicates allowed
│   │   │   Purpose: Sorted collection with duplicates
│   │   │   Topics: Frequency counting, equal_range
│   │   │   Lines: 270+
│   │
│   └── 💻 MultimapExample.cpp         # std::multimap - Duplicate keys
│       │   Purpose: One-to-many relationships
│       │   Topics: Multiple values per key, equal_range
│       │   Lines: 280+
│
├── #️⃣ 03_UnorderedContainers/         # Hash-based structures
│   │
│   ├── 📖 README.md                   # Unordered containers overview
│   │
│   ├── 💻 UnorderedSetExample.cpp     # std::unordered_set - Hash set
│   │   │   Purpose: Fast unique element lookups
│   │   │   Topics: Hash functions, buckets, O(1) average
│   │   │   Lines: 290+
│   │
│   ├── 💻 UnorderedMapExample.cpp     # std::unordered_map - Hash map
│   │   │   Purpose: Fast key-value lookups
│   │   │   Topics: Hash tables, custom hash functions
│   │   │   Lines: 320+
│   │
│   ├── 💻 UnorderedMultisetExample.cpp # Hash multiset
│   │   │   Purpose: Fast lookups with duplicates
│   │   │   Topics: Hash-based duplicate handling
│   │   │   Lines: 270+
│   │
│   └── 💻 UnorderedMultimapExample.cpp # Hash multimap
│       │   Purpose: Fast lookups with duplicate keys
│       │   Topics: Hash-based one-to-many relations
│       │   Lines: 280+
│
└── 🔄 04_ContainerAdaptors/           # Specialized interfaces
    │
    ├── 📖 README.md                   # Container adaptors overview
    │
    ├── 💻 StackExample.cpp            # std::stack - LIFO structure
    │   │   Purpose: Last-In-First-Out operations
    │   │   Topics: Push, pop, top, call stack simulation
    │   │   Lines: 260+
    │
    ├── 💻 QueueExample.cpp            # std::queue - FIFO structure
    │   │   Purpose: First-In-First-Out operations
    │   │   Topics: Enqueue, dequeue, task queues
    │   │   Lines: 260+
    │
    └── 💻 PriorityQueueExample.cpp    # std::priority_queue - Heap
        │   Purpose: Priority-based operations
        │   Topics: Max-heap, min-heap, custom comparators
        │   Lines: 300+
```

---

## 📊 Organization Principles

### 1. Numbered Folders
- **Purpose:** Logical learning progression
- **Format:** `##_CategoryName/`
- **Benefits:**
  - Clear ordering
  - Easy navigation
  - Structured learning path

### 2. Category Grouping
Each major category has its own subfolder:
- **01_SequenceContainers:** Linear, sequential access
- **02_AssociativeContainers:** Tree-based, ordered
- **03_UnorderedContainers:** Hash-based, fast lookup
- **04_ContainerAdaptors:** Special-purpose interfaces

### 3. File Naming Convention
- **README.md:** Overview and guide for each section
- **ExampleName.cpp:** Runnable code examples
- **Format:** PascalCase for example names
- **Descriptive:** Names indicate container type

---

## 🎯 Navigation Strategy

### For Beginners
```
Start: README.md (module root)
  ↓
Read: QUICK_REFERENCE.md (syntax overview)
  ↓
Begin: 01_SequenceContainers/README.md
  ↓
Study: VectorExample.cpp (most important)
  ↓
Continue sequentially through numbered folders
```

### For Quick Reference
```
Go to: QUICK_REFERENCE.md
  ↓
Find specific container syntax
  ↓
Optional: Refer to detailed example file
```

### For Specific Topics
```
Check: INDEX.md
  ↓
Search for topic or use case
  ↓
Navigate to relevant file
```

---

## 📁 File Type Guide

### 📖 Documentation Files (.md)

#### Module-Level (Root Directory)
| File | Purpose | When to Read |
|------|---------|--------------|
| README.md | Main entry, learning path | First time, overview |
| QUICK_REFERENCE.md | Syntax cheat sheet | Quick lookup, reference |
| PROJECT_SUMMARY.md | Statistics, metrics | Overview, completion status |
| INDEX.md | Complete navigation | Finding specific topics |
| STRUCTURE.md | This file | Understanding organization |
| TESTING.md | Build instructions | Before compiling |

#### Category-Level (Subdirectories)
| File | Purpose | When to Read |
|------|---------|--------------|
| 01_SequenceContainers/README.md | Sequence containers overview | Before studying sequence containers |
| 02_AssociativeContainers/README.md | Tree-based containers overview | Before studying associative containers |
| 03_UnorderedContainers/README.md | Hash-based containers overview | Before studying unordered containers |
| 04_ContainerAdaptors/README.md | Adaptors overview | Before studying adaptors |

### 💻 Code Files (.cpp)

All code files follow this structure:
```cpp
/**
 * @file ExampleName.cpp
 * @brief Brief description
 * @author Learning Module
 * @date 2025-11-14
 */

// Includes

// Example functions (5-8 functions)

// Main function with clear output

// Compilation instructions
```

### 🔧 Build Files

| File | Purpose | Platform | Usage |
|------|---------|----------|-------|
| CMakeLists.txt | CMake configuration | All | `cmake . && make` |
| compile_all.sh | Bash script | Linux/Mac | `./compile_all.sh` |
| compile_all.ps1 | PowerShell script | Windows | `./compile_all.ps1` |

---

## 🎓 Learning Path Through Structure

### Phase 1: Foundation (Week 1)
```
📁 01_STL_Containers/
├── 📖 README.md                    ← Start here
├── 📖 QUICK_REFERENCE.md           ← Skim for overview
└── 📦 01_SequenceContainers/
    ├── 💻 VectorExample.cpp        ← Master this first
    ├── 💻 ArrayExample.cpp         ← Fixed-size alternative
    └── 💻 DequeExample.cpp         ← Both-ends operations
```

### Phase 2: Special Interfaces (Week 1-2)
```
📁 01_STL_Containers/
└── 🔄 04_ContainerAdaptors/
    ├── 💻 StackExample.cpp         ← LIFO operations
    ├── 💻 QueueExample.cpp         ← FIFO operations
    └── 💻 PriorityQueueExample.cpp ← Heap operations
```

### Phase 3: Ordered Containers (Week 2)
```
📁 01_STL_Containers/
└── 🔑 02_AssociativeContainers/
    ├── 💻 SetExample.cpp           ← Unique sorted elements
    ├── 💻 MapExample.cpp           ← Key-value pairs
    ├── 💻 MultisetExample.cpp      ← With duplicates
    └── 💻 MultimapExample.cpp      ← Multiple values per key
```

### Phase 4: Hash-Based Containers (Week 3)
```
📁 01_STL_Containers/
└── #️⃣ 03_UnorderedContainers/
    ├── 💻 UnorderedSetExample.cpp  ← Fast unique lookups
    ├── 💻 UnorderedMapExample.cpp  ← Fast key-value lookups
    └── 💻 Unordered*Example.cpp    ← Variants with duplicates
```

### Phase 5: Advanced Topics (Week 3-4)
```
📁 01_STL_Containers/
└── 📦 01_SequenceContainers/
    ├── 💻 ListExample.cpp          ← Linked list operations
    └── 💻 ForwardListExample.cpp   ← Memory-efficient variant
```

---

## 🔍 Finding Specific Topics

### By Container Type
- **Array-like:** 01_SequenceContainers/{Vector, Deque, Array}Example.cpp
- **List-like:** 01_SequenceContainers/{List, ForwardList}Example.cpp
- **Set-like:** 02_AssociativeContainers/{Set, Multiset}Example.cpp or 03_UnorderedContainers/Unordered{Set, Multiset}Example.cpp
- **Map-like:** 02_AssociativeContainers/{Map, Multimap}Example.cpp or 03_UnorderedContainers/Unordered{Map, Multimap}Example.cpp
- **Stack/Queue:** 04_ContainerAdaptors/{Stack, Queue, PriorityQueue}Example.cpp

### By Operation Type
- **Random Access:** VectorExample.cpp, DequeExample.cpp, ArrayExample.cpp
- **Fast Insertion/Deletion:** ListExample.cpp, ForwardListExample.cpp
- **Fast Lookup:** Unordered{Set, Map}Example.cpp
- **Sorted Order:** {Set, Map, Multiset, Multimap}Example.cpp
- **LIFO:** StackExample.cpp
- **FIFO:** QueueExample.cpp
- **Priority:** PriorityQueueExample.cpp

### By Use Case
- **General collection:** VectorExample.cpp
- **Dictionary:** MapExample.cpp or UnorderedMapExample.cpp
- **Unique elements:** SetExample.cpp or UnorderedSetExample.cpp
- **Task queue:** QueueExample.cpp
- **Expression evaluation:** StackExample.cpp
- **Event scheduling:** PriorityQueueExample.cpp
- **Graph adjacency:** VectorExample.cpp (vector of vectors)
- **Cache implementation:** ListExample.cpp + UnorderedMapExample.cpp

---

## 📏 File Size Reference

### Small Files (< 200 lines)
- None - all examples are comprehensive

### Medium Files (200-300 lines)
- Most example files fall in this range
- Includes multiple examples per file
- Comprehensive coverage of container features

### Large Files (> 300 lines)
- MapExample.cpp (320+ lines)
- UnorderedMapExample.cpp (320+ lines)
- PriorityQueueExample.cpp (300+ lines)
- More complex operations and use cases

---

## 🎨 Color Coding (In Documentation)

- 📖 Documentation files
- 💻 Runnable code examples
- 🔧 Build/configuration files
- 📦 Sequence containers category
- 🔑 Associative containers category
- #️⃣ Unordered containers category
- 🔄 Container adaptors category
- ✅ Complete and tested
- ⭐ Modern C++ features
- ✓ Validated and working

---

## 🔗 Cross-References

### Within This Module
- Each README.md references relevant example files
- QUICK_REFERENCE.md links to detailed examples
- INDEX.md provides complete navigation

### To Other Modules
- **STL_Algorithms:** Uses containers extensively
- **Memory Management:** Understanding allocators
- **Modern C++:** Advanced container features
- **Templates:** Container implementation details

---

## 📊 Statistics

| Category | Folders | .cpp Files | .md Files | Total Lines |
|----------|---------|-----------|-----------|-------------|
| Sequence Containers | 1 | 5 | 1 | ~1,400 |
| Associative Containers | 1 | 4 | 1 | ~1,150 |
| Unordered Containers | 1 | 4 | 1 | ~1,160 |
| Container Adaptors | 1 | 3 | 1 | ~820 |
| Module Documentation | - | - | 6 | - |
| **Total** | **4** | **17** | **10** | **~4,530+** |

---

## 🎯 Design Philosophy

### Hierarchical Organization
- Clear category separation
- Logical progression
- Easy to navigate
- Scales well

### Self-Contained Files
- Each .cpp file is independent
- Can be compiled and run separately
- Complete with examples and documentation
- No external dependencies

### Comprehensive Documentation
- Multiple levels of documentation
- Quick reference for experts
- Detailed guides for beginners
- Navigation aids for all users

### Modern C++ Standards
- C++17 as baseline
- C++20 features where applicable
- Best practices throughout
- Future-proof examples

---

**Last Updated:** 2025-11-14

**Total Directories:** 5 (1 root + 4 categories)

**Total Files:** 26 (17 .cpp + 9 .md + 3 build scripts)

**Organization Status:** ✅ Complete and Optimized

