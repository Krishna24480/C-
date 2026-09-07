// Selection Sort

#include <iostream>
using namespace std;

void SelecS(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int miniIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[miniIndex])
            {
                miniIndex = j;
            }
        }
        swap(arr[miniIndex], arr[i]);
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

    SelecS(arr, n);

    cout << endl;

    cout << "Sorted Array: \n";
    PrintArr(arr, n);
    return 0;
}