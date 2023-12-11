// 12 Linked list Department of Computer Engineering has student's club named 'Pinnacle Club'. 
// Students of Second, third and final year of department can be granted membership 
// on request. Similarly one may cancel the membership of club. First node is reserved 
// for president of club and last node is reserved for secretary of club. Write C++ 
// program to maintain club member‘s information using singly linked list. Store 
// student PRN and Name. Write functions to
// a) Add and delete the members as well as president or even secretary.
// b) Compute total number of members of club
// c) Display members 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ClubMember
{
    public:
    int PRN;
    string name;
    ClubMember *next;

    ClubMember(int p,string s){ ////to call
           PRN=p;
           name=s;
           next=nullptr;
    }
};

class PinnacleClub
{
    public:
    ClubMember*president;
    ClubMember*secretary;
    public:

    PinnacleClub()
    {
    president=nullptr;
    secretary=nullptr;
    }

    void addMember(int prn,string name){

        ClubMember *newMember=new ClubMember(prn,name);

                if(president==nullptr){
                      president=newMember;
                      secretary=newMember;
                }else{
                    secretary->next=newMember;
                    secretary=newMember;
                }
    }
    void display(){
          ClubMember* current=president;
          while (current!=nullptr){
             cout<<"PRN : "<<current->PRN<<"  NAME: "<<current->name<<endl;
             current= current->next;

          }


    }
    void totoalMember(){
        int count=0;
        ClubMember* current=president;
        while(current!=nullptr){
            count++;
            current=current->next;
        }
        cout<<"Total number of member : "<<count<<endl;
        return ;
        
    }
    void deleteMember(int prn){
        ClubMember*current=president;
        ClubMember*previous=nullptr;

        while(current!=nullptr && current->PRN!=prn){
            previous=current;
            current=current->next;
        }

        if(current==nullptr){
            cout<<"Member not exist"<<endl;
            return;
        }else if(current==president){
            president=president->next;
        }else{
            //to delet member
            previous->next=current->next;
        }
        delete current;

    }



};
int main(){
    PinnacleClub p;  //object
    int prn;
    string name;
    for(int i=0;i<3;i++){
        cout<<"prn : ";
          cin>>prn;
        cout<<"name : ";
          cin>>name;
          p.addMember(prn,name);
    }
    p.display();
    p.totoalMember();
    int n;
    cout<<"Enter the PRN that u want to delelt : ";
    cin>>n;
    p.deleteMember(n);
    p.display();
}