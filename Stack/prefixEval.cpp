#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nL endl
#define vll vector<ll>

void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    stack<ll> st;
    for (ll i = n - 1; i >= 0; i--)
    {
        ll a = s[i] - '0';
        if (a >= 0 && a <= 9)
            st.push(a);
        else
        {
            ll op1 = st.top();
            st.pop();
            ll op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    cout << st.top() << nL;
}

signed main()
{
    solve();
    return 0;
}