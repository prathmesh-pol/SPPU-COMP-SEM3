#include<iostream>
#include<string.h>
using namespace std;

class StudentData;

class Student{
    string name;
    int roll_no;
    string clas;
    char* division;
    string DOB;
    char* bloodgroup;
    static int count;

    public:

    Student()
    {
        name="";
        roll_no=0;
        clas="";
        division=new char;
        DOB="dd/mm/yyyy";
        bloodgroup=new char;
    }

    ~Student()
    {
        delete division;
        delete[] bloodgroup;
    }

    static int getCount()
    {
        return count;
    }

    void getData(StudentData*);
    void displayData(StudentData*);
};

class StudentData{
    string contactaddress;
    long int* telno;
    long int* dlno;
    friend class Student;

    public:

    StudentData()
    {
        contactaddress="";
        telno=new long;
        dlno=new long;
    }

    ~StudentData()
    {
        delete telno;
        delete dlno;
    }

    void getStudData()
    {
        cout<<"Enter Contact Address : ";
        cin.get();
        getline(cin,contactaddress);
        cout<<"Enter Telephone Number : ";
        cin>>*telno;
        cout<<"Enter Driving License Number : ";
        cin>>*dlno;
    }

    void displayStudData()
    {
        cout<<"Contact Address : "<<contactaddress<<endl;
        cout<<"Telephone Number : "<<*telno<<endl;
        cout<<"Driving License Number : "<<*dlno<<endl;
    }
};

inline void Student::getData(StudentData* st)
{
    cout<<"Enter Student Name : ";
    getline(cin,name);
    cout<<"Enter Roll Number : ";
    cin>>roll_no;
    cout<<"Enter Class : ";
    cin.get();
    getline(cin,clas);
    cout<<"Enter Division : ";
    cin>>division;
    cout<<"Enter Date of Birth : ";
    cin.get();
    getline(cin,DOB);
    cout<<"Enter Blood Group : ";
    cin>>bloodgroup;
    st->getStudData();
    count++;
}

inline void Student::displayData(StudentData* st1)
{
    cout<<"Student Name : "<<name<<endl;
    cout<<"Roll Number : "<<roll_no<<endl;
    cout<<"Class : "<<clas<<endl;
    cout<<"Division : "<<division<<endl;
    cout<<"Date of Birth : "<<DOB<<endl;
    cout<<"Blood Group : "<<bloodgroup<<endl;
    st1->displayStudData();
}

int Student::count;

int main()
{
    Student* stud1[200];
    StudentData* stud2[200];
    int n=0;
    char ch;

    do
    {
        stud1[n]=new Student;
        stud2[n]=new StudentData;
        stud1[n]->getData(stud2[n]);
        n++;
        cout<<"Do you want to add another student details (y/n) : ";
        cin>>ch;
        cin.get();
    } while (ch=='y' || ch=='Y');

    for(int i=0;i<n;i++)
    {
        cout<<endl;
        stud1[i]->displayData(stud2[i]);
    }

    cout<<endl;
    cout<<"Total Students : "<<Student::getCount();
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        delete stud1[i];
        delete stud2[i];
    }


    return 0;
}