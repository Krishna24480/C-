// InserTion Sort  Using Recursion

// Recursion-Day 4

#include <iostream>
using namespace std;

int printArr(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int arr[], int n)
{
}

int main()
{

    int arr[] = {8, 4, 5, 3, 5, 4, 2, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Sorted:" << endl;
    printArr(arr, n);

    InsertionSort(arr, n);
    cout << "Array After Sorted:" << endl;
    printArr(arr, n);
    return 0;
}