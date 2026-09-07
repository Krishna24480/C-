#include <iostream>
using namespace std;

void RotateAatKP(int arr[], int n, int k)
{

    int temp[n];

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] =arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }  
}

void PrintArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()

{
    int arr[] = {1, 3, 7, 8, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;

    cout << "Enter The K Postion You want to Rotate Array\n";
    cin >> k;

    cout << "Array Brfore Rotate: \n";
    PrintArr(arr, n);

    cout << "Array After Rotate: \n";
    RotateAatKP(arr, n, k);
    PrintArr(arr, n);

    return 0;
}