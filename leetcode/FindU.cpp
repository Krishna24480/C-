#include <iostream>
using namespace std;

int findUnique(int arr[], int n)
{
    int unique = 0;

    for (int i = 0; i < n; i++)
    {
        unique ^= arr[i];
    }

    return unique;
}

int main()
{
    int arr[] = {2, 3, 5, 3, 2};
    int n = 5;

    cout << findUnique(arr, n);

    return 0;
}