#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, key = 0, search = 0;
    cout << "Enter number of students:" << endl;
    cin >> n;

    int arr[n], b[n + 1], srr[n];
    cout << "Enter Roll number of students:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b[i] = arr[i];
        srr[i] = arr[i];
    }
    sort(srr, srr + n);

    cout << "0: Exit\n";
    cout << "1: Linear Search\n";
    cout << "2: Sentinel Search\n";
    cout << "3: Binary Search\n";
    cout << "4: Fibonacci Search\n";

    cout << "Search Method: ";
    cin >> search;

    
    while (search != 0)
    {
        cout << "Enter key: ";
        cin >> key;

        if (search == 1)
        {
            cout << "------------LINEAR SEARCH------------\n";
            bool f = 0;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (key == arr[i])
                {

                    cout << "Attend training session\n"
                         << "Position: " << i + 1 << " " << endl;
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                cout << "Not Attend training session" << endl;
            }
        }
        else if (search == 2)
        {
            // Sentinel search
            cout << "------------SENTINEL SEARCH------------\n";
            int ans = 0;
            b[n] = key;
            int j = 0;
            while (b[j] != b[n])
            {
                j++;
                ans = j;
            }
            if (j < n)
            {
                cout << "Attended training session\n"
                     << "Position: " << ans + 1 << " " << endl;
            }
            else
            {
                cout << "Not Attended training session" << endl;
            }
        }
        else if (search == 3)
        {
            cout << "------------BINARY SEARCH------------\n";

            int index = -1;

            int s = 0, l = n - 1;
            int mid;
            while (s <= l)
            {
                mid = (s + l) / 2;
                if (srr[mid] == key)
                {
                    index = mid;
                    break;
                }
                else if (srr[mid] < key)
                {
                    s = mid + 1;
                }
                else
                {
                    l = mid - 1;
                }
            }

            if (index == -1)
            {
                cout << "Not Attended training session" << endl;
            }
            else
            {
                cout << "Attended training session" << endl;
            }
        }
        else if (search == 4)
        {
            cout << "------------FIBONACCI SEARCH------------\n";
            int m2 = 0, m1 = 1, m = 0, offset = 0, i = 0;

            while (m < n)
            {
                m2 = m1;
                m1 = m;
                m = m2 + m1;
            }

            bool f = 0;
            cout << "M2"
                 << "  "
                 << "M1"
                 << "  "
                 << "M"
                 << "  "
                 << "Offset"
                 << " "
                 << "i"
                 << " "
                 << "arr[i]" << endl;
            while (m != 1)
            {
                i = min(offset + m2, n - 1);
                cout << m2 << "   " << m1 << "  " << m << "   " << offset << "   " << i << "   " << arr[i - 1] << endl;
                if (srr[i] == key)
                {
                    cout << "Attended training session\n"
                         << "Position: " << i+1 << " " << endl;
                    f = 1;
                    break;
                }
                else if (srr[i] < key)
                {
                    m = m1;
                    m1 = m2;
                    m2 = m - m1;
                    offset = i;
                    i = offset + m2;
                }
                else
                {
                    m = m2;
                    m1 = m1 - m2;
                    m2 = m - m1;
                    i = offset + m2;
                }
            }
            if (m == 1)
            {
                cout << m2 << "   " << m1 << "  " << m << "   " << offset << "   " << i << "   " << arr[i - 1] << endl;
            }
            if (f == 0)
                cout << "Not Attended training session" << endl;
        }
        cout << "Search Method: ";
        cin >> search;
    
    }
}
