# 📦 Sequence Containers

## Overview

Sequence containers store elements in a linear sequence and provide various ways to access and manipulate the elements. They maintain the order in which elements are inserted (unless explicitly modified).

## Containers in This Section

| Container | Description | Best For | Time Complexity (Access) |
|-----------|-------------|----------|-------------------------|
| **vector** | Dynamic array | General-purpose, random access | O(1) |
| **deque** | Double-ended queue | Fast insertions at both ends | O(1) |
| **list** | Doubly-linked list | Fast insertions anywhere | O(n) |
| **forward_list** | Singly-linked list | Memory-efficient linked list | O(n) |
| **array** | Fixed-size array | Fixed-size, compile-time known | O(1) |

## Quick Comparison

### Memory Layout
- **Contiguous:** vector, array, deque (chunked)
- **Node-based:** list, forward_list

### Performance Characteristics

| Operation | vector | deque | list | forward_list | array |
|-----------|--------|-------|------|--------------|-------|
| Random access | O(1) | O(1) | O(n) | O(n) | O(1) |
| Insert/delete at beginning | O(n) | O(1) | O(1) | O(1) | - |
| Insert/delete at end | O(1)* | O(1) | O(1) | - | - |
| Insert/delete in middle | O(n) | O(n) | O(1) | O(1) | - |
| Memory overhead | Low | Medium | High | Medium | None |

*O(1) amortized

## When to Use Each

### Use vector when:
- ✅ You need random access
- ✅ You primarily add/remove from the end
- ✅ Cache performance matters
- ✅ You want the default choice (use unless you have a reason not to)

### Use deque when:
- ✅ You need fast insertions/deletions at both ends
- ✅ You need random access
- ✅ You don't need iterator/pointer stability

### Use list when:
- ✅ You need fast insertions/deletions anywhere with an iterator
- ✅ You need iterator stability (iterators remain valid after modifications)
- ✅ You frequently splice lists together
- ✅ You don't need random access

### Use forward_list when:
- ✅ You need memory efficiency over list
- ✅ You only need forward iteration
- ✅ You primarily insert after a given position

### Use array when:
- ✅ Size is known at compile time
- ✅ You want zero overhead
- ✅ You prefer STL interface over C arrays

## Examples in This Section

1. **[VectorExample.cpp](VectorExample.cpp)** - Most commonly used container
2. **[DequeExample.cpp](DequeExample.cpp)** - Double-ended operations
3. **[ListExample.cpp](ListExample.cpp)** - Linked list operations
4. **[ForwardListExample.cpp](ForwardListExample.cpp)** - Singly-linked list
5. **[ArrayExample.cpp](ArrayExample.cpp)** - Fixed-size array

## Common Operations

### Capacity Operations
```cpp
size()          // Number of elements
empty()         // Check if empty
max_size()      // Maximum possible size
```

### Vector/Deque Specific
```cpp
capacity()      // Allocated capacity (vector only)
reserve(n)      // Reserve capacity (vector only)
shrink_to_fit() // Release unused memory
```

### Element Access
```cpp
operator[]      // Unchecked access
at()           // Bounds-checked access
front()        // First element
back()         // Last element (not forward_list)
```

### Modifiers
```cpp
push_back()    // Add to end (not forward_list)
pop_back()     // Remove from end (not forward_list)
push_front()   // Add to front (deque, list, forward_list)
pop_front()    // Remove from front (deque, list, forward_list)
insert()       // Insert at position
erase()        // Remove at position
clear()        // Remove all elements
```

## Best Practices

1. ✅ **Default to vector** - Use unless you have a specific reason not to
2. ✅ **Reserve capacity** - Call `reserve()` for vectors when final size is known
3. ✅ **Use emplace** - Prefer `emplace_back()` over `push_back()` for efficiency
4. ✅ **Range-based for** - Use modern C++ iteration when possible
5. ✅ **Const correctness** - Use const references when not modifying

## Common Pitfalls

1. ❌ **Iterator invalidation** - Modifying vector can invalidate iterators
2. ❌ **Unnecessary copies** - Pass containers by const reference
3. ❌ **Not reserving capacity** - Leads to multiple reallocations
4. ❌ **Using list when vector works** - Poor cache performance
5. ❌ **Accessing out of bounds** - Always check bounds or use `at()`

---

**Next:** Start with [VectorExample.cpp](VectorExample.cpp) - the most important sequence container!

