#include <iostream>
using namespace std;
class complex
{
   public:
         float real,img;
         complex()
         {
           real = 0;
           img = 0;
         }
     
     
        friend ostream & operator <<(ostream& ,complex& );
        friend istream & operator >>(istream& ,complex& );
        friend complex operator +(complex &c1,complex&a1);
        friend complex operator -(complex &c2,complex&a2);
        friend complex operator *(complex &c3,complex&a3);
        friend complex operator /(complex &c4,complex&a4);
};

  istream & operator >>(istream&in ,complex&obj )
  {
    cout<<"Enter the real part: ";
    in>>obj.real;
    cout<<"Enter the imaginary part: ";
    in>>obj.img;
    return in;
  }

  ostream & operator <<(ostream& out ,complex& obj )
  {
    cout<<"Complex No is :";
    out<<obj.real<<"+i"<<obj.img<<"\n";   
    return out;
  }

  complex operator +(complex &c1,complex&a1)
  {
    complex r1;
    r1.real=c1.real+a1.real;
    r1.img=c1.img+a1.img;
    return r1;
  }

  complex operator -(complex &c2,complex&a2)
  {
    complex r2;
    r2.real=c2.real-a2.real;
    r2.img=c2.img-a2.img;
    return r2;
  }

  complex operator *(complex &c3,complex&a3)
  {
    complex r3;
    r3.real=c3.real*a3.real-c3.img*a3.img;
    r3.img=c3.real*a3.img+c3.img*a3.real;
    return r3;
  }

  complex operator /(complex &c4,complex&a4)
  {
    complex r4;
    r4.real=(c4.real*a4.real+c4.img*a4.img) / (a4.real*a4.real+c4.img*c4.img);
    r4.img=(-c4.real*a4.img+c4.img*a4.real) / (a4.real*a4.real+c4.img*c4.img);
    return r4;
  }
int main()
{
    complex s,a,b,add,sub,mul,div;
    cout<<"Enter First Complex No:\n";
    cin>>a;
    cout<<"Enter Second Complex No:\n";
    cin>>b;
   int ch;
   char ans ,y,Y;
   do
   {
        cout<<"\nMENU:";
        cout<<"\n1.Addition";
        cout<<"\n2.Substraction";
        cout<<"\n3.Multiplication";
        cout<<"\n4.Division";
        cout<<"\nEnter your Choice: ";
        cin>>ch;

     switch(ch)
     {
        case 1:
            add=a+b;
            cout<<"Addition of ";
            cout<<add<<"\n";
            break;
        case 2:
            sub=a-b;
            cout<<"Substraction of ";
            cout<<sub<<"\n";
            break;
        case 3:
           mul=a*b;
           cout<<"Multiplication of ";
           cout<<mul<<"\n";
           break;
        case 4:
            div=a/b;
            cout<<"Division of ";
            cout<<div<<"\n";
            break;
       default:
            cout<<"Please Enter valid choice";
            break;
     }
     cout<<"\n Do you want to continue (y/n): ";
     cin>>ans;
  }
  while(ans=='y'||ans=='Y');

  return 0;
}