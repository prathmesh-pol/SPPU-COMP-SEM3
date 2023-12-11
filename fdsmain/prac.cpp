#include <bits/stdc++.h>
using namespace std;

class node
{
public:
   string name;
   string prn;
   node *next;
   node()
   {
      name = "";
      prn = '0';
      next = NULL;
   }
};
string name ,prn;


void printdata(node* n){
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


node* Entries(node * &head){
   int n;
   cout<<"ENter no";
   cin>>n;
   int i =n;
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
         end_insert(&head,name,prn);
         i--;
   }
}

int main()
{    node* head=NULL,*newnode;

    Entries(head);
    printdata(head);
   return 0;
}