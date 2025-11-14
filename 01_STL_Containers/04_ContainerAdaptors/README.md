# 🔄 Container Adaptors

## Overview

Container adaptors provide specialized interfaces built on top of underlying sequence containers. They restrict the interface to provide specific data structure behaviors (LIFO, FIFO, Priority).

## Adaptors in This Section

| Adaptor | Description | Operations | Underlying Default |
|---------|-------------|------------|-------------------|
| **stack** | LIFO (Last-In-First-Out) | push, pop, top | deque |
| **queue** | FIFO (First-In-First-Out) | push, pop, front, back | deque |
| **priority_queue** | Priority-based heap | push, pop, top | vector |

## Key Characteristics

### Not True Containers
- Adaptors wrap underlying containers
- Provide restricted interface
- Cannot iterate directly
- No direct element access (except top/front)

### Underlying Container Requirements

**stack** can use:
- deque (default)
- vector
- list

**queue** can use:
- deque (default)
- list

**priority_queue** can use:
- vector (default)
- deque

## Stack (LIFO)

### Operations
```cpp
push()     // Add to top - O(1)
pop()      // Remove from top - O(1)
top()      // Access top - O(1)
empty()    // Check if empty - O(1)
size()     // Number of elements - O(1)
```

### Use Cases
- Function call stack simulation
- Undo/Redo functionality
- Expression evaluation
- Depth-First Search (DFS)
- Backtracking algorithms

### Example
```cpp
std::stack<int> stk;
stk.push(1);
stk.push(2);
stk.push(3);
std::cout << stk.top();  // 3 (LIFO)
stk.pop();
std::cout << stk.top();  // 2
```

## Queue (FIFO)

### Operations
```cpp
push()     // Add to back - O(1)
pop()      // Remove from front - O(1)
front()    // Access front - O(1)
back()     // Access back - O(1)
empty()    // Check if empty - O(1)
size()     // Number of elements - O(1)
```

### Use Cases
- Task scheduling
- Breadth-First Search (BFS)
- Print job queues
- Request handling
- Buffer management

### Example
```cpp
std::queue<int> q;
q.push(1);
q.push(2);
q.push(3);
std::cout << q.front();  // 1 (FIFO)
q.pop();
std::cout << q.front();  // 2
```

## Priority Queue (Heap)

### Operations
```cpp
push()     // Insert element - O(log n)
pop()      // Remove top - O(log n)
top()      // Access top (max/min) - O(1)
empty()    // Check if empty - O(1)
size()     // Number of elements - O(1)
```

### Characteristics
- Max-heap by default (largest element at top)
- Can create min-heap with custom comparator
- Maintains heap property automatically

### Use Cases
- Dijkstra's algorithm
- Event scheduling
- Huffman coding
- Job scheduling by priority
- Top K elements problems

### Example
```cpp
// Max-heap (default)
std::priority_queue<int> maxPQ;
maxPQ.push(3);
maxPQ.push(1);
maxPQ.push(5);
std::cout << maxPQ.top();  // 5 (maximum)

// Min-heap
std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;
minPQ.push(3);
minPQ.push(1);
minPQ.push(5);
std::cout << minPQ.top();  // 1 (minimum)
```

## Choosing Underlying Container

### Stack
```cpp
std::stack<int> stk1;                          // deque (default)
std::stack<int, std::vector<int>> stk2;        // vector
std::stack<int, std::list<int>> stk3;          // list
```

**Recommendation:** Use default (deque) unless you have specific requirements.

### Queue
```cpp
std::queue<int> q1;                            // deque (default)
std::queue<int, std::list<int>> q2;            // list
```

**Recommendation:** Use default (deque) for best performance.

### Priority Queue
```cpp
std::priority_queue<int> pq1;                  // vector (default)
std::priority_queue<int, std::deque<int>> pq2; // deque
```

**Recommendation:** Use default (vector) for heap operations.

## Comparison Table

| Feature | stack | queue | priority_queue |
|---------|-------|-------|----------------|
| Access Pattern | LIFO | FIFO | Priority-based |
| Top/Front Access | O(1) | O(1) | O(1) |
| Insert | O(1) | O(1) | O(log n) |
| Remove | O(1) | O(1) | O(log n) |
| Iteration | No | No | No |
| Default Container | deque | deque | vector |
| Common Use | Recursion, Undo | Tasks, BFS | Scheduling, Heap |

## Examples in This Section

1. **[StackExample.cpp](StackExample.cpp)** - LIFO operations
2. **[QueueExample.cpp](QueueExample.cpp)** - FIFO operations
3. **[PriorityQueueExample.cpp](PriorityQueueExample.cpp)** - Heap operations

## Best Practices

1. ✅ **Use appropriate adaptor** for your access pattern
2. ✅ **Check empty()** before pop() or top()
3. ✅ **Use emplace()** for complex objects
4. ✅ **Choose right underlying container** for performance
5. ✅ **Consider priority_queue** for scheduling problems

## Common Pitfalls

1. ❌ **Calling top() on empty stack/queue** → Undefined behavior
2. ❌ **Trying to iterate** → Adaptors don't support iteration
3. ❌ **Forgetting pop() after top()** → Element still in container
4. ❌ **Confusing push_back with push** → Adaptors use push()
5. ❌ **Wrong priority_queue comparator** → Min/max confusion

## Design Patterns

### Stack Pattern
```cpp
// Process all elements (LIFO)
while (!stk.empty()) {
    auto item = stk.top();
    stk.pop();
    // Process item
}
```

### Queue Pattern
```cpp
// Process all elements (FIFO)
while (!q.empty()) {
    auto item = q.front();
    q.pop();
    // Process item
}
```

### Priority Queue Pattern
```cpp
// Process by priority
while (!pq.empty()) {
    auto item = pq.top();
    pq.pop();
    // Process highest priority item
}
```

## When to Use Each

### Use stack when:
- You need LIFO behavior
- Implementing recursion iteratively
- Undo/Redo functionality
- Expression parsing/evaluation
- DFS traversal

### Use queue when:
- You need FIFO behavior
- Task scheduling (first-come-first-served)
- BFS traversal
- Buffer implementation
- Producer-consumer patterns

### Use priority_queue when:
- Elements have priorities
- Need efficient min/max extraction
- Implementing heaps
- Scheduling by priority
- Graph algorithms (Dijkstra, Prim)

---

**Next:** Start with [StackExample.cpp](StackExample.cpp) for LIFO operations!

