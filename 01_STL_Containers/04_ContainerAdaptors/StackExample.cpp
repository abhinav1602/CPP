/**
 * @file StackExample.cpp
 * @brief Comprehensive examples of std::stack usage
 * @author Learning Module
 * @date 2025-11-14
 *
 * This file demonstrates:
 * - LIFO (Last-In-First-Out) operations
 * - Stack operations: push, pop, top
 * - Use cases: expression evaluation, undo, DFS
 * - Underlying container selection
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cctype>

void example1_BasicOperations();
void example2_LIFODemonstration();
void example3_ExpressionEvaluation();
void example4_UndoSystem();
void example5_UnderlyingContainer();
void example6_BalancedParentheses();

/**
 * @brief Example 1: Basic Stack Operations
 * @complexity Time: O(1) for all operations
 */
void example1_BasicOperations() {
    std::cout << "--- Basic Stack Operations ---" << std::endl;

    std::stack<int> stk;

    std::cout << "Empty? " << (stk.empty() ? "yes" : "no") << std::endl;

    // Push elements
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.emplace(40);  // Construct in place

    std::cout << "After pushing 10, 20, 30, 40:" << std::endl;
    std::cout << "Size: " << stk.size() << std::endl;
    std::cout << "Top: " << stk.top() << std::endl;

    // Pop element
    stk.pop();
    std::cout << "After pop():" << std::endl;
    std::cout << "Size: " << stk.size() << std::endl;
    std::cout << "Top: " << stk.top() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 2: LIFO Demonstration
 * @complexity Time: O(n)
 */
void example2_LIFODemonstration() {
    std::cout << "--- LIFO Demonstration ---" << std::endl;

    std::stack<std::string> books;

    // Stack books
    books.push("C++ Primer");
    books.push("Effective C++");
    books.push("Modern C++");

    std::cout << "Books stacked (bottom to top):" << std::endl;
    std::cout << "1. C++ Primer" << std::endl;
    std::cout << "2. Effective C++" << std::endl;
    std::cout << "3. Modern C++" << std::endl;

    std::cout << "\nRemoving books (Last In, First Out):" << std::endl;
    while (!books.empty()) {
        std::cout << "Taking: " << books.top() << std::endl;
        books.pop();
    }

    std::cout << std::endl;
}

/**
 * @brief Example 3: Expression Evaluation (Postfix)
 * @complexity Time: O(n) where n is expression length
 */
void example3_ExpressionEvaluation() {
    std::cout << "--- Expression Evaluation (Postfix) ---" << std::endl;

    // Postfix expression: "5 3 + 2 *" = (5 + 3) * 2 = 16
    std::string expr = "5 3 + 2 *";
    std::stack<int> stk;

    std::cout << "Postfix expression: " << expr << std::endl;
    std::cout << "Evaluation steps:" << std::endl;

    for (char c : expr) {
        if (std::isdigit(c)) {
            stk.push(c - '0');
            std::cout << "  Push " << (c - '0') << std::endl;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (stk.size() >= 2) {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int result;

                switch (c) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': result = a / b; break;
                    default: result = 0;
                }

                stk.push(result);
                std::cout << "  " << a << " " << c << " " << b << " = " << result << std::endl;
            }
        }
    }

    if (!stk.empty()) {
        std::cout << "Final result: " << stk.top() << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Example 4: Undo System Simulation
 * @complexity Time: O(1) per operation
 */
void example4_UndoSystem() {
    std::cout << "--- Undo System Simulation ---" << std::endl;

    std::stack<std::string> actions;
    std::string currentState = "Empty Document";

    auto performAction = [&](const std::string& action) {
        actions.push(currentState);
        currentState = action;
        std::cout << "Action: " << action << std::endl;
    };

    auto undo = [&]() {
        if (!actions.empty()) {
            std::cout << "Undo: " << currentState << " -> ";
            currentState = actions.top();
            actions.pop();
            std::cout << currentState << std::endl;
        } else {
            std::cout << "Nothing to undo!" << std::endl;
        }
    };

    std::cout << "Initial state: " << currentState << std::endl;

    performAction("Added 'Hello'");
    performAction("Added 'World'");
    performAction("Added '!'");

    std::cout << "\nCurrent state: " << currentState << std::endl;
    std::cout << "Undo history size: " << actions.size() << std::endl;

    std::cout << "\nPerforming undos:" << std::endl;
    undo();
    undo();

    std::cout << "\nCurrent state: " << currentState << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 5: Underlying Container Selection
 * @complexity Time: O(1) for operations
 */
void example5_UnderlyingContainer() {
    std::cout << "--- Underlying Container Selection ---" << std::endl;

    // Default: deque
    std::stack<int> stk1;

    // Using vector
    std::stack<int, std::vector<int>> stk2;

    // Using list
    std::stack<int, std::list<int>> stk3;

    std::cout << "Stack can use different underlying containers:" << std::endl;
    std::cout << "1. std::stack<int> - uses deque (default)" << std::endl;
    std::cout << "2. std::stack<int, std::vector<int>> - uses vector" << std::endl;
    std::cout << "3. std::stack<int, std::list<int>> - uses list" << std::endl;

    std::cout << "\nRecommendation: Use default (deque) unless specific needs" << std::endl;

    // All work the same way
    for (int i = 1; i <= 3; ++i) {
        stk1.push(i);
        stk2.push(i);
        stk3.push(i);
    }

    std::cout << "\nAll stacks top element: " << stk1.top() << ", "
              << stk2.top() << ", " << stk3.top() << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Example 6: Balanced Parentheses Checker
 * @complexity Time: O(n) where n is string length
 */
void example6_BalancedParentheses() {
    std::cout << "--- Balanced Parentheses Checker ---" << std::endl;

    auto isBalanced = [](const std::string& expr) -> bool {
        std::stack<char> stk;

        for (char c : expr) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stk.empty()) return false;

                char top = stk.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        return stk.empty();
    };

    std::vector<std::string> testCases = {
        "((()))",
        "({[]})",
        "(()",
        "({[}])",
        "{[()]}",
        "((])"
    };

    for (const auto& expr : testCases) {
        std::cout << expr << " : "
                  << (isBalanced(expr) ? "Balanced ✓" : "Not Balanced ✗")
                  << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief Main function
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "    STL Stack Comprehensive Examples    " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    example1_BasicOperations();
    example2_LIFODemonstration();
    example3_ExpressionEvaluation();
    example4_UndoSystem();
    example5_UnderlyingContainer();
    example6_BalancedParentheses();

    std::cout << "========================================" << std::endl;
    std::cout << "  All stack examples completed!         " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}

/*
 * Compilation:
 *   g++ -std=c++17 -Wall -Wextra -O2 StackExample.cpp -o StackExample
 *   clang++ -std=c++17 -Wall -Wextra -O2 StackExample.cpp -o StackExample
 *
 * Run:
 *   ./StackExample       (Linux/Mac)
 *   .\StackExample.exe   (Windows)
 *
 * Key Takeaways:
 * 1. Stack provides LIFO (Last-In-First-Out) access
 * 2. Only top element is accessible
 * 3. No iteration support
 * 4. All operations are O(1)
 * 5. Perfect for undo, recursion, expression evaluation
 * 6. Always check empty() before top() or pop()
 */

