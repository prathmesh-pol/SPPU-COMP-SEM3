#include<iostream>
using namespace std;

class node
{	
        node *prev;
        bool n;
        node*next;
    public:
        node()
        {
            prev=next=NULL;
        }
        node(bool b) 
        {
            n=b;
            prev=next=NULL;
        }
        friend class binary;
};

class binary
{
	node *start;
	
	public:
		binary()        {  start=NULL;}
		void binary_number(int no);
		void displayBinary();
		void onesComplement();
		void twoscomplement();
		
};

void binary::binary_number(int no)
{
	bool tem;
	node *p;
	tem=no%2;
	start=new node(tem);
	no=no/2;
	while(no!=0)
	{
		tem=no%2;
		no=no/2;
        p=new node(tem);
        p->next=start;
        start->prev=p;
		start=p;
	}
}

void binary::displayBinary()
{
	node *t;
	t=start;
	while(t!=NULL)
	{
		cout<<t->n;
		t=t->next;
	}
	
}
void binary::onesComplement()
{
	node *t;
	t=start;
	
	while(t!=NULL)
	{
		if(t->n==0)
			t->n=1;
		else
			t->n=0;
		
		t=t->next;
		
	}
}

void binary::twoscomplement()
{
	onesComplement();
	bool carry=1;
	node *t;
	t=start;
	while(t->next!=NULL)        { t=t->next;}
	while(t!=NULL)
	{
        if(t->n==1&& carry==1)
        {
            t->n=0;
            carry=1;
        }

        else if(t->n==0&& carry==1)
        {
            t->n=1;
            carry=0;
        }

        else if(carry==0)
            break;
        
        t=t->prev;
    }

    displayBinary();
}


int main()
{
	int num,num1;
	binary n1,n3,n2;
	int choice=1;
	do
	{
		cout<<"\n\n=========Binary Number Operations========\n";
		cout<<"1. Generate binary\n2.One's Complement\n3.Two's Complement\n0.Exit\n\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter Number in decimal form: ";
					cin>>num;
					n1.binary_number(num);
					cout<<"\nBinary Representation: ";
					n1.displayBinary();
					break;
			case 2:cout<<"\nEnter Number in decimal form: ";
					cin>>num;
					n1.binary_number(num);
					cout<<"\nBinary Representation: ";
					n1.displayBinary();
					cout<<"\nOnes Complement: ";
					n1.onesComplement();
					n1.displayBinary();
					break;
			case 3:cout<<"\nEnter Number in decimal form: ";
					cin>>num;
					n1.binary_number(num);
					cout<<"\nBinary Representation: ";
					n1.displayBinary();
					cout<<"\nTwos complement; ";
					n1.twoscomplement();
					break;
			
		}

	}while(choice!=0);

	n1.binary_number(7);
	cout<<"\nBinary Representation: ";
	n1.displayBinary();

	cout<<"\nTwos complement; ";
	n1.twoscomplement();
	return 0;
}