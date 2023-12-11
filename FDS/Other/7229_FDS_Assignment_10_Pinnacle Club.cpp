/*

Department of Computer Engineering has student's club named
'Pinnacle Club'. Students of Second, third and final year of
department can be granted membership on request. Similarly one
may cancel the membership of club. First node is reserved for
president of club and last node is reserved for secretary of
club. Write C++ program to maintain club member‘s information
using singly linked list. Store student PRN and Name. Write
functions to :

a) Add and delete the members as well as president or even secretary.

b) Compute total number of members of club

c) Display members

d) Display list in reverse order using recursion

e) Two linked lists exists for two divisions. Concatenate two lists

*/


#include<bits/stdc++.h>
using namespace std ;

class node{
    public:
    string name;
    string prn;
    node *next;
    node(){
        prn = '0';
        name = 'ait';
        next = NULL;
    }
};


string name ,prn;

void printList(node* n){
    cout<<"\n"<< left<< setw(20)<< "NAME"<< left<< setw(5)<<"PRN"<<endl<<endl;
    while(n!=NULL){
    cout<< left<< setw(20)<< n->name<< left<< setw(5)<<n->prn<<endl;
        n = n->next;
    }
}

void end_insert(node **head_ref , string namedata, string prndata){
   node * newnode = new node();
   newnode->name = namedata;
   newnode->prn = prndata;
   newnode->next = NULL;
   node * end = *head_ref;

   if(*head_ref==NULL){
       *head_ref = newnode;
       return ;
   }
   while(end->next!=NULL){
       end = end->next;
   }
   end->next = newnode;
   return;
}

void deletion(node **head_ref, string target){
    node *temp, *prev;
    temp = *head_ref;

    if(temp->name==target){
        *head_ref = temp ->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->name!=target){
        prev = temp;
        temp = temp ->next;
    }

    if(temp==NULL){
        return;
    }

    prev->next= temp->next;
    free(temp);
}

node* ReverseList_Recrusive(node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead = ReverseList_Recrusive(head->next);
        head->next->next = head;
        head->next = NULL;
    
    return newhead;
}

void total_number(node* n){
    int num=0;
    while(n!=NULL){
        n = n->next;
        num++;
    }
    cout<<"\nTotal number of members of club : "<<num<<endl;
}

node* Entries(node * &head){
    int n;
    cout<<"\nEnter the number Entries : ";
        cin>>n;
        int i=n;
        while(i>0){
            if(i==n ){
                cout<<"\nEnter PRN of President of : ";
                cin>>prn;
                cin.ignore();
                cout<<"Enter Name of President : ";
                getline(cin, name);
                
            }
            else if(i==1){
                cout<<"\nEnter PRN of Secretary : ";
                cin>>prn;
                cin.ignore();
                cout<<"Enter Name of Secretary : ";
                getline(cin, name);
            }
            else{
                cout<<"\nEnter PRN of member : ";
                cin>>prn;
                cin.ignore();
                cout<<"Enter Name of member : ";
                getline(cin, name);
            }

            end_insert(&head, name, prn);
            i--;
            
        }
        return head;
        
}

void Concatenate(node *&div1, node *&div2){
    node * temp = div1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = div2;
   
}

int main(){
    node *head = NULL,*newhead;
    bool flag = true;
    int ch;
    while(flag){

    cout<<"\n\n ---------------- MENU ---------------- \n\n";

    cout<<" 1. Add Entry to Pinnacle Club\n";
    cout<<" 2. Display the Members of the Club\n";
    cout<<" 3. Compute total number of members of club\n";
    cout<<" 4. Delete member from the Club\n";
    cout<<" 5. Display list in reverse order\n";
    cout<<" 6. Concatenate two lists\n";
    cout<<" 7. Exit\n";

    cout<<"\nEnter Choice : ";
    cin>>ch;

    
    if(ch==1)   Entries(head);
    
    if(ch==2)   printList(head);
    
    if(ch==3)   total_number(head);

    if(ch==4){
    string ch;
    cout<<"\nEnter name of member to be deleted : ";
    cin.ignore();
    getline(cin , name);
    deletion(&head, name);
    }

    if(ch==5){
        cout<<"\nReverse ordered list : \n";
        newhead = ReverseList_Recrusive(head);
        printList(newhead);
        head = newhead;
    }

    if(ch==6){
        node * div1_head=NULL, *div2_head=NULL, *finalList;

        cout<<"\n\n------------------ Entries of div 1 ------------------\n\n";
        Entries(div1_head);
        printList(div1_head);

        cout<<"\n\n------------------ Entries of div 2 ------------------\n\n";
        Entries(div2_head);
        printList(div2_head);

        cout<<"\n\n------------------ Final List ------------------\n\n";
        Concatenate(div1_head,div2_head);
        printList(div1_head);
        head = div1_head;

    }

    if(ch==7){
        cout<<"\n\nThank you sir!!!\nDo visit again!!!\n\n";
        flag = false;
        exit(0);
    }

    }
}