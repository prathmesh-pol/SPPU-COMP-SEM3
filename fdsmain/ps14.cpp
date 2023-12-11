#include <bits/stdc++.h>
using namespace std;
 
int  precedence(char c)
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
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');
 
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
 
        else {
            while (!st.empty()
                   &&  precedence(s[i]) <=  precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    cout << result << endl;
}
void evalulate(string exp){

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[1]=='+')
        {
           float ans = ((exp[0]-48)+(exp[2]-48));
           cout<<ans<<endl;
           break;
        }
        if (exp[1]=='-')
        {
                       float ans = ((exp[0]-48)-(exp[2]-48));

           cout<<ans<<endl;
           break;
        }
        if (exp[1]=='*')
        {
                       float ans = ((exp[0]-48)*(exp[2]-48));

           cout<<ans<<endl;
           break;
        }
        if (exp[1]=='/')
        {
                       float ans = ((exp[0]-48)/(exp[2]-48));

           cout<<ans<<endl;
           break;
        }
        
    }
    

}
 
int main()
{
    string exp ;
    cout<<"enter the infix expression : ";
    cin>>exp;
    cout<<"postfix expression is : ";
    // Function call
    infixToPostfix(exp);
    cout<<"The result of evaluation : ";
    evalulate(exp);
    return 0;
}