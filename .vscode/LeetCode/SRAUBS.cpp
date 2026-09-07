#include <iostream>
using namespace std;

int search(int arr[], int n, int key)
{
    int S = 0;
    int E = n - 1;

    while (S <= E)
    {
        int mid = S + (E - S) / 2;

        if (arr[mid] == key)
            return mid;

        // Left half is sorted
        if (arr[S] <= arr[mid])
        {
            if (arr[S] <= key && key < arr[mid])
                E = mid - 1;
            else
                S = mid + 1;
        }

        // Right half is sorted
        else
        {
            if (arr[mid] < key && key <= arr[E])
                S = mid + 1;
            else
                E = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    int key = 0;

    int position = search(arr, n, key);

    if (position != -1)
        cout << "Key found at index: " << position << endl;
    else
        cout << "Key not found" << endl;

    return 0;
}