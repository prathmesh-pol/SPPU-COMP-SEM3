#include<iostream>
#include<queue>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    
    public:
    Queue(int s){
        size=s;
        arr=new int[size];
        front=0;
        rear=0;
    }

    // enqueue
    void enqueue(int x){
        if(rear == size){
            cout<<"Queue is full"<<endl;
            return;
        }

        arr[rear]=x;
        rear++;
    }

    int dequeue(){
        if(rear == front){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int ans=arr[front];
        arr[front] = -1;
        front++;
        if(front == rear){
            front=rear=0;
        }
        return ans;
    }

    int top(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            int val=arr[front];
            return val;
        }
    }

    bool isempty(){
        if(rear==front) return true;
        else return false;
    }

    void display(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return;
        }

        for(int i=front;i<rear;i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }
};

int main(){
    Queue obj1(5);
    obj1.enqueue(10);
    obj1.enqueue(11);
    obj1.enqueue(12);
    int ans=obj1.top();
    if(ans) cout<<ans<<endl;
    obj1.display();
    obj1.dequeue();
    obj1.dequeue();
    obj1.display();
    

}