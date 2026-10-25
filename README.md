# Infix to Postfix Conversion Using Stack in C

## 1. Overview

This program converts an infix expression into a postfix expression using a stack data structure. It uses operator precedence and parentheses to arrange operators in the correct order.

## 2. Objective

- To understand how a stack works in C.
- To learn the difference between infix and postfix expressions.
- To implement basic stack operations.
- To convert infix expressions into postfix form using operator precedence.

## 3. Basic Concepts

### Infix Expression

In an infix expression, the operator is placed between the operands.

Example: A+B

### Postfix Expression

In a postfix expression, the operator is placed after the operands.

Example: `AB+`

### Stack

A stack is a linear data structure that follows the **LIFO (Last In, First Out)** principle. The last element added to the stack is the first one removed.

In this program, the stack stores operators and parentheses during conversion.

#### Stack Operations

- **Push:** Adds an element to the top of the stack.
- **Pop:** Removes and returns the top element.
- **Peek:** Returns the top element without removing it.
- **isEmpty():** Checks whether the stack is empty.
- **isFull():** Checks whether the stack has reached its maximum capacity.

## 4. Precedence Levels

Operator precedence determines which operators should be processed first.

| Operator | Operation | Precedence |
|---|---|---|
| `^` | Exponentiation | 3 |
| `*` | Multiplication | 2 |
| `/` | Division | 2 |
| `+` | Addition | 1 |
| `-` | Subtraction | 1 |
| `()` | Parentheses | Control the order of operations |

Operators with higher precedence are generally processed before operators with lower precedence. Parentheses control the order of operations.

## 5. Algorithm

1. Start with an empty stack.
2. Read the infix expression from left to right.
3. If the character is an operand, add it directly to the postfix expression.
4. If the character is an opening parenthesis `(`, push it onto the stack.
5. If the character is a closing parenthesis `)`, pop operators into the postfix expression until the matching opening parenthesis is found. Remove the opening parenthesis.
6. If the character is an operator, pop operators with higher or equal precedence from the stack, then push the current operator.
7. After reading the complete expression, pop all remaining operators into the postfix expression.
8. Add the string terminator `\0` and display the postfix expression.
9. Stop.

## 6. Block Diagram

```text
       +------------------------+
       |      Start Program     |
       +------------------------+
                  |
                  v
       +------------------------+
       | Enter Infix Expression |
       +------------------------+
                  |
                  v
       +------------------------+
       | Initialize Empty Stack |
       +------------------------+
                  |
                  v
       +------------------------+
       | Read Next Character    |
       +------------------------+
                  |
                  v
       +------------------------+
       | Check Character Type   |
       +------------------------+
                  |
          +-------+-------+
          |       |       |
          v       v       v
       Operand Operator Parenthesis
          |       |       |
          v       v       v
       Add to  Check      Handle
       Postfix Precedence Parentheses
          |       |       |
          +-------+-------+
                  |
                  v
       +------------------------+
       | More Characters Left?  |
       +------------------------+
             |           |
            Yes          No
             |           |
             v           v
       Read Next     Pop Remaining
       Character     Operators
                         |
                         v
                +-------------------+
                | Display Postfix   |
                | Expression        |
                +-------------------+
                         |
                         v
                +-------------------+
                |       Stop        |
                +-------------------+
```

## 7. Step-by-Step Example

**Infix expression:**

`(A+B)*(C-D)^E`

**Expected postfix expression:**

`AB+CD-E^*`

| Step | Symbol | Action | Postfix | Stack |
|---:|:---:|---|---|---|
| 1 | `(` | Push opening parenthesis | — | `(` |
| 2 | `A` | Add operand | `A` | `(` |
| 3 | `+` | Push operator | `A` | `( +` |
| 4 | `B` | Add operand | `AB` | `( +` |
| 5 | `)` | Pop `+` and remove `(` | `AB+` | Empty |
| 6 | `*` | Push operator | `AB+` | `*` |
| 7 | `(` | Push opening parenthesis | `AB+` | `* (` |
| 8 | `C` | Add operand | `AB+C` | `* (` |
| 9 | `-` | Push operator | `AB+C` | `* ( -` |
| 10 | `D` | Add operand | `AB+CD` | `* ( -` |
| 11 | `)` | Pop `-` and remove `(` | `AB+CD-` | `*` |
| 12 | `^` | Push operator | `AB+CD-` | `* ^` |
| 13 | `E` | Add operand | `AB+CD-E` | `* ^` |
| 14 | End | Pop remaining operators | `AB+CD-E^*` | Empty |

**Output:**

```text
Postfix Expression: AB+CD-E^*
```

## 8. Advantages

- Helps understand stack operations and their practical use.
- Removes the need for parentheses in the resulting postfix expression.
- Uses operator precedence to arrange operators.
- Provides a practical introduction to expression conversion in C.

## 9. Disadvantages

- Supports only single alphabetic operands.
- Does not support multi-character variable names or fractional numbers.
- Assumes that the input expression is valid.
- Does not correctly handle right-to-left associativity of the exponentiation operator `^` in every case.

## 10. Technologies Used

- **Programming Language:** C
- **Data Structure:** Stack
- **Concepts:** Operator precedence, expression conversion, character processing

