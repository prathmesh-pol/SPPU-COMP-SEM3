/*
	7229 Khushi Assignment 12
*/

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
        {
            st.push(s[i]);
        }
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

int main()
{
    int ch;
    string s;
    while (1)
    {
        cout << "\n\n----------------------MENU--------------------\n\n";
        cout << "1. Enter parenthesis\n2. Print Parenthesis\n3. check for Balance Parenthesis\n4. Exit \n";
        cout<<"\nEnter your choice : ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "\nEnter parenthesis to be checked : ";
            cin >> s;
        }
        else if (ch == 2)
        {
            cout << "\nEnter String : " << s;
        }
        else if (ch == 3)
        {
            if (balanced_parenthesis(s))
            {
                cout << "\nBalanced";
            }
            else
            {
                cout << "\nNot Balanced";
            }
        }
        else if (ch == 4)
        {
            cout<<"\nThank u sir . Do visit Again !!!\n";
            exit(0);
        }
        else
        {
            cout << "\nInvalid Choice !!!\n";
        }
    }
}