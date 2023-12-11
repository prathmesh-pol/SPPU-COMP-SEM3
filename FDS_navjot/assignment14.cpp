#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    int priority;
    Node<T>* next;

    Node() {
        next = nullptr;
    }

    Node(T val, int pri) {
        data = val;
        priority = pri;
        next = nullptr;
    }
};

template <class T>
class PriorityQueue {
private:
    Node<T>* head;

public:
    PriorityQueue() {
        head = nullptr;
    }

    void enqueue(T item, int priority) {
        Node<T>* newNode = new Node<T>(item, priority);

        if (head == nullptr || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty" << endl;
            return T();
        }

        Node<T>* temp = head;
        T item = head->data;
        head = head->next;
        delete temp;
        return item;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty" << endl;
            return;
        }

        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << "Data: " << temp->data << " Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PriorityQueue<int> pq;

    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.enqueue(40, 2);

    cout << "Priority Queue:" << endl;
    pq.display();

    cout << "\nDequeue: " << pq.dequeue() << endl;
    cout << "Priority Queue after dequeue:" << endl;
    pq.display();

    return 0;
}
