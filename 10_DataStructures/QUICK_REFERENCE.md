# Data Structures Quick Reference

| Structure | Operations | Complexity (avg) | Notes |
|-----------|------------|------------------|-------|
| LinkedList | push_front, remove | O(1)/O(n) | Sequential traversal |
| Stack | push, pop, top | O(1) | LIFO |
| Queue | enqueue, dequeue | O(1) amortized | FIFO circular buffer |
| BST | insert, search | O(log n) avg | Unbalanced worst O(n) |
| Graph (adj list) | addEdge, BFS/DFS | O(V+E) | Sparse efficient |
| HashTable | insert, contains | O(1) avg | Probe sequences |
| Trie | insert, contains | O(L) | Prefix queries |

Traversal:
```cpp
for(Node* cur=head.get();cur;cur=cur->next.get()) {}
```

