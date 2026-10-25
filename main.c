/*
 * This program converts an infix expression into a postfix expression.
 * It supports five operators: +, -, *, / and ^.
 * Operands are limited to single alphabetic characters.
 * Parentheses are supported to control the order of operations.
 * Multi-character and fractional operands are not supported.
 */
#include <stdio.h>
#define MAX 20

char stk[MAX];
int top = -1;
//--------------------------------------------------------------------------------------//
// Checks whether the stack is empty
int isEmpty()
{
    return top == -1;
}
// Checks whether the stack is full
int isFull()
{
    return top == MAX - 1;
}
// Returns the top element without removing it-->peek() operation
char peek()
{
    return stk[top];
}
// Removes and returns the top element--> pop() operation
char pop()
{
    if (isEmpty())
        return -1;
    char ch = stk[top];
    top--;
    return ch;
}
// Adds an operator or parenthesis to the stack--> push() operation
void push(char oper)
{
    if (isFull())
        printf("Stack Full");
    else
    {
        top++;
        stk[top] = oper;
    }
}

// Checks whether the character is a letter
int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}
//-------------------------------------------------------------------------------------------//
// Returns the precedence of each operator
// ^ -> 3 , * ,/ -> 2 , +,- -> 1 --->percedence
int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}
//----------------------------------------------------------------------------------------//
// Converts an infix expression into postfix form
void convertInfixToPostfix(char *expression)
{
    int i, j = 0;
    char postfix[MAX];

    // Reads the expression from left to right
    for (i = 0; expression[i]; i++)
    {
        // Adds operands directly to the output
        if (checkIfOperand(expression[i]))
            postfix[j++] = expression[i];

        // Pushes the opening parenthesis onto the stack
        else if (expression[i] == '(')
            push(expression[i]);

        // Pops operators until the matching '(' is found
        else if (expression[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();

            pop();  // Removes the opening parenthesis
        }
        else
        {
            // Pops operators that have higher or equal precedence
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))
                postfix[j++] = pop();

            push(expression[i]);
        }
    }

    // Adds any remaining operators to the output
    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';  // Marks the end of the postfix string

    printf("Postfix Expression: %s\n", postfix);
}
//----------------------------------------------------------------------------------------//
//main
int main()
{
    char expression[MAX];
    printf("Enter the Expression: ");
    scanf("%19s", expression);
  
    convertInfixToPostfix(expression);
  
  return 0;
}
