#include <bits/stdc++.h>
using namespace std;

class file_handle
{
    fstream doc;
    public:

    void create_file()
    {
        doc.open("file_handle.txt", ios::out);

        if (!doc)
        {
            cout << "Error !!! " << endl;
        }
        else
        {
            cout << "File Created Successfully " << endl;
            doc.close();
        }
    }

    void write_file()
    {

        doc.open("file_handle.txt", ios::out);
        string data;
        cout << "Enter data : ";
        getline(cin, data);
        doc << data;
        cout << "Data Entered Successfully " << endl;
        doc.close();
    }

    void read_file()
    {

        cout << "\nReading the file : ";
        doc.open("file_handle.txt", ios::in);
        string x;
        while (doc >> x)
        {
            cout << x << " ";
        }
    }
};

int main()
{
    file_handle doc;
    doc.create_file();
    doc.write_file();
    doc.read_file();
}