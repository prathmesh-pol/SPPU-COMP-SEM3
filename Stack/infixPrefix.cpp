#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nL endl
#define vll vector<ll>

ll prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    stack<char> st;
    string str;
    reverse(s.begin(), s.end());
    for (auto &i : s)
    {
        if (i == '(')
            i = ')';
        else if(i==')')
            i = '(';
    }
    for (auto &i : s)
    {
        if (i == '(')
            st.push(i);
        else if (i == ')')
        {
            while (st.top() != '(')
            {
                str += st.top();
                st.pop();
            }
            st.pop();
        }
        else if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
            str += i;
        else
        {
            while (!st.empty() && prec(i) <= prec(st.top()))
            {
                str += st.top();
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            str += st.top();
            st.pop();
        }
    }
    reverse(str.begin(), str.end());
    cout << str << nL;
}

signed main()
{
    solve();
    return 0;
}