// Reverse The Array

#include <iostream>
using namespace std;

void Reverse(int arr[], int n)
{

    int m = 0;
    int s = n - 1;

    while (s > m)
    {
        swap(arr[m], arr[s]);
        m++;
        s--;
    }
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    Reverse(arr, n);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}