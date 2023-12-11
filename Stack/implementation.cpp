#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nL endl
#define vll vector<ll>

class stack
{
public:
    ll top;
    ll *arr;
    ll size;
    stack(ll size){
        this->size=size;
        arr=new ll[size];
        top=-1;
    }
    void push(ll val){
        if(size-top>1){
            top++;
            arr[top]=val;
        }
        else cout<<"Stack OverFlow"<<nL;
    }
    void pop(){
        if(top>=0) top--;
        else cout<<"Stack UnderFlow"<<nL;
    }
    ll peek(){
        return arr[top];
    }
    bool isEmpty(){
        if(top<0) return false;
        else return true;
    }
};

signed main()
{
    vll v = {1, 2, 3, 4, 5, 6};
    return 0;
}