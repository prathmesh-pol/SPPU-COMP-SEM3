#include <iostream>
#include <stack>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0; // Default precedence for non-operators
}

// Function to convert infix expression to postfix
string infixToPostfix(const string &infix)
{
    stack<char> s;
    string postfix;

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch; // Operand, append to postfix
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the '('
        }
        else if (isOperator(ch))
        {
            while (!s.empty() && getPrecedence(ch) <= getPrecedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
double evaluatePostfix(const string &postfix)
{
    stack<double> s;

    for (char ch : postfix)
    {
        if (isalnum(ch))
        {
            s.push(ch - '0'); // Convert character to integer
        }
        else if (isOperator(ch))
        {
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();

            switch (ch)
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            }
        }
    }

    return s.top();
}

// Function to check whether the expression is well-parenthesized
bool isWellParenthesized(const string &expression)
{
    stack<char> s;

    for (char ch : expression)
    {
        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                return false;
            }
            s.pop();
        }
    }

    return s.empty(); // Stack should be empty if well-parenthesized
}

int main()
{
    // Test infix to postfix conversion and evaluation
    string infixExpression;
    cout << "Enter infix expression: ";
    cin >> infixExpression;

    // Check for well-parenthesized expression
    if (isWellParenthesized(infixExpression))
    {
        string postfixExpression = infixToPostfix(infixExpression);
        cout << "Postfix expression: " << postfixExpression << endl;

        double result = evaluatePostfix(postfixExpression);
        cout << "Result of the expression: " << result << endl;
    }
    else
    {
        cout << "Expression is not well-parenthesized." << endl;
    }

    return 0;
}
