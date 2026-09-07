#include <iostream>
using namespace std;

int findRootIndex(int arr[], int size, int n)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // arr[mid] is the possible root
        long long square = 1LL * arr[mid] * arr[mid];

        if (square == n)
        {
            return mid; // Root found
        }
        else if (square < n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Root not found
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int n;
    cout << "Enter number: ";
    cin >> n;

    int index = findRootIndex(arr, size, n);

    if (index != -1)
        cout << "Root exists at index: " << index << endl;
    else
        cout << "Root does not exist in the array." << endl;

    return 0;
}