// Binary Search Using Recursion

// Recursion-Day 3

#include <iostream>
using namespace std;

bool BinaryS(int arr[], int s, int e, int key)
{
    int mid = s + (e - s) / 2;
    
    if (s > e)
        return false;

    if (arr[mid] == key)
        return true;

    if (arr[mid] < key)
    {
        return BinaryS(arr, mid + 1, e, key);
    }
    else
    {
        return BinaryS(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[] = {2, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter Your Key" << endl;
    cin >> key;

    int ans = BinaryS(arr, 0, n - 1, key);

    if (ans == true )
    {
        cout << "Key Present in array" << endl;
    }
    else
    {
        cout << "Key is not present in array" << endl;
    }

    return 0;
}