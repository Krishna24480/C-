// Move Zero in Right Side

#include <iostream>
using namespace std;

void MZ(int arr[],int n){

    int nonZero = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonZero]);
            nonZero++;
        }       
    }
}

void PrintArr(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {2,3,0,3,0,2,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Move Zero\n";
    PrintArr(arr, n);

    cout << "Array After Move Zero\n";
    MZ(arr, n);
    PrintArr(arr, n);

    return 0;
}
