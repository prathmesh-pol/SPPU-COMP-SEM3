#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Maximum size of the deque

class Deque
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    // Constructor
    Deque() : front(-1), rear(-1) {}

    // Function to check if the deque is empty
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    // Function to check if the deque is full
    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Function to add an element at the front of the deque
    void addFront(int element)
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + MAX_SIZE) % MAX_SIZE;
        }

        arr[front] = element;
        cout << "Element added at the front: " << element << endl;
    }

    // Function to add an element at the rear of the deque
    void addRear(int element)
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = element;
        cout << "Element added at the rear: " << element << endl;
    }

    // Function to delete an element from the front of the deque
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot delete from the front." << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    // Function to delete an element from the rear of the deque
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot delete from the rear." << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
        }
    }

    // Function to display the elements in the deque
    void displayDeque()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";
        int current = front;
        while (current != rear)
        {
            cout << arr[current] << " ";
            current = (current + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    Deque deque;

    // Add elements to the front and rear of the deque
    deque.addFront(5);
    deque.addRear(10);
    deque.addFront(3);

    // Display the deque
    deque.displayDeque();

    // Delete elements from the front and rear of the deque
    deque.deleteFront();
    deque.deleteRear();

    // Display the updated deque
    deque.displayDeque();

    return 0;
}
