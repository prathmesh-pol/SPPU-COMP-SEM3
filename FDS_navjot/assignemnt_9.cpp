#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int prn;
    string name;
    node *next;

public:
    node() {
        cout << "Node Initialized" << endl;
        next = NULL;
    }

    node(int n, string s) {
        this->prn = n;
        this->name = s;
        next = NULL;
    }

    ~node(){
        int data1 = this -> prn;
        string data2 = this -> name;

        if(this->next != NULL){
            delete next;
            next = NULL;
        }

        cout<<"Memory has been freed"<<endl;

    }
};

void insertathead(node *&head, int P, string s) {
    node *temp = new node(P, s);
    if (head == NULL) {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void insertattail(node *&tail, node *&head, int P, string s) {
    node *temp = new node(P, s);
    if (tail == NULL){
        tail = temp;
        if(head==NULL){
            head = tail;
        }
        return;
    }
    tail->next = temp;
    tail = tail->next;
    // tail->next = head; 
}

void insertmembers(node *&head, int P, string s) {
    node *temp = new node(P, s);
    if (head == NULL) {
        head = temp;
        return;
    }
    node *point = head;
    while (point->next != NULL) {
        point = point->next;
    }
    point->next = temp;
}

void displayList(node *head) {
    node *current = head;
    if (current == NULL) {
        cout << "Empty List" << endl;
        return;
    }
    
    while(current != NULL){
        cout<<current->prn<<" "<<current->name;
        current=current->next;
        cout<<endl;
    }
}



int main() {
    node *head = NULL;
    node *tail = NULL;
    // displayList(head);

    // Create linked list
    
    // set president
    insertathead(head,1048,"Navjot");
    // set secretary
    insertattail(tail,head,1049,"tourist");

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        string s; cin>>s;

        insertmembers(head,x,s);
    }

    cout<<"-------------------"<<endl;
    // Display the linked list
    displayList(head);
    displayList(tail);

}
