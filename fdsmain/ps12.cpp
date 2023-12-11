#include<bits/stdc++.h>
using namespace std ;

class node{
    public:
    string name;
    string prn;
    node *next;
    node(){
        prn = '0';
        name = "";
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


    if(ch==7){
        cout<<"\n\n Do again!!!\n\n";
        flag = false;
        exit(0);
    }

    }
}