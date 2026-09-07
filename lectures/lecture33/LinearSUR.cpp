// Linear Search Using Recursion

// Recursion-Day 3

#include <iostream>
using namespace std;

int LinearS(int arr[], int key, int n)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else{
        return LinearS(arr + 1, key, n - 1);
    }    
}

int main()
{
    int arr[] = {2, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;

    cout << "Enter Your Key" << endl;
    cin >> key;

    int ans = LinearS(arr, key, n);

    if (ans == true)
    {
        cout << "Key Present in array" << endl;
    }
    else
    {
        cout << "Key is not present in array" << endl;
    }
    return 0;
}