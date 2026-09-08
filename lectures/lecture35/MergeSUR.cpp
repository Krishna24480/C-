// Merge Sort  Using Recursion

// Recursion-Day 5

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

void Merge(int arr[], int s, int e)
{

    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge2 Sorted Arrays
    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void MergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // Left Side
    MergeSort(arr, s, mid);

    // Right Side
    MergeSort(arr, mid + 1, e);

    // Merge Arrays
    Merge(arr, s, e);
}

int main()
{

    int arr[] = {8, 4, 5, 3, 5, 4, 2, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = n - 1;

    cout << "Array Before Sorted:" << endl;
    printArr(arr, n);

    MergeSort(arr, s, e);
    cout << "Array After Sorted:" << endl;
    printArr(arr, n);
    return 0;
}