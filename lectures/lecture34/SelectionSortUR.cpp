//  Selection Sort  Using Recursion

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

void SelectionSort(int arr[], int n, int index = 0)
{
    if (index >= n - 1)
        return;

    int minIndex = index;

    for (int i = index + 1; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    swap(arr[index], arr[minIndex]);

    SelectionSort(arr, n, index + 1);
}

int main()
{

    int arr[] = {8, 4, 5, 3, 5, 4, 2, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Sorted:" << endl;
    printArr(arr, n);

    SelectionSort(arr, n);
    cout << "Array After Sorted:" << endl;
    printArr(arr, n);
    return 0;
}