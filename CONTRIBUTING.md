# 🤝 Contributing to C++ Learning Modules

Thank you for your interest in contributing to this project! This document provides guidelines and instructions for contributing.

---

## 📋 Table of Contents

- [Code of Conduct](#code-of-conduct)
- [How Can I Contribute?](#how-can-i-contribute)
- [Development Setup](#development-setup)
- [Coding Standards](#coding-standards)
- [Documentation Standards](#documentation-standards)
- [Submission Guidelines](#submission-guidelines)
- [Review Process](#review-process)

---

## 📜 Code of Conduct

### Our Pledge

We are committed to providing a welcoming and inspiring community for all. Please be respectful and constructive in your interactions.

### Expected Behavior

- ✅ Be respectful and inclusive
- ✅ Provide constructive feedback
- ✅ Focus on what is best for the community
- ✅ Show empathy towards other contributors

### Unacceptable Behavior

- ❌ Harassment or discriminatory language
- ❌ Personal attacks or trolling
- ❌ Publishing others' private information
- ❌ Unethical or illegal behavior

---

## 🎯 How Can I Contribute?

### 1. Reporting Bugs

**Before submitting a bug report:**
- Check existing issues to avoid duplicates
- Verify the bug with the latest version
- Collect relevant information (compiler version, OS, error messages)

**When submitting a bug:**
- Use a clear, descriptive title
- Provide step-by-step reproduction instructions
- Include code samples and error messages
- Describe expected vs. actual behavior

### 2. Suggesting Enhancements

**Before suggesting:**
- Check if the feature already exists
- Review existing enhancement requests

**When suggesting:**
- Explain why this enhancement would be useful
- Provide examples of how it would be used
- Consider implementation complexity

### 3. Improving Documentation

Documentation contributions are highly valued!

**Areas needing help:**
- Fixing typos and grammatical errors
- Clarifying confusing explanations
- Adding more examples
- Improving code comments
- Translating documentation (future)

### 4. Contributing Code

**Types of code contributions:**
- New example files
- Bug fixes
- Performance improvements
- New modules (coordinated with maintainers)
- Test cases

---

## 🛠️ Development Setup

### Prerequisites

**Required:**
- C++17 compatible compiler (g++ 7+, clang++ 5+, MSVC 19.14+)
- Git
- Text editor or IDE (VS Code, CLion, Visual Studio, etc.)

**Recommended:**
- CMake 3.10+
- clang-format (for code formatting)
- Markdown linter (for documentation)

### Setting Up Your Environment

1. **Fork the repository**
   ```bash
   # Via GitHub UI - click "Fork"
   ```

2. **Clone your fork**
   ```bash
   git clone https://github.com/YOUR_USERNAME/CPP.git
   cd CPP
   ```

3. **Add upstream remote**
   ```bash
   git remote add upstream https://github.com/abhinav1602/CPP.git
   ```

4. **Create a branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

### Keeping Your Fork Updated

```bash
git fetch upstream
git checkout main
git merge upstream/main
git push origin main
```

---

## 💻 Coding Standards

### C++ Code Style

#### Naming Conventions

```cpp
// Classes: PascalCase
class MyClass { };

// Functions: camelCase
void calculateSum() { }

// Variables: camelCase
int totalCount = 0;

// Constants: UPPER_SNAKE_CASE
const int MAX_SIZE = 100;

// Files: PascalCaseExample.cpp
// VectorExample.cpp, UniquePtrExample.cpp
```

#### Code Organization

```cpp
/**
 * @file ExampleName.cpp
 * @brief Brief description
 * @author Your Name
 * @date YYYY-MM-DD
 *
 * Detailed description of concepts covered
 */

#include <iostream>
#include <vector>
// ... other includes

/**
 * @brief Example 1: Description
 * @complexity Time: O(?), Space: O(?)
 */
void example1() {
    // Clear comments explaining each step
    // Actual implementation
}

// More example functions...

int main() {
    std::cout << "=== Topic Examples ===" << std::endl;
    example1();
    // ... more examples
    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 ExampleName.cpp -o ExampleName
 * 
 * Key Takeaways:
 * 1. Point 1
 * 2. Point 2
 * ...
 */
```

#### Best Practices

1. **Modern C++ Features**
   ```cpp
   // ✅ Use auto for type deduction
   auto it = container.begin();
   
   // ✅ Use range-based for loops
   for (const auto& item : container) { }
   
   // ✅ Use nullptr instead of NULL
   int* ptr = nullptr;
   
   // ✅ Use smart pointers
   auto ptr = std::make_unique<int>(10);
   ```

2. **Const Correctness**
   ```cpp
   // ✅ Mark non-modifying functions const
   int getValue() const { return value; }
   
   // ✅ Use const references for parameters
   void process(const std::string& str) { }
   ```

3. **RAII Principle**
   ```cpp
   // ✅ Acquire resources in constructor, release in destructor
   class ResourceGuard {
       Resource* res;
   public:
       ResourceGuard() : res(acquire()) {}
       ~ResourceGuard() { release(res); }
   };
   ```

4. **Comments**
   ```cpp
   // ✅ Comment-to-code ratio: ~1:2
   // ✅ Explain WHY, not just WHAT
   // ✅ Use Doxygen-style comments for functions
   ```

### Compilation Requirements

All code must compile cleanly with:
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -O2 file.cpp -o output
clang++ -std=c++17 -Wall -Wextra -Wpedantic -O2 file.cpp -o output
```

### Testing

Before submitting:
- ✅ Code compiles without warnings
- ✅ Code runs and produces correct output
- ✅ No memory leaks (use valgrind or sanitizers if possible)
- ✅ Code follows project style guide

---

## 📚 Documentation Standards

### Markdown Formatting

#### Headers
```markdown
# H1 - Module Title
## H2 - Major Section
### H3 - Subsection
#### H4 - Minor point
```

#### Code Blocks
```markdown
Use triple backticks with language specifier:
```cpp
std::vector<int> v = {1, 2, 3};
```
````

#### Lists
```markdown
- Unordered list item
  - Nested item

1. Ordered list item
2. Second item
```

#### Tables
```markdown
| Column 1 | Column 2 |
|----------|----------|
| Data 1   | Data 2   |
```

#### Links
```markdown
[Link Text](URL)
[Relative Link](../path/to/file.md)
```

### Documentation Structure

#### README Files

Every README.md should include:
1. **Overview** - Brief description
2. **Key Concepts** - Core principles
3. **Syntax Section** - Basic syntax with examples
4. **Operations** - Common operations table
5. **Code Examples** - 3-5 inline examples
6. **Complexity** - Performance analysis
7. **Best Practices** - Modern C++ recommendations
8. **Common Pitfalls** - What to avoid
9. **Comparison** - Compare with alternatives
10. **Further Reading** - External resources

#### Example Template
```markdown
# Topic Name

## Overview
[Brief description]

## Key Concepts
- Concept 1
- Concept 2

## Syntax
```cpp
// Code example
```

## Common Operations
| Operation | Complexity | Description |
|-----------|-----------|-------------|
| op1 | O(?) | Description |

## Examples
[Examples here]

## Best Practices
1. Practice 1
2. Practice 2

## Common Pitfalls
1. Pitfall 1
2. Pitfall 2

---
**Next:** [Next Topic](link)
```

---

## 📤 Submission Guidelines

### Pull Request Process

1. **Update your branch**
   ```bash
   git fetch upstream
   git rebase upstream/main
   ```

2. **Commit your changes**
   ```bash
   git add .
   git commit -m "Add: Brief description of changes"
   ```

   **Commit Message Format:**
   ```
   Type: Brief description (50 chars or less)

   More detailed explanation if necessary. Wrap at 72 characters.
   Explain what and why, not how.

   Fixes #issue_number
   ```

   **Types:**
   - `Add:` New feature or file
   - `Fix:` Bug fix
   - `Update:` Update existing content
   - `Docs:` Documentation only
   - `Style:` Formatting changes
   - `Refactor:` Code restructuring
   - `Test:` Adding tests

3. **Push to your fork**
   ```bash
   git push origin feature/your-feature-name
   ```

4. **Create Pull Request**
   - Go to GitHub and create a PR
   - Fill out the PR template
   - Link related issues

### Pull Request Checklist

Before submitting, ensure:

- [ ] Code compiles without warnings on g++ and clang++
- [ ] All new code has appropriate comments
- [ ] Documentation is updated (README, etc.)
- [ ] Examples run correctly
- [ ] Follows project coding style
- [ ] No merge conflicts with main branch
- [ ] Commit messages are clear and descriptive

---

## 🔍 Review Process

### What to Expect

1. **Initial Review** - Within 7 days
2. **Feedback** - Constructive comments on improvements
3. **Iteration** - Address feedback and update PR
4. **Approval** - Once all requirements met
5. **Merge** - Into main branch

### Review Criteria

Reviewers will check for:
- **Correctness:** Code works as intended
- **Quality:** Follows standards and best practices
- **Documentation:** Clear and comprehensive
- **Testing:** Compiles and runs correctly
- **Style:** Consistent with project style

---

## 💡 Tips for Contributors

### For First-Time Contributors

- Start with small contributions (typos, documentation improvements)
- Read existing code to understand the style
- Ask questions if anything is unclear
- Don't be afraid to make mistakes - we're here to help!

### For Code Contributors

- Keep PRs focused on a single feature/fix
- Write meaningful commit messages
- Test thoroughly before submitting
- Respond promptly to review feedback
- Be patient during the review process

### For Documentation Contributors

- Check for spelling and grammar
- Ensure code examples compile
- Keep explanations clear and concise
- Use consistent formatting
- Add visual elements (tables, lists) where helpful

---

## 🎖️ Recognition

Contributors will be recognized in:
- Project documentation
- Release notes
- GitHub contributors page

---

## 📞 Getting Help

### Questions?

- **GitHub Discussions:** For general questions
- **GitHub Issues:** For bug reports and feature requests
- **Email:** For private matters (see profile)

### Resources

- [C++ Reference](https://en.cppreference.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [GitHub Docs](https://docs.github.com/)
- [Markdown Guide](https://www.markdownguide.org/)

---

## 📜 License

By contributing, you agree that your contributions will be licensed under the CC BY-NC-SA 4.0 license.

---

## 🙏 Thank You!

Your contributions help make this resource better for everyone. Whether you're fixing a typo or adding a new module, every contribution is valued!

---

**Questions?** Open an issue or start a discussion!

**Ready to contribute?** Fork the repo and start coding!

---

*Last Updated: November 14, 2025*
