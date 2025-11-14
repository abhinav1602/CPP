# OOP Quick Reference

| Feature | Syntax | Purpose |
|---------|--------|---------|
| Class | `class X { ... };` | Encapsulation |
| Inheritance | `class D: public B {}` | Reuse/interface |
| Virtual | `virtual void f();` | Polymorphism |
| Override | `void f() override;` | Safe override |
| Abstract | `=0` pure virtual | Interface contract |
| Rule of Five | copy/move + dtor | Resource mgmt |

Example:
```cpp
struct Base { virtual void f()=0; virtual ~Base()=default; };
struct Impl : Base { void f() override {} };
```

