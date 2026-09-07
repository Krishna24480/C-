#include <iostream>
using namespace std;

void Reverse(int arr[], int n)
{
    int S = 0;
    int E = n-1;

    while (S<=E)
    {
        swap(arr[S], arr[E]);
        S++;
        E--;
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
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[2]);

    cout << "Array Before Reverse: \n";
    PrintArr(arr, n);

    cout << "Array After Reverse: \n";
    Reverse(arr, n);
    PrintArr(arr, n);

    return 0;
}