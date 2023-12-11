#include <bits/stdc++.h>
using namespace std;
#define n 20

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "\nStack Overflow";
            return;
        }
        top++;
        arr[top] = x;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "\nThe stack is empty....!!! ";
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "\nThe stack is empty !! No element to pop";
            return;
        }
        top--;
    }
};

bool balanced_parenthesis(string s)
{
    Stack st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' or s[i] == '{')
            st.push(s[i]);

        else
        {
            if (s[i] == ')')
            {
                if (!st.empty() && st.Top() == '(')
                    st.pop();

                else
                    return false;
            }

            else if (!st.empty() && s[i] == '}')
            {
                if (st.Top() == '{')
                    st.pop();

                else
                    return false;
            }

            if (!st.empty() && s[i] == ']')
            {
                if (st.Top() == '[')
                    st.pop();

                else
                    return false;
            }
        }
    }
    return st.empty();
}
int precedence(char c)
{
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{
    stack<char> st;

    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main()
{
    int ch;
    string s;
    while (1)
    {
        cout << "\n\n----------------------MENU--------------------\n\n";
        cout << "1. Enter parenthesis\n2. check for Balance Parenthesis\n3.infix to Postfix\n4. Exit \n";
        cout << "\nEnter your choice : ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "\nEnter parenthesis to be checked : ";
            cin >> s;
        }

        else if (ch == 2)
        {
            if (balanced_parenthesis(s))
            {
                cout << "Balanced" << endl;
            }
            else
            {
                cout << "Not Balanced" << endl;
            }
        }
        else if (ch == 3)
        {
            string exp;
            cout << "enter the infix expression : ";
            cin >> exp;
            cout << "postfix expression is : ";
            // Function call
            infixToPostfix(exp);
        }
        else if (ch == 4)
        {
            exit(0);
        }

        else
        {
            cout << "Invalid Choice !!!" << endl;
        }
    }

    return 0;
}