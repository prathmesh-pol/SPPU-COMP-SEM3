/*
	7229 Khushi Assignment 15
*/

#include <iostream>
using namespace std;

class Queue{
    public:
        int front;
        int rear;
        int M;
        int* arr;

        Queue(){
            cout << "Enter Maximum number of orders that can be taken: ";
            cin >> M;
            arr = new int[M];
            front = -1;
            rear = -1;
        }
        ~Queue(){
            delete[] arr;
        }

       void enqueue(int val, int *arr){
    if (rear-front+1 == M){
        cout << "Queue Full\n";
        return;
    } else{
        rear++;
    }
    arr[(int)rear % M] = val;
    if (front == -1){
        front = 0;
    } 
    cout << rear << " " << front << " " << M <<"\n";
}

int dequeue(int *arr){
    if (front+1 > rear){
        cout << "Queue Empty\n";
        return -1;
    }
    int temp = arr[(int) front % M];
    front ++;
    return temp;
}

void display(int *arr){
    for (int i=front; i<rear+1; i++){
        cout << arr[(int) i % M] << " ";
    }
    cout << "\n";
}

};

int main(){
    Queue q;

    while (1){
        int i;
        cout << "\n1. To Make order.\n2. To Finish Order.\n3. To Show orders\n4.To Exit.\n";
        cin >> i;
        if (i == 1){
            int data;
            cout << "Enter order(int): ";
            cin >> data;
            q.enqueue(data, q.arr);
        } else if (i == 2){
            try{
                cout << "Finished " << q.dequeue(q.arr) << "\n";
            } catch(...){}
        } else if (i == 3){
            cout << "Queue is: \n";
            q.display(q.arr);
        } else{
            break;
        }
    }

    return 0;
}
