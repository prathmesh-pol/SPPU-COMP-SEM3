#include <iostream>
#include <list>

using namespace std;

// Template class for Priority Queue
template <typename T>
class PriorityQueue
{
public:
    // Inner class for storing data items and priorities
    class QueueItem
    {
    public:
        T data;
        int priority;

        // Overloading <= operator to compare priorities
        bool operator<=(const QueueItem &other) const
        {
            return priority <= other.priority;
        }
    };

    list<QueueItem> itemList; // Inorder list to store items in the queue

public:
    // Function to add an item with priority to the queue
    void enqueue(const T &data, int priority)
    {
        QueueItem newItem{data, priority};

        // Finding the correct position to maintain order
        auto it = itemList.begin();
        while (it != itemList.end() && !(newItem <= *it))
        {
            ++it;
        }

        itemList.insert(it, newItem);
    }

    // Function to remove and return the item with the highest priority
    T dequeue()
    {
        if (!itemList.empty())
        {
            T data = itemList.front().data;
            itemList.pop_front();
            return data;
        }
        else
        {
            cerr << "Queue is empty. Cannot dequeue." << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() const
    {
        return itemList.empty();
    }

    // Function to display the items in the queue
    void displayQueue() const
    {
        cout << "Priority Queue:" << endl;
        for (const auto &item : itemList)
        {
            cout << "Data: " << item.data << ", Priority: " << item.priority << endl;
        }
        cout << endl;
    }
};

int main()
{
    // Example usage of PriorityQueue
    PriorityQueue<string> priorityQueue;

    // Adding items to the queue with priorities
    priorityQueue.enqueue("Item 1", 2);
    priorityQueue.enqueue("Item 2", 1);
    priorityQueue.enqueue("Item 3", 3);

    // Displaying the initial queue
    priorityQueue.displayQueue();

    // Dequeueing and displaying the highest priority item
    cout << "Dequeued item: " << priorityQueue.dequeue() << endl;

    // Displaying the updated queue
    priorityQueue.displayQueue();

    return 0;
}
