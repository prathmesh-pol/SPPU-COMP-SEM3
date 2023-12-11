// Imagine a publishing company which does marketing for book and audio cassette versions. 
//Create a class publication that stores the title (a string) and price (type float) of publications. 
//From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). 
//Write a program that instantiates the book and tape class,allows user to enter data and displays the data members.
// If an exception is caught, replace all the data member values with zero values.


#include<bits/stdc++.h>
using namespace std ;

class publication{
    public:
        string title;
        static float price;

        
        void input_pub(void);
        void print_pub(void);

};

float publication::price=0;

void publication:: input_pub(void){
            float temp;
            cout<<"Enter Title for the book : ";
            cin>>title;
            cout<<"Enter Price of the book : ";
            cin>>temp;

            price += temp;

        }

void publication:: print_pub(void){
            cout<<"Title : "<<title<<endl;
            cout<<"Price : "<<price<<endl;
        }


class book: virtual public publication{
    public:
        int page_count;
        void input_page_cnt(void){
            cout<<"Enter number of pages in the book : ";
            cin>>page_count;
        }
    

        void print_page_cnt(void){
            cout<<"Pages : "<<page_count<<endl;
             
        }


};

class tape:virtual public publication{
    public:
        float play_time;

        void input_time(){
            cout<<"Enter Playing time(in minutes) : ";
            cin>>play_time;

        }

        void print_time(){
            cout<<"tape count : "<<play_time<<endl;
            
        }


};

class Total_price:public tape , book{
    public:
              
        void print_pub(void){
            cout<<"Total Price : "<< price;
            cout<<"\nAfter Applyinng 10 percent discount" <<endl;
            cout<<"Pay : "<<price*0.9<<endl;
        }
        
    
};


int main(){
    book b1,b2;
    tape t1,t2;

    cout<<"\n\n-------------- BOOK 1 --------------\n\n";

    b1.input_pub();
    b1.input_page_cnt();
    t1.input_time();
    b1.print_pub();
    b1.print_page_cnt();
    t1.print_time();


    cout<<"\n\n-------------- BOOK 2 --------------\n\n";

    b2.input_pub();
    b2.input_page_cnt();
    t2.input_time();
    b2.print_pub();
    b2.print_page_cnt();
    t2.print_time();

    cout<<"\n\n-------------- TOTAL PRICE --------------\n\n";
    Total_price p;
    p.print_pub();
    
}