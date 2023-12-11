#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Deque {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque Overflow: Cannot insert element at front.\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }

        arr[front] = element;
        cout << "Inserted element at front: " << element << endl;
    }

    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque Overflow: Cannot insert element at rear.\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = element;
        cout << "Inserted element at rear: " << element << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow: Cannot delete element from front.\n";
            return;
        }

        cout << "Deleted element from front: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow: Cannot delete element from rear.\n";
            return;
        }

        cout << "Deleted element from rear: " << arr[rear] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);

        cout << endl;
    }
};

int main() {
    Deque deque;

    deque.insertFront(5);
    deque.insertRear(10);
    deque.insertRear(20);
    deque.insertFront(15);

    deque.display();

    deque.deleteFront();
    deque.deleteRear();

    deque.display();

    return 0;
}
