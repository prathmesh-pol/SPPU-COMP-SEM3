#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace  std;
class Student
{
        public:
                int Day, Month, Year ;
                string Name;
                string Phone_Number;
        public:
        void Input()
        {
                cout<<"\nEnter Name : ";
                getline(cin,Name);
                cout<<"Enter Phone Number : ";
                getline(cin,Phone_Number);
                cout<<"Enter the Date of Birth : (in dd/mm/yy) format : ";
                scanf("%d/%d/%d",&Day,&Month,&Year);
                while(Day > 31 || Day < 0)
                {
                        cout<<"Invalid Date of Birth "<<endl;
                        cout<<"Enter the correct day ";
                        cin>>Day;
                }
                while(Month > 12 || Month < 1 )
                {
                        cout<<"Invalid Date of Birth "<<endl;
                        cout<<"Enter the correct Month ";
                        cin>>Month;
                }
        }
        void Display()
        {   
              
                cout<< left<< setw(20)<< Name<< left<< setw(20)<<Phone_Number<<left<< setw(20);
                printf("%d/%d/%d",Day,Month,Year);
                cout<<endl;
        }
};
bool comparator(Student s1, Student s2)
{
        if(s1.Name < s2.Name)
                return 1;
        else
                return 0;

        if(s1.Name == s2.Name)
                return(s1.Year < s2.Year);

        if(s1.Year == s2.Year)
                return(s1.Month < s2.Month);

        return(s1.Day < s2.Day);
}
int main(void)
{
        Student s1;  string key; 
        s1.Input();
        vector<Student> list;
        list.push_back(s1);
        int choice, i;
        
        do
        {
                Student student;
                int flag = 0;
                cout<<endl<<"----------Menu------------ "<<endl;
                cout<<"1. Add a Student  "<<endl;
                cout<<"2. Sort the List  "<<endl;
                cout<<"3. Display the List  "<<endl;
                cout<<"4. Search an Element  "<<endl;
                cout<<"5. Exit  "<<endl;

                cout<<"\nEnter choice : ";
                cin>>choice;
                switch (choice)
                {
                        case 1:
                                cin.ignore();
                                student.Input();
                                list.push_back(student);
                                break;
                        case 2:
                                sort(list.begin(),list.end(),comparator);
                                break;
                        case 3:
                                cout<<"\n"<< left<< setw(20)<< "NAME"<< left<< setw(20)<<"MARKS "<<left<< setw(20)<<"ROLL NUMBER "<<endl<<endl;
                                for(i=0; i< list.size();i++)
                                        list[i].Display();
                                break;
                        case 4:
                                cout<<"\nEnter the name to be searched : ";
                                cin.ignore();
                                getline(cin,key);
                                for(auto itr = list.begin() ; itr != list.end() ; itr++){
                                        if(list[i].Name == key){
                                        cout<<"Name Found "<<endl;break;
                                        }                                       
                                }
                               
                                        cout<<"No such Name Exists "<<endl;          
                                break;
                        case 5:
                                exit(0);
                        default:
                                cout<<"Invalid choice !!! ";
                                break;
                }
        } while (choice != 4);

        return 0;
}
