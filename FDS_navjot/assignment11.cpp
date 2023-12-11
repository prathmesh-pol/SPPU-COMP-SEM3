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
string infixToPostfix(string infix){
    stack<int> s;
    string postfix;

    for(char ch : infix){
        if(isalnum(ch)){
            postfix+=ch;
        }else if(ch == '('){
            s.push(ch);
        }else if(ch == ')'){
            
            while(!s.empty()&&s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }else if(isOperator(ch)){
            while(!s.empty() && getPrecedence(ch) <= getPrecedence(s.top())){
                postfix+=s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }

    return postfix;

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
    }
    else
    {
        cout << "Expression is not well-parenthesized." << endl;
    }

    return 0;
}
