# Smart Pointers Quick Reference

| Type | Creation | Release | Use Cases |
|------|----------|---------|----------|
| unique_ptr | `auto p = std::make_unique<T>()` | automatic (scope end) | sole ownership, RAII |
| shared_ptr | `auto sp = std::make_shared<T>()` | last owner destroyed | shared graphs, factories |
| weak_ptr | `std::weak_ptr<T> w = sp;` | non-owning | break cycles, cache |

Patterns:
```cpp
auto p = std::make_unique<Foo>();
auto sp = std::make_shared<Foo>();
std::weak_ptr<Foo> wp = sp; // lock when needed
if (auto locked = wp.lock()) { locked->method(); }
```

