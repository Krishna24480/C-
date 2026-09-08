// Quick Sort  Using Recursion

// Recursion-Day 6

#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part smbhal lete h
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{

    // base case
    if (s >= e)
        return;

    // partitioon karenfe
    int p = partition(arr, s, e);

    // left part sort karo
    quickSort(arr, s, p - 1);

    // right wala part sort karo
    quickSort(arr, p + 1, e);
}

int printArr(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {8, 4, 5, 3, 5, 4, 2, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = n - 1;

    cout << "Array Before Sorted:" << endl;
    printArr(arr, n);

    quickSort(arr, s, e);
    cout << "Array After Sorted:" << endl;
    printArr(arr, n);
    return 0;
}