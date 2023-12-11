#include <iostream>
using namespace std;

// Node structure to store binary digits
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// DoublyLinkedList class for managing binary numbers
class DoublyLinkedList
{
public:
    Node *head;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr) {}

    // Function to add a binary digit at the end
    void addDigit(int digit)
    {
        Node *newNode = new Node{digit, nullptr, nullptr};

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Function to compute 1's complement
    void onesComplement()
    {
        Node *current = head;

        while (current != nullptr)
        {
            current->data = 1 - current->data;
            // cout << current->data << endl;
            current = current->next;
        }
    }

    // Function to compute 2's complement
    void twosComplement()
    {
        onesComplement(); // Compute 1's complement

        Node *current = head;
        Node *last = nullptr; // Keep track of the last node for efficient addition

        // Traverse to the end of the list to find the last node
        while (current->next != nullptr)
        {
            last = current;
            current = current->next;
        }

        // Add 1 to the 1's complement (starting from the rightmost bit)
        while (current != nullptr)
        {
            int sum = current->data + 1;
            current->data = sum % 2;

            if (sum < 2)
            {
                // No need to carry, break out of the loop
                break;
            }

            // Move to the previous node (towards the leftmost bit)
            current = last;
            if (last != nullptr)
            {
                last = last->prev;
            }
        }

        // If there's a carry left, add a new node with the carry
        // if (current == nullptr && last == nullptr)
        // {
        //     // The list was empty, add a new node at the beginning
        //     addDigit(1);
        // }
    }

    // Void function to reverse the linked list
    void reverseList()
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Void function to add binary numbers in place (starting from LSB)
    void addBinary(DoublyLinkedList &num)
    {
        reverseList(); // Reverse the linked lists
        num.reverseList();

        Node *current1 = head;
        Node *current2 = num.head;
        int carry = 0;

        while (current1 || current2)
        {
            int sum;

            if (current1 != nullptr && current2 != nullptr)
            {
                sum = carry + current1->data + current2->data;
                current1->data = sum % 2;
                current1 = current1->next;
                current2 = current2->next;
            }
            else if (current1 != nullptr)
            {
                sum = carry + current1->data;
                current1->data = sum % 2;
                current1 = current1->next;
            }
            else if (current2 != nullptr)
            {
                sum = carry + current2->data;
                addDigit(sum % 2);
                current2 = current2->next;
            }
            else
            {
                sum = carry;
                addDigit(sum % 2);
            }

            carry = sum / 2;
        }

        reverseList(); // Reverse the result back to the original order
        num.reverseList();
    }

    // Function to display the binary number
    void displayBinary()
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data;
            current = current->next;
        }

        cout << endl;
    }
};

int main()
{
    // Create two binary numbers
    DoublyLinkedList binaryNum1, binaryNum2;

    // Add digits to the first binary number (1010)
    binaryNum1.addDigit(1);
    binaryNum1.addDigit(0);
    binaryNum1.addDigit(1);
    binaryNum1.addDigit(0);

    // Add digits to the second binary number (1100)
    binaryNum2.addDigit(0);
    binaryNum2.addDigit(1); 
    binaryNum2.addDigit(0);
    binaryNum2.addDigit(0);

    // Display the binary numbers
    cout << "Binary Number 1: ";
    binaryNum1.displayBinary();

    cout << "Binary Number 2: ";
    binaryNum2.displayBinary();

    // Compute and display 1's complement of the first binary number
    binaryNum1.onesComplement();
    cout << "1's Complement of Binary Number 1: ";
    binaryNum1.displayBinary();

    // Compute and display 2's complement of the second binary number
    binaryNum2.twosComplement();
    // binaryNum2.onesComplement();
    cout << "2's Complement of Binary Number 2: ";
    binaryNum2.displayBinary();

    // Add two binary numbers and display the result
    binaryNum1.addBinary(binaryNum2);
    cout << "Sum of Binary Numbers: ";
    binaryNum1.displayBinary();

    return 0;
}
