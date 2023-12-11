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
    for (auto &i : s)
    {
        if (i == '(')
            st.push(i);
        else if (i == ')')
        {
            while (st.top() != '(')
            {
                cout << st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
            cout << i;
        else
        {
            while (!st.empty() && prec(i) <= prec(st.top()))
            {
                cout << st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}

signed main()
{
    solve();
    return 0;
}