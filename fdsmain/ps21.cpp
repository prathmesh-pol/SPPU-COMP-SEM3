#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int* arr;

public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        arr = new int[size];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == front - 1);
    }

    // Function to enqueue an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        cout << value << " enqueued to the queue.\n";
    }

    // Function to dequeue an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        int removedValue = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        cout << removedValue << " dequeued from the queue.\n";
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Elements in the queue: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << "\n";
    }
};

int main() {
    CircularQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display();

    queue.dequeue();
    queue.dequeue();

    queue.display();

    queue.enqueue(6);
    queue.enqueue(7);

    queue.display();

    return 0;
}
