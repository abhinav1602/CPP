# #️⃣ Unordered Containers

## Overview

Unordered containers are hash-based data structures that provide fast O(1) average-case lookup, insertion, and deletion. Unlike associative containers, they do not maintain any ordering of elements.

## Containers in This Section

| Container | Description | Duplicates | Average Complexity |
|-----------|-------------|------------|-------------------|
| **unordered_set** | Hash set of unique keys | No | O(1) |
| **unordered_map** | Hash map (key-value) | No (unique keys) | O(1) |
| **unordered_multiset** | Hash set with duplicates | Yes | O(1) |
| **unordered_multimap** | Hash map with duplicate keys | Yes | O(1) |

## Key Characteristics

### Implementation
- **Data Structure:** Hash Table
- **Ordering:** No ordering (unordered)
- **Memory:** High (buckets + linked lists for collisions)

### Performance

| Operation | Average Case | Worst Case |
|-----------|-------------|------------|
| Insert | O(1) | O(n) |
| Delete | O(1) | O(n) |
| Search | O(1) | O(n) |
| Iteration | O(n) | O(n) |

*Worst case occurs when many collisions happen (poor hash function)*

## Comparison: Unordered vs Ordered

| Feature | Unordered (hash) | Ordered (tree) |
|---------|-----------------|----------------|
| Search | O(1) average | O(log n) |
| Insert | O(1) average | O(log n) |
| Delete | O(1) average | O(log n) |
| Ordering | None | Sorted |
| Memory | Very High | High |
| Use Case | Speed priority | Order needed |

## When to Use Each

### Use unordered_set when:
- ✅ You need fast lookups (O(1))
- ✅ Order doesn't matter
- ✅ Checking existence frequently
- ✅ No range queries needed

### Use unordered_map when:
- ✅ You need fast key-value lookups
- ✅ Implementing caches
- ✅ Frequency counting (fast)
- ✅ Order not required

### Use unordered_multiset when:
- ✅ Fast lookups with duplicates
- ✅ Frequency counting without order
- ✅ Speed over ordering

### Use unordered_multimap when:
- ✅ One-to-many with fast access
- ✅ No ordering needed
- ✅ High-performance lookups

## Hash Function Basics

### Default Hash Support
These types work out-of-the-box:
- All integral types (int, long, etc.)
- Floating-point types
- Pointers
- std::string

### Custom Hash Functions
For custom types, you need to provide:
```cpp
struct MyHash {
    size_t operator()(const MyType& obj) const {
        // Compute and return hash value
        return std::hash<int>()(obj.id);
    }
};

std::unordered_set<MyType, MyHash> mySet;
```

## Bucket Interface

Unordered containers use buckets:
```cpp
bucket_count()      // Number of buckets
max_bucket_count()  // Maximum possible buckets
bucket_size(n)      // Elements in bucket n
bucket(key)         // Which bucket contains key
load_factor()       // Average elements per bucket
max_load_factor()   // Threshold for rehashing
rehash(n)          // Set bucket count to n
reserve(n)         // Reserve space for n elements
```

## Common Operations

### All Unordered Containers
```cpp
insert()       // Insert element - O(1) avg
erase()        // Remove element - O(1) avg
find()         // Find element - O(1) avg
count()        // Count occurrences - O(1) avg
clear()        // Remove all - O(n)
size()         // Number of elements
empty()        // Check if empty
```

### Map-Specific
```cpp
operator[]     // Access/insert with key - O(1) avg
at()          // Access with bounds check - O(1) avg
```

## Examples in This Section

1. **[UnorderedSetExample.cpp](UnorderedSetExample.cpp)** - Hash set
2. **[UnorderedMapExample.cpp](UnorderedMapExample.cpp)** - Hash map
3. **[UnorderedMultisetExample.cpp](UnorderedMultisetExample.cpp)** - Hash multiset
4. **[UnorderedMultimapExample.cpp](UnorderedMultimapExample.cpp)** - Hash multimap

## Best Practices

1. ✅ **Reserve capacity** when size is known: `reserve(n)`
2. ✅ **Provide good hash functions** - distributes keys evenly
3. ✅ **Monitor load factor** - keep below 1.0 for performance
4. ✅ **Use default hash when possible** - for standard types
5. ✅ **Combine hash values** properly for composite keys

## Common Pitfalls

1. ❌ **Poor hash function** → Many collisions → O(n) operations
2. ❌ **High load factor** → Performance degradation
3. ❌ **Not reserving capacity** → Multiple rehashes
4. ❌ **Assuming ordering** → Unordered containers have no order
5. ❌ **Using for range queries** → Use ordered containers instead

## Performance Tips

### Good Hash Function Properties
- Fast to compute
- Distributes keys evenly across buckets
- Minimizes collisions
- Deterministic (same input = same output)

### Load Factor Management
```cpp
// Keep load factor below 1.0 for best performance
if (map.load_factor() > 0.8) {
    map.rehash(map.bucket_count() * 2);
}
```

### When to Use Ordered vs Unordered

**Use Unordered (hash):**
- Pure lookup/existence checks
- No range queries
- No sorted iteration needed
- Performance is critical

**Use Ordered (tree):**
- Need sorted order
- Range queries (lower_bound, upper_bound)
- Ordered iteration required
- Predictable O(log n) performance

---

**Next:** Start with [UnorderedSetExample.cpp](UnorderedSetExample.cpp) for fast lookups!

