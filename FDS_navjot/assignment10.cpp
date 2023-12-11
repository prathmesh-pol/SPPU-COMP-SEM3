#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * prev;
    node * next;

    public:

    node(int d){
        this->data = d;
        prev = NULL;
        next = NULL;
    }
};

void insertathead(node * &head, int data){
    node * temp = new node(data);
    if( head == NULL ){
        head = temp;
        return;
    }

    temp->next = head;
    temp->prev = NULL;
    head = temp;

}

void insertatlast(node * &head,node * &tail, int data){
    node * temp = new node(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void display(node * head){
    node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

vector<int> converttobinary(int num){
    vector<int> ans;
    while(num>0){
        int val = num%2;
        num/=2;
        ans.push_back(val);
    }

    return ans;
}

void onecomplement(node * head){
    node * temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            temp -> data = 1;
        }else{
            temp -> data = 0;
        }
        temp = temp ->next;
    }

    display(head);
}

void twocomplement(node * head){
    onecomplement(head);
    node * temp = head;
    int carry = 1;
    while(temp->next = NULL){
        temp = temp->next;
    }

    while(temp != NULL){
        int sum = carry + temp->data;
        temp -> data = sum%2;
        carry=sum/2;
        temp = temp->prev;
    }
}

node * addbinary(node * h1, node * h2){
    //  carry = 0;
    // loop
    // sum = carry + h1data + h2 data
    // insertatlast = sum%2 ,
    // carry = sum/2;
}

int main(){
    node * dll1 = NULL;
    node * tail1 = NULL;
    node * dll2 = NULL;
    node * tail2 = NULL;

    int num1,num2; 
    // cin>>num1>>num2;
    num1=9, num2 = 6;
    vector<int> n1 = converttobinary(num1);
    reverse(n1.begin(),n1.end());

    vector<int> n2 = converttobinary(num2);
    reverse(n2.begin(),n2.end());

    for(auto i : n1){
        insertatlast(dll1,tail1,i);
    }

    for(auto i : n2){
        insertatlast(dll2,tail2,i);
    }

    display(dll1);
    display(dll2);


    onecomplement(dll1);
    display(dll1);
    


}

// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* prev;
//     Node* next;

//     Node(int value) {
//         data = value;
//         prev = nullptr;
//         next = nullptr;
//     }
// };

// Node* createNode(int value) {
//     return new Node(value);
// }

// void insertEnd(Node** head, int data) {
//     Node* newNode = createNode(data);
//     if (*head == nullptr) {
//         *head = newNode;
//     } else {
//         Node* temp = *head;
//         while (temp->next != nullptr) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         newNode->prev = temp;
//     }
// }

// void display(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data;
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void onesComplement(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         temp->data = (temp->data == 0) ? 1 : 0;
//         temp = temp->next;
//     }
// }

// void twosComplement(Node* head) {
//     onesComplement(head);
//     int carry = 1;
//     Node* temp = head;
//     while (temp->next != nullptr) {
//         temp = temp->next;
//     }
//     while (temp != nullptr) {
//         int sum = temp->data + carry;
//         temp->data = sum % 2;
//         carry = sum / 2;
//         temp = temp->prev;
//     }
// }

// Node* addBinary(Node* num1, Node* num2) {
//     Node* result = nullptr;
//     int carry = 0;
//     while (num1 != nullptr || num2 != nullptr || carry) {
//         int sum = (num1 ? num1->data : 0) + (num2 ? num2->data : 0) + carry;
//         carry = sum / 2;
//         insertEnd(&result, sum % 2);
//         if (num1) num1 = num1->next;
//         if (num2) num2 = num2->next;
//     }
//     return result;
// }

// int main() {
//     Node* binaryNum1 = nullptr;
//     Node* binaryNum2 = nullptr;

//     // Inserting binary numbers into the linked lists
//     // Example: 1010 and 1101
//     insertEnd(&binaryNum1, 1);
//     insertEnd(&binaryNum1, 0);
//     insertEnd(&binaryNum1, 1);
//     insertEnd(&binaryNum1, 0);

//     insertEnd(&binaryNum2, 1);
//     insertEnd(&binaryNum2, 1);
//     insertEnd(&binaryNum2, 0);
//     insertEnd(&binaryNum2, 1);

//     cout << "Binary Number 1: ";
//     display(binaryNum1);

//     cout << "Binary Number 2: ";
//     display(binaryNum2);

//     cout << "1's Complement of Binary Number 1: ";
//     onesComplement(binaryNum1);
//     display(binaryNum1);

//     cout << "2's Complement of Binary Number 2: ";
//     twosComplement(binaryNum2);
//     display(binaryNum2);

//     Node* sum = addBinary(binaryNum1, binaryNum2);
//     cout << "Sum of Binary Numbers: ";
//     display(sum);

//     return 0;
// }
