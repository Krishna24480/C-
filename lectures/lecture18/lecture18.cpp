// Insertion Sort

#include <iostream>
using namespace std;

void InsertionS(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j>=0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PrintArr(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {10, 3, 21, 455, -6, 33, 268619, 3, 66};
    //  int arr[] = {1, 7, 9, 2, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "InSorted Array: \n";
    PrintArr(arr, n);

    InsertionS(arr, n);

    cout << endl;

    cout << "Sorted Array: \n";
    PrintArr(arr, n);
    return 0;
}