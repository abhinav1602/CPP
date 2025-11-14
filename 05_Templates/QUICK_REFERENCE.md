# Templates Quick Reference

| Feature | Example | Notes |
|---------|---------|-------|
| Function template | `template<class T> T max(T,T);` | Generic functions |
| Class template | `template<class T> struct Box{T v;};` | Generic types |
| Specialization | `template<> struct Box<int>{};` | Custom behavior |
| Variadic | `template<class... Ts>` | Parameter packs |
| SFINAE | `enable_if` | Conditional participation |
| Concepts (C++20) | `template<std::integral T>` | Cleaner constraints |

Fold:
```cpp
template<class... Ts> auto sum(Ts... xs){ return (xs + ...); }
```

