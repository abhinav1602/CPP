# Memory Management Quick Reference

| Concept | Example | Notes |
|---------|---------|-------|
| Raw pointer | `int* p = &x;` | No ownership semantics |
| new/delete | `int* p=new int; delete p;` | Pair correctly |
| new[]/delete[] | allocate arrays | Use `delete[]` |
| smart ptr | `auto up=std::make_unique<T>()` | Prefer over raw |
| shared refcount | `use_count()` | Avoid cycles (weak_ptr) |
| placement new | `new(buf) T();` | Manual lifetime |
| custom alloc | allocator concept | For performance/control |

Idioms:
```cpp
auto sp = std::make_shared<int>(5);
std::weak_ptr<int> wp = sp;
if(auto l=wp.lock()) { /* use */ }
```

