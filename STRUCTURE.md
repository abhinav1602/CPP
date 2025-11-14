# 🗂️ Repository Structure

**Directory organization and naming conventions**

*Last Updated: November 15, 2025*

---

## Directory Tree

```
CPP/
│
├── README.md                    # Main overview
├── PROJECT_SUMMARY.md           # Statistics & metrics
├── QUICK_REFERENCE.md           # Global syntax reference
├── INDEX.md                     # Navigation guide
├── STRUCTURE.md                 # This file
├── CONTRIBUTING.md              # Contribution guidelines
├── LICENSE                      # CC BY-NC-SA 4.0
│
├── 01_STL_Containers/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── 01_SequenceContainers/
│   │   ├── README.md
│   │   ├── VectorExample.cpp
│   │   ├── DequeExample.cpp
│   │   ├── ListExample.cpp
│   │   ├── ForwardListExample.cpp
│   │   └── ArrayExample.cpp
│   ├── 02_AssociativeContainers/
│   │   ├── README.md
│   │   ├── SetExample.cpp
│   │   ├── MapExample.cpp
│   │   ├── MultisetExample.cpp
│   │   └── MultimapExample.cpp
│   ├── 03_UnorderedContainers/
│   │   └── ... (4 examples)
│   └── 04_ContainerAdaptors/
│       └── ... (3 examples)
│
├── 02_STL_Algorithms/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── 01_NonModifyingAlgorithms/ (4 examples)
│   ├── 02_ModifyingAlgorithms/ (5 examples)
│   ├── 03_SortingAlgorithms/ (4 examples)
│   ├── 04_NumericAlgorithms/ (3 examples)
│   └── 05_SetOperations/ (2 examples)
│
├── 03_MemoryManagement/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── 01_Pointers/ (3 examples)
│   ├── 02_SmartPointers/ (3 examples)
│   ├── 03_RAII/ (1 example)
│   ├── 04_DynamicMemory/ (3 examples)
│   └── 05_CustomAllocators/ (2 examples)
│
├── 04_OOP/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── 01_Classes/ (3 examples)
│   ├── 02_Inheritance/ (3 examples)
│   ├── 03_Polymorphism/ (4 examples)
│   ├── 04_OperatorOverloading/ (2 examples)
│   └── 05_SpecialMemberFunctions/ (2 examples)
│
├── 05_Templates/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── 01_FunctionTemplates/ (1 example)
│   ├── 02_ClassTemplates/ (1 example)
│   ├── 03_TemplateSpecialization/ (1 example)
│   ├── 04_VariadicTemplates/ (1 example)
│   └── 05_SFINAE_Concepts/ (2 examples)
│
├── 06_ModernCpp/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── 01_AutoDecltype/ (2 examples)
│   ├── 02_LambdaExpressions/ (2 examples)
│   ├── 03_MoveSemantics/ (3 examples)
│   ├── 04_SmartPointers/ (2 examples)
│   ├── 05_Constexpr/ (1 example)
│   ├── 06_StructuredBindings/ (1 example)
│   └── 07_RangesViews/ (1 example)
│
├── 07_Multithreading/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── 01_Threads/ (3 examples)
│   ├── 02_Synchronization/ (2 examples)
│   ├── 03_ConditionVariables/ (1 example)
│   ├── 04_Atomic/ (1 example)
│   └── 05_AsyncFuture/ (2 examples)
│
├── 08_FileIO/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── 01_BasicIO/ (1 example)
│   ├── 02_FileStreams/ (3 examples)
│   ├── 03_StringStreams/ (1 example)
│   └── 04_Formatting/ (1 example)
│
├── 09_ExceptionHandling/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── 01_TryCatchFinally/ (2 examples)
│   ├── 02_CustomExceptions/ (2 examples)
│   ├── 03_ExceptionSafety/ (1 example)
│   └── 04_Noexcept/ (1 example)
│
└── 10_DataStructures/
    ├── README.md
    ├── QUICK_REFERENCE.md
    ├── 01_LinkedList/ (2 examples)
    ├── 02_Stack/ (2 examples)
    ├── 03_Queue/ (1 example)
    ├── 04_BinaryTree/ (1 example)
    ├── 05_Graph/ (1 example)
    ├── 06_HashTable/ (1 example)
    └── 07_Trie/ (1 example)
```

---

## File Types

### Root Level
- **README.md** - Repository overview and quick start
- **PROJECT_SUMMARY.md** - Statistics and module status
- **QUICK_REFERENCE.md** - C++ syntax cheat sheet
- **INDEX.md** - Navigation across modules
- **STRUCTURE.md** - This file
- **CONTRIBUTING.md** - Contribution guidelines
- **LICENSE** - CC BY-NC-SA 4.0 terms

### Module Level
- **README.md** - Module topics, objectives, learning path
- **QUICK_REFERENCE.md** - Module-specific syntax reference

### Topic Level
- **README.md** - Brief topic introduction
- **ExampleName.cpp** - Runnable code (includes compilation command in comments)

---

## Naming Conventions

### Directories
- Numbered prefixes: `01_TopicName`, `02_SubTopic`
- PascalCase with underscores: `STL_Containers`, `ModernCpp`
- Hierarchical organization from general to specific

### Files
- Documentation: `README.md`, `QUICK_REFERENCE.md`
- Examples: `TopicNameExample.cpp` (descriptive PascalCase)
- All examples self-contained with embedded compilation instructions

---

## Navigation

Start with [README.md](README.md) for overview, then:
- Browse modules via [INDEX.md](INDEX.md)
- Quick syntax lookup in [QUICK_REFERENCE.md](QUICK_REFERENCE.md)
- Statistics in [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)
- Each module README provides learning path

---

## Compilation

Each .cpp file contains compilation instructions in comments:

```cpp
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 Example.cpp -o Example */
```

No build system required - simple command-line compilation.

---

*Organized for progressive learning from fundamentals to advanced topics.*

