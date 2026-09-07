// Binary Search

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int key, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int arr[7] = {2, 4, 5, 6, 7, 8, 9};
    int n = 7;
    int key;

    cout << "Enter Your Key" << endl;
    cin >> key;

    int ans = BinarySearch(arr, key, n);

    if (ans != -1)
    {
        cout << "Key Present at array index : " << ans << endl;
    }
    else
    {
        cout << "Key is not present in array" << endl;
    }

    return 0;
}