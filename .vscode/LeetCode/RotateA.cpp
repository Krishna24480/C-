#include <iostream>
using namespace std;

int RotateA(int arr[],int n, int k){

    int temp;

    for (int i = 0; i < k; i++)
    {
        temp= arr[0];
        for (int j = 0; j < n-1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
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

    cout << "Enter The no. You want to Rotate Array\n";
    cin >> k;

    cout << "Array Brfore Rotate: \n";
    PrintArr(arr, n);

    cout << "Array After Rotate: \n";
    RotateA(arr, n,k);
    PrintArr(arr, n);

    return 0;
}