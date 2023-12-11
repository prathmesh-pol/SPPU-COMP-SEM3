#include <iostream>
#include <vector>

using namespace std;

// Defining Templete
template <typename T>

void sort_array(){

    // Taking Input
    int n;
    cout << "Enter number of items:";
    cin >> n;

    T arr[n];
    for (int i =0; i< n; i++) {
        cout << "Enter number:";
        cin >> arr[i];
    }


    // Selection sort Algorithm
    int min_idx;
 
    for (int i = 0; i < n-1; i++) {
        min_idx = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
 
        T temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    // Printing Sorted Array
    cout << "\nSorted array is:\n";

    for (auto x: arr){
        cout << x << " ";
    }
    cout << endl;
}

int main(){

    sort_array<int>();

    sort_array<float>();

    return 0;
}
