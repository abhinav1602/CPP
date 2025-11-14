# ✏️ Modifying Algorithms

Algorithms that modify elements in a range.

## Algorithms Covered

- `std::copy` - Copy elements
- `std::transform` - Apply function to elements
- `std::replace` - Replace values
- `std::remove` - Remove elements (use with erase)
- `std::fill` - Fill range with value

## Key Concept: Remove-Erase Idiom

```cpp
auto new_end = std::remove(vec.begin(), vec.end(), value);
vec.erase(new_end, vec.end());
```

## Examples

1. [CopyExample.cpp](CopyExample.cpp)
2. [TransformExample.cpp](TransformExample.cpp)
3. [ReplaceExample.cpp](ReplaceExample.cpp)
4. [RemoveExample.cpp](RemoveExample.cpp)
5. [FillExample.cpp](FillExample.cpp)

