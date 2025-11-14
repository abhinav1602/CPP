# 🧪 STL Containers - Testing Guide

## 📋 Table of Contents
- [Prerequisites](#prerequisites)
- [Quick Start](#quick-start)
- [Compilation Methods](#compilation-methods)
- [Testing Individual Files](#testing-individual-files)
- [Testing All Files](#testing-all-files)
- [CMake Build](#cmake-build)
- [Expected Outputs](#expected-outputs)
- [Troubleshooting](#troubleshooting)
- [Memory Leak Detection](#memory-leak-detection)
- [Platform-Specific Notes](#platform-specific-notes)

---

## ✅ Prerequisites

### Compiler Requirements
| Compiler | Minimum Version | Recommended Version | C++ Standard |
|----------|----------------|---------------------|--------------|
| **g++** (GCC) | 7.0 | 11.3+ | C++17 |
| **clang++** | 5.0 | 14.0+ | C++17 |
| **MSVC** | 19.14 (VS 2017) | 19.30+ (VS 2022) | C++17 |

### Installation

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install build-essential cmake
g++ --version  # Verify installation
```

**macOS:**
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Or use Homebrew
brew install gcc cmake
```

**Windows:**
- **Option 1:** Install MinGW-w64
  - Download from: https://www.mingw-w64.org/
  - Add to PATH: `C:\mingw64\bin`

- **Option 2:** Install MSYS2
  - Download from: https://www.msys2.org/
  - Install: `pacman -S mingw-w64-x86_64-gcc`

- **Option 3:** Use Visual Studio 2019+
  - Install "Desktop development with C++"

---

## 🚀 Quick Start

### Compile and Run One Example (Linux/Mac)
```bash
cd 01_SequenceContainers
g++ -std=c++17 -Wall -Wextra -O2 VectorExample.cpp -o VectorExample
./VectorExample
```

### Compile and Run One Example (Windows - PowerShell)
```powershell
cd 01_SequenceContainers
g++ -std=c++17 -Wall -Wextra -O2 VectorExample.cpp -o VectorExample.exe
./VectorExample.exe
```

### Compile All Examples (Linux/Mac)
```bash
chmod +x compile_all.sh
./compile_all.sh
```

### Compile All Examples (Windows)
```powershell
./compile_all.ps1
```

---

## 🔧 Compilation Methods

### Method 1: Direct Compilation (Recommended for Single Files)

#### Using g++
```bash
# Basic compilation
g++ -std=c++17 -Wall -Wextra VectorExample.cpp -o VectorExample

# With optimization
g++ -std=c++17 -Wall -Wextra -O2 VectorExample.cpp -o VectorExample

# With all warnings
g++ -std=c++17 -Wall -Wextra -Wpedantic -O2 VectorExample.cpp -o VectorExample

# With debug symbols
g++ -std=c++17 -Wall -Wextra -g VectorExample.cpp -o VectorExample

# C++20 (if supported)
g++ -std=c++20 -Wall -Wextra -O2 VectorExample.cpp -o VectorExample
```

#### Using clang++
```bash
# Basic compilation
clang++ -std=c++17 -Wall -Wextra VectorExample.cpp -o VectorExample

# With optimization
clang++ -std=c++17 -Wall -Wextra -O2 VectorExample.cpp -o VectorExample

# With sanitizers (for debugging)
clang++ -std=c++17 -Wall -Wextra -fsanitize=address -fsanitize=undefined VectorExample.cpp -o VectorExample
```

#### Using MSVC (Visual Studio - Command Prompt)
```cmd
cl /EHsc /std:c++17 /W4 VectorExample.cpp
VectorExample.exe
```

### Method 2: Batch Compilation Scripts

#### Linux/Mac - compile_all.sh
```bash
#!/bin/bash

echo "=================================="
echo "Compiling STL Containers Examples"
echo "=================================="

success_count=0
fail_count=0
total_count=0

# Find all .cpp files recursively
for file in $(find . -name "*.cpp"); do
    ((total_count++))
    output="${file%.cpp}"
    
    echo ""
    echo "[$total_count] Compiling: $file"
    
    if g++ -std=c++17 -Wall -Wextra -O2 "$file" -o "$output" 2>&1; then
        echo "✅ Success: $file"
        ((success_count++))
    else
        echo "❌ Failed: $file"
        ((fail_count++))
    fi
done

echo ""
echo "=================================="
echo "Compilation Summary"
echo "=================================="
echo "Total:   $total_count"
echo "Success: $success_count"
echo "Failed:  $fail_count"
echo "=================================="

if [ $fail_count -eq 0 ]; then
    echo "✅ All files compiled successfully!"
    exit 0
else
    echo "❌ Some files failed to compile."
    exit 1
fi
```

#### Windows - compile_all.ps1
```powershell
Write-Host "==================================" -ForegroundColor Cyan
Write-Host "Compiling STL Containers Examples" -ForegroundColor Cyan
Write-Host "==================================" -ForegroundColor Cyan

$success_count = 0
$fail_count = 0
$total_count = 0

# Find all .cpp files recursively
Get-ChildItem -Recurse -Filter *.cpp | ForEach-Object {
    $total_count++
    $file = $_.FullName
    $output = $file -replace '\.cpp$', '.exe'
    
    Write-Host ""
    Write-Host "[$total_count] Compiling: $file" -ForegroundColor Yellow
    
    $result = & g++ -std=c++17 -Wall -Wextra -O2 $file -o $output 2>&1
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✅ Success: $file" -ForegroundColor Green
        $success_count++
    } else {
        Write-Host "❌ Failed: $file" -ForegroundColor Red
        Write-Host $result -ForegroundColor Red
        $fail_count++
    }
}

Write-Host ""
Write-Host "==================================" -ForegroundColor Cyan
Write-Host "Compilation Summary" -ForegroundColor Cyan
Write-Host "==================================" -ForegroundColor Cyan
Write-Host "Total:   $total_count" -ForegroundColor White
Write-Host "Success: $success_count" -ForegroundColor Green
Write-Host "Failed:  $fail_count" -ForegroundColor Red
Write-Host "==================================" -ForegroundColor Cyan

if ($fail_count -eq 0) {
    Write-Host "✅ All files compiled successfully!" -ForegroundColor Green
    exit 0
} else {
    Write-Host "❌ Some files failed to compile." -ForegroundColor Red
    exit 1
}
```

### Method 3: CMake Build System

#### CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.10)
project(STL_Containers)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Sequence Containers
add_executable(VectorExample 01_SequenceContainers/VectorExample.cpp)
add_executable(DequeExample 01_SequenceContainers/DequeExample.cpp)
add_executable(ListExample 01_SequenceContainers/ListExample.cpp)
add_executable(ForwardListExample 01_SequenceContainers/ForwardListExample.cpp)
add_executable(ArrayExample 01_SequenceContainers/ArrayExample.cpp)

# Associative Containers
add_executable(SetExample 02_AssociativeContainers/SetExample.cpp)
add_executable(MapExample 02_AssociativeContainers/MapExample.cpp)
add_executable(MultisetExample 02_AssociativeContainers/MultisetExample.cpp)
add_executable(MultimapExample 02_AssociativeContainers/MultimapExample.cpp)

# Unordered Containers
add_executable(UnorderedSetExample 03_UnorderedContainers/UnorderedSetExample.cpp)
add_executable(UnorderedMapExample 03_UnorderedContainers/UnorderedMapExample.cpp)
add_executable(UnorderedMultisetExample 03_UnorderedContainers/UnorderedMultisetExample.cpp)
add_executable(UnorderedMultimapExample 03_UnorderedContainers/UnorderedMultimapExample.cpp)

# Container Adaptors
add_executable(StackExample 04_ContainerAdaptors/StackExample.cpp)
add_executable(QueueExample 04_ContainerAdaptors/QueueExample.cpp)
add_executable(PriorityQueueExample 04_ContainerAdaptors/PriorityQueueExample.cpp)

# Optional: Create a custom target to run all examples
add_custom_target(run_all
    COMMAND VectorExample
    COMMAND DequeExample
    COMMAND ListExample
    COMMAND ForwardListExample
    COMMAND ArrayExample
    COMMAND SetExample
    COMMAND MapExample
    COMMAND MultisetExample
    COMMAND MultimapExample
    COMMAND UnorderedSetExample
    COMMAND UnorderedMapExample
    COMMAND UnorderedMultisetExample
    COMMAND UnorderedMultimapExample
    COMMAND StackExample
    COMMAND QueueExample
    COMMAND PriorityQueueExample
    DEPENDS VectorExample DequeExample ListExample ForwardListExample ArrayExample
            SetExample MapExample MultisetExample MultimapExample
            UnorderedSetExample UnorderedMapExample UnorderedMultisetExample UnorderedMultimapExample
            StackExample QueueExample PriorityQueueExample
)
```

#### Using CMake
```bash
# Create build directory
mkdir build
cd build

# Configure
cmake ..

# Build all
cmake --build .

# Or use make (Linux/Mac)
make

# Run specific example
./VectorExample

# Run all examples (if custom target defined)
make run_all
```

---

## 📝 Testing Individual Files

### Test Sequence Containers
```bash
cd 01_SequenceContainers

# Vector
g++ -std=c++17 -Wall -Wextra -O2 VectorExample.cpp -o VectorExample && ./VectorExample

# Deque
g++ -std=c++17 -Wall -Wextra -O2 DequeExample.cpp -o DequeExample && ./DequeExample

# List
g++ -std=c++17 -Wall -Wextra -O2 ListExample.cpp -o ListExample && ./ListExample

# Forward List
g++ -std=c++17 -Wall -Wextra -O2 ForwardListExample.cpp -o ForwardListExample && ./ForwardListExample

# Array
g++ -std=c++17 -Wall -Wextra -O2 ArrayExample.cpp -o ArrayExample && ./ArrayExample
```

### Test Associative Containers
```bash
cd 02_AssociativeContainers

g++ -std=c++17 -Wall -Wextra -O2 SetExample.cpp -o SetExample && ./SetExample
g++ -std=c++17 -Wall -Wextra -O2 MapExample.cpp -o MapExample && ./MapExample
g++ -std=c++17 -Wall -Wextra -O2 MultisetExample.cpp -o MultisetExample && ./MultisetExample
g++ -std=c++17 -Wall -Wextra -O2 MultimapExample.cpp -o MultimapExample && ./MultimapExample
```

### Test Unordered Containers
```bash
cd 03_UnorderedContainers

g++ -std=c++17 -Wall -Wextra -O2 UnorderedSetExample.cpp -o UnorderedSetExample && ./UnorderedSetExample
g++ -std=c++17 -Wall -Wextra -O2 UnorderedMapExample.cpp -o UnorderedMapExample && ./UnorderedMapExample
g++ -std=c++17 -Wall -Wextra -O2 UnorderedMultisetExample.cpp -o UnorderedMultisetExample && ./UnorderedMultisetExample
g++ -std=c++17 -Wall -Wextra -O2 UnorderedMultimapExample.cpp -o UnorderedMultimapExample && ./UnorderedMultimapExample
```

### Test Container Adaptors
```bash
cd 04_ContainerAdaptors

g++ -std=c++17 -Wall -Wextra -O2 StackExample.cpp -o StackExample && ./StackExample
g++ -std=c++17 -Wall -Wextra -O2 QueueExample.cpp -o QueueExample && ./QueueExample
g++ -std=c++17 -Wall -Wextra -O2 PriorityQueueExample.cpp -o PriorityQueueExample && ./PriorityQueueExample
```

---

## 🎯 Expected Outputs

Each example produces formatted output showing:
1. **Header:** Example name and description
2. **Section Headers:** Numbered examples with descriptions
3. **Results:** Actual output from operations
4. **Explanations:** What each operation demonstrates

### Example Output Format
```
=== Vector Examples ===

1. Basic Operations:
Initial vector: 1 2 3 4 5
After push_back(6): 1 2 3 4 5 6
After pop_back(): 1 2 3 4 5
Size: 5, Capacity: 8

2. Iterators:
Using iterator: 1 2 3 4 5
Using reverse iterator: 5 4 3 2 1

... (more examples)
```

---

## 🐛 Troubleshooting

### Common Compilation Errors

#### Error: "g++ command not found"
**Solution:**
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS
xcode-select --install

# Windows - add to PATH or use full path
C:\mingw64\bin\g++.exe ...
```

#### Error: "unrecognized command line option '-std=c++17'"
**Solution:** Upgrade your compiler
```bash
g++ --version  # Check version
# Need GCC 7+ or Clang 5+
```

#### Error: "fatal error: iostream: No such file or directory"
**Solution:** Install C++ standard library
```bash
# Ubuntu/Debian
sudo apt-get install libstdc++-dev

# macOS
xcode-select --install
```

#### Warning: "unused variable"
**Solution:** Either use the variable or remove it. Our examples should have no warnings.

#### Error: "multiple definition of main"
**Solution:** Compile only one .cpp file at a time
```bash
# ❌ Wrong
g++ *.cpp -o output

# ✅ Correct
g++ VectorExample.cpp -o VectorExample
```

### Runtime Errors

#### Segmentation Fault
**Possible Causes:**
- Out-of-bounds access
- Dereferencing invalid iterator
- Stack overflow

**Debug:**
```bash
# Compile with debug symbols
g++ -std=c++17 -g VectorExample.cpp -o VectorExample

# Run with gdb
gdb ./VectorExample
run
bt  # backtrace
```

#### Memory Leaks
**Solution:** Use valgrind (Linux) or sanitizers
```bash
# Valgrind
valgrind --leak-check=full ./VectorExample

# AddressSanitizer
g++ -std=c++17 -fsanitize=address -g VectorExample.cpp -o VectorExample
./VectorExample
```

---

## 🔍 Memory Leak Detection

### Using Valgrind (Linux/Mac)
```bash
# Install valgrind
sudo apt-get install valgrind  # Ubuntu
brew install valgrind          # macOS

# Compile with debug symbols
g++ -std=c++17 -g VectorExample.cpp -o VectorExample

# Run with valgrind
valgrind --leak-check=full --show-leak-kinds=all ./VectorExample

# Expected output
# LEAK SUMMARY:
#    definitely lost: 0 bytes in 0 blocks
#    indirectly lost: 0 bytes in 0 blocks
#      possibly lost: 0 bytes in 0 blocks
```

### Using AddressSanitizer (All Platforms)
```bash
# Compile with sanitizer
g++ -std=c++17 -fsanitize=address -fsanitize=undefined -g VectorExample.cpp -o VectorExample

# Run (errors will be reported automatically)
./VectorExample
```

### Using Visual Studio (Windows)
1. Enable CRT Debug Heap
2. Use `_CrtDumpMemoryLeaks()` in code
3. Check Output window for leaks

---

## 🖥️ Platform-Specific Notes

### Linux
- ✅ Native support for g++ and clang++
- ✅ Valgrind available
- ✅ All features supported
- **Script:** Use `compile_all.sh`

### macOS
- ✅ Clang is default (Apple Clang)
- ⚠️ May need to install GCC separately for g++
- ⚠️ Valgrind support limited on newer macOS
- ✅ Use AddressSanitizer instead
- **Script:** Use `compile_all.sh`

### Windows
- ✅ MinGW-w64 recommended
- ✅ MSVC fully supported
- ❌ Valgrind not available (use Visual Studio tools)
- ✅ AddressSanitizer supported in recent MSVC
- **Script:** Use `compile_all.ps1`
- **Note:** Use `.exe` extension for executables

#### Windows-Specific Commands
```powershell
# Compile
g++ -std=c++17 -Wall -Wextra -O2 VectorExample.cpp -o VectorExample.exe

# Run
.\VectorExample.exe

# Or
./VectorExample.exe
```

---

## ✅ Validation Checklist

Before considering testing complete, verify:

- [ ] All files compile without errors
- [ ] All files compile without warnings (`-Wall -Wextra`)
- [ ] All programs run without crashing
- [ ] All programs produce expected output
- [ ] No memory leaks (valgrind or sanitizers)
- [ ] No undefined behavior (sanitizers)
- [ ] Code follows C++17 standard
- [ ] Examples demonstrate stated concepts
- [ ] Output is clear and educational

---

## 🚀 Performance Testing (Optional)

### Compile with Optimization
```bash
g++ -std=c++17 -O3 -march=native VectorExample.cpp -o VectorExample
```

### Benchmark with time
```bash
time ./VectorExample
```

### Profile with gprof (Linux)
```bash
g++ -std=c++17 -pg VectorExample.cpp -o VectorExample
./VectorExample
gprof VectorExample gmon.out > analysis.txt
```

---

## 📚 Additional Tools

### Static Analysis
```bash
# clang-tidy
clang-tidy VectorExample.cpp -- -std=c++17

# cppcheck
cppcheck --enable=all --std=c++17 VectorExample.cpp
```

### Formatting
```bash
# clang-format
clang-format -i VectorExample.cpp

# Or use .clang-format file for project-wide settings
```

---

## 🎓 Learning Exercises

After compiling and running examples:
1. **Modify examples:** Change values, add operations
2. **Break examples:** See what causes errors
3. **Measure performance:** Compare containers
4. **Write tests:** Create your own examples
5. **Debug:** Practice using gdb or sanitizers

---

**Last Updated:** 2025-11-14

**Tested Compilers:**
- GCC 11.3 (Ubuntu 22.04)
- Clang 14.0 (macOS 12.0)
- MSVC 19.30 (Visual Studio 2022)

**Status:** ✅ All examples compile and run successfully

**Support:** For issues, check troubleshooting section or review documentation.

