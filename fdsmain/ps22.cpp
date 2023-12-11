#include <iostream>
#include <list>

template <typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;

        Node(const T& d, int p) : data(d), priority(p) {}

        // Overload <= operator to compare nodes based on priority
        bool operator<=(const Node& other) const {
            return priority <= other.priority;
        }
    };

    std::list<Node> itemList;

public:
    // Function to insert an item with priority into the priority queue
    void enqueue(const T& item, int priority) {
        Node newNode(item, priority);

        // Find the correct position in the ordered list based on priority
        auto it = itemList.begin();
        while (it != itemList.end() && newNode <= *it) {
            ++it;
        }

        // Insert the new node at the correct position
        itemList.insert(it, newNode);
    }

    // Function to remove and return the item with the highest priority
    T dequeue() {
        if (!itemList.empty()) {
            T highestPriorityItem = itemList.front().data;
            itemList.pop_front();
            return highestPriorityItem;
        } else {
            std::cerr << "Priority queue is empty." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const {
        return itemList.empty();
    }

    // Function to display the contents of the priority queue
    void displayQueue() const {
        if (!itemList.empty()) {
            std::cout << "Priority Queue: ";
            for (const auto& node : itemList) {
                std::cout << "(" << node.data << ", " << node.priority << ") ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Priority queue is empty." << std::endl;
        }
    }
};

int main() {
    PriorityQueue<std::string> priorityQueue;

    // Enqueue items with priorities
    priorityQueue.enqueue("Item1", 3);
    priorityQueue.enqueue("Item2", 1);
    priorityQueue.enqueue("Item3", 2);

    // Display the initial priority queue
    priorityQueue.displayQueue();

    // Dequeue the highest priority item
    std::cout << "Dequeued: " << priorityQueue.dequeue() << std::endl;

    // Display the updated priority queue
    priorityQueue.displayQueue();

    return 0;
}
