/*
	7229 Khushi Assignment 13
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 50

using namespace std;

class Stack{
    public:
    char arr[MAX];
    int top;

    Stack(){
        top = -1;
    }

    char Top(){
        if (top == -1)
        {
            cout << "\nThe stack is empty....!!! ";
            return -1;
        }
        return arr[top];
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
};

template<typename T>
void print_stack(T st){
    while(!st.isempty()){
        cout<<st.Top();
        char k = st.pop();
    }cout<<endl;
}

int main(){
    char ch;
    Stack str1, str2, str3,rev;
    string exp;
    while (1){
        cout << "\n\n----------------------MENU--------------------\n\n";
        cout << "1. Enter String\n2. Print String\n3. Print Reverse String \n4. Check for Palingdrome \n5. Exit\n";
        cout<<"\nEnter your choice : ";
        cin >> ch;

        if(ch=='1'){
        cout << "\nEnter String to Check: ";cin >> exp;
        while(!str1.isempty()){
            str1.pop();
        }
        while(!str2.isempty()){
            str2.pop();
        }
        while(!str3.isempty()){
            str3.pop();
        }
        for (auto i: exp){
           str1.push(i);
           str2.push(i);
           str3.push(i);
        }
        while(!rev.isempty()){
            rev.pop();
        }
        while (!str2.isempty()){
            rev.push(str2.pop());
        }
        }
        else if(ch == '2'){
            cout<< "Entered String : "<<exp;
        }
        else if(ch=='3'){
            cout<<"Reverse String :";
            print_stack(str3);
        }
        else if(ch=='4'){

            bool flag=1;
            while (!str1.isempty()){
                if (str1.pop() != rev.pop()){
                    flag = 0;
                }
            }
            if (flag == 1){
                cout << "\nGiven string is Palindrome.\n";
            } else {
                cout <<"\nGiven string is not palindrome\n";
            }
        }

        else if(ch=='5'){
            exit(0);
        }

        else{
            cout<<"Invalid Choice !!!";
        }

    }
    return 0;
}