# Smart Pointers

Automatic memory management with ownership semantics.

Examples:
- SmartPointersExample.cpp (unique/shared/weak overview)
- See also Module 03 for deeper allocator & lifetime topics.

Key Types:
- `std::unique_ptr` exclusive ownership
- `std::shared_ptr` shared ownership w/ ref counting
- `std::weak_ptr` non-owning observation

Best Practices:
- Prefer `make_unique` / `make_shared`
- Avoid raw `new` in user code (except low-level facilities)
- Break cycles with `weak_ptr`
- Keep shared ownership minimal

