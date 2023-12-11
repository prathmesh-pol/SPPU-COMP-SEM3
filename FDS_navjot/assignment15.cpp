/*
DO YOU KNOW : Double ended queue is referred as DEQUEUE
*/
#include<iostream>
using namespace std;

class dequeue{
    public:
    int * arr;
    int size;
    int front;
    int rear;

    public:
    dequeue(int n){
        size = n;
        arr= new int[size];
        front=-1;
        rear=-1;
    }

    void pushfront(int data){
        if(isfull()){
            cout<<"Queue is full"<<endl;
            return;
        }else if(isempty()){
            front=rear=0;
        }else if(front == 0 && rear != size -1){
            front=size-1;
        }else{
            front--;
        }

        arr[front] = data;
    }

    void pushrear(int data){
        if(isfull()){
            cout<<"Queue is full"<<endl;
            return;
        }else if(isempty()){
            front=rear=0;
        }else if(front!=0 && rear==size-1){
            rear=0;
        }else{
            rear++;
        }

        arr[rear] = data;
    }

    bool isfull(){
        if((front ==0 && rear == size -1 )|| (front != 0 && (front-1)%(size-1) == rear)) return true;
        return false;
    }

    int popfront(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            int ans=arr[front];
            arr[front]=-1;
            if(front==rear){
                front=rear=-1;
            }else if(front == size -1){
                front = 0;
            }else{
                front++;
            }

            return ans;
        }
    }

    int poprear(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            int ans=arr[rear];
            arr[rear] = -1;
            if(front == rear){
                front=rear=-1;
            }else if(rear == 0){
                rear=size-1;
            }else{
                rear--;
            }

            return ans;
        }
    }

    bool isempty(){
        if(front == -1 ) return true;
        return false;
    }

    int getfront(){
        if(isempty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }else {
            return arr[front];
        }
    }

    int getrear(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            return arr[rear];
        }
    }

    void display(){
        if(isempty()){
            cout<<"Nothing to show"<<endl;
            return;
        }else{
            if(rear >= front){
                for(int i=front;i<=rear;i++){
                    cout<<arr[i]<<" ";
                }

                cout<<endl;
            }else{
                for(int i=front;i<size;i++){
                    cout<<arr[i]<<" ";
                }

                for(int i=0;i<=rear;i++){
                    cout<<arr[i]<<" ";
                }

                cout<<endl;
            }
        }
    }
};

int main(){

    dequeue obj1(5);

    obj1.pushrear(1);
    obj1.pushrear(2);
    obj1.pushrear(3);
    obj1.pushfront(0);

    obj1.display(); // Output: 1 2 3
    cout<<obj1.getfront()<<endl;
    cout<<obj1.getrear()<<endl;
    obj1.popfront();
    obj1.poprear();
    obj1.display(); // Output: 2 3
}