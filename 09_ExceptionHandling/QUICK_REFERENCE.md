# Exception Handling Quick Reference

| Concept | Example | Guarantee |
|---------|---------|-----------|
| Throw | `throw std::runtime_error("err");` | Transfer control |
| Try/Catch | `try{...}catch(...)` | Handle failure |
| Custom exception | derive std::exception | Polymorphic what() |
| noexcept | `void f() noexcept;` | No throw promise |
| Basic safety | container operations | Valid state |
| Strong safety | commit/rollback | No partial effects |
| No-throw | operations that cannot fail | Performance |

Pattern:
```cpp
try { risky(); } catch(const std::exception& e){ log(e); }
```

