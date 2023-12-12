#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int priority;
    node *next;

public:
    node()
    {
        next = NULL;
    }

    node(int val, int pri)
    {
        this->data = val;
        this->priority = pri;
        node *next = NULL;
    }
};

class Priority_queue
{
public:
    node *head;

public:
    Priority_queue()
    {
        head = NULL;
    }

    void enqueue(int val, int pri)
    {
        node *newnode = new node(val, pri);

        if (head == NULL || pri > head->priority)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL and temp->next->priority >= pri)
            {
                temp = temp->next;
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }

        node *temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        return val;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Priority queue is empty" << endl;
            return;
        }

        node *temp = head;
        while (temp != NULL)
        {
            cout << "Data : " << temp->data << " Priority : " << temp->priority << endl;
            temp = temp->next;
        }
    }
};
int main()
{

    Priority_queue p;
    p.enqueue(5, 1);
    p.enqueue(5, 2);
    p.enqueue(5, 3);
    p.enqueue(6, 3);
    p.enqueue(5, 1);
    p.enqueue(4, 4);

    p.display();
    cout << p.dequeue() << endl;
    p.display();
}