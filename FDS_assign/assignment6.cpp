#include<bits/stdc++.h>
using namespace std;

int linear(int n,int ar[],int key)
{
    int i=0;
    while(i<=n-1)
    {
        if(ar[i]==key)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int sentinel(int n,int ar[],int key)
{
    int i=0,last=0;
    last=ar[n-1];
    ar[n-1]=key;
    while(ar[i]!=key)
    {
        i++;
    }

    if(i<n-1 || last==key)
    {
        return i;
    }
    else
    {
        return -1;
    }

}

int main()
{
    int n;
    cout<<"Enter number of students who ateended";
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    int key=0;
    cout<<"Enter the roll number to search";
    cin>>key;

    int i=1,choice=0;
    while(i>0)
    {
        cout<<"1. Liner Search \n 2. Binary Search";
        cin>>choice;

        if(choice==1)
        {
            int index=sentinel(n,ar,key);
            if(index>0)
            {
                cout<<"He was present ";
            }else
            {
                cout<<"He was not present ";
            }
        }
        
        else if(choice==2)
        {
            int index=sentinel(n,ar,key);
            if(index>0)
            {
                cout<<"He was present ";
            }else
            {
                cout<<"He was not present ";
            }
        
        }

        
        else
            break;
    }

}