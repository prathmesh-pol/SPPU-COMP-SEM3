/*
	7229 Khushi Assignment 14
*/

#include <iostream>

#define MAX 50

using namespace std;

class Stack{
    public:
    char arr[MAX];
    int top;

    Stack(){
        top = -1;
    }

    void push(int val){
        if (top == MAX -1){
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = val;
    }

    bool isempty(){
        return top == -1;
    }

    char pop(){
        if (top == -1){
            cout << "Stack UNderflow\n";
            return -1;
        }
        char temp = arr[top];
        top--;
        return temp; 
    }
    char Top(){
        if(top==-1){
            cout<<"\nThe stack is empty....!!! ";
            return -1;
        }
        return arr[top];
    }

    char high(){
        if (top == -1){
            return '(';
        }
        return arr[top];
    }
};

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }

}

string infix_to_postfix(string s){
    Stack st;
    string ans;
    for(int i =0 ;i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z')  || (s[i]>='A' && s[i]<='Z')) {
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.isempty() && st.Top()!='('){
                ans+=st.Top(); st.pop();
            }
            if(!st.isempty()){
                st.pop();
            }
        }
        else{
            while(!st.isempty() && prec(st.Top())>=prec(s[i])){
                ans += st.Top(); st.pop();
            }
            st.push(s[i]);
        }

    }
    while(!st.isempty()){
        ans+=st.Top(); st.pop();
    }
    return ans;
}

int main(){
    char ch;
    string st,ans;
    while (1){
        cout << "\n\n----------------------MENU--------------------\n\n";
        cout << "1. Enter Infix expression \n2. Print Expression \n3. Print Postfix Expression  \n4. Exit\n";
        cout<<"\nEnter your choice : ";
        cin >> ch;

        if(ch=='1'){
            cout<<"\nEnter Infix Expression : ";
            cin.ignore();
            getline(cin, st);
        }

        else if (ch=='2'){
        
            cout<< "\nEntered Expression : " <<st;
        }

        else if(ch=='3'){
            ans = infix_to_postfix(st);
            cout<<"\nPostfix Expression : "<<ans;
        }
        else if(ch=='4'){
            cout<<"\nBye sir. Do visit Again !!! ";
            exit(0);
        }
        else{
            cout<<"\nInvalid Choice !!! ";
        }
        
    }
}