# Infix to Postfix Expression Evaluator

This project evaluates arithmetic expressions by converting infix notation to postfix notation and then computing the result. It is implemented in C using a stack data structure with arrays and currently handles only single-digit numbers. Future improvements will include support for multi-digit numbers.

## Features

- **Infix to Postfix Conversion:** Converts infix expressions (e.g., `3 + 5 * (2 - 8)`) to postfix notation (e.g., `3 5 2 8 - * +`).
- **Postfix Evaluation:** Computes the result of postfix expressions using a stack-based approach.

## How It Works

1. **Infix to Postfix Conversion:**
   - Uses a stack to manage operators and parentheses.
   - Outputs the postfix expression by applying operator precedence and parentheses rules.

2. **Postfix Evaluation:**
   - Processes the postfix expression using a stack.
   - Computes the result by applying operators to operands.

## Limitations

- **Single-Digit Numbers Only:** The current implementation supports only single-digit numbers. Multi-digit numbers and more complex expressions will be supported in future updates.

## Future Improvements

- **Multi-Digit Numbers:** Support for multi-digit numbers and decimal values.
- **Error Handling:** Improved handling of invalid expressions and errors.
- **Extended Operators:** Support for additional mathematical functions and operators.

## Implementation Details

- **Language:** C
- **Data Structure:** Stack (implemented using arrays)

## Example 1

**Input:** 3 + 5 * (2 - 8)

**Output:** 
Postfix expression: 3 5 2 8 - * + 

Answer: -21

## Example 2

**Input:** 7 - 3 * 2

**Output:**
Postfix expression: 7 3 2 * - 

Answer: 1
