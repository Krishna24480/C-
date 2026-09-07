// Sorted Array or Not Using Recursion

// Recursion-Day 3

#include <iostream>
using namespace std;

bool SortedAON(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool ans = SortedAON(arr + 1, n - 1);
        return ans;
    }
}

int main()
{
    int arr[] = {2, 4, 5, 6, 7, 8, 9,11,44};
    int n = sizeof(arr) / sizeof(arr[0]);

    bool ans = SortedAON(arr, n);

    cout << endl;

    if (ans == true)
    {
        cout << "Array is Sorted" << endl << endl;
    }
    else
    {
        cout << "Array is Not Sorted" << endl;
    }

    return 0;
}