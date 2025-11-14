# Modern C++ Quick Reference

| Feature | Example | Notes |
|---------|---------|-------|
| auto | `auto x=5;` | Type deduction |
| decltype | `decltype(x) y=0;` | Query type |
| range-for | `for(auto& e: c)` | Simpler loops |
| move | `std::move(obj)` | Transfer resources |
| forward | `std::forward<T>(v)` | Perfect forwarding |
| lambda | `[](int x){}` | Inline callable |
| constexpr | `constexpr int k=10;` | Compile-time const |
| structured bindings | `auto [a,b]=pair;` | Decomposition |
| smart pointers | `make_unique<T>()` | RAII |
| concepts | `std::integral T` | Constrained templates |
| ranges | `vec | views::filter(...)` | Lazy pipelines |

