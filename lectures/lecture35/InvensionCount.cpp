// Invenstion  Using Recursion

// Recursion-Day 5

#include <iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int count = 0;

    int temp[right - left + 1];

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            // All remaining elements in left half
            // will form an inversion
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy sorted elements back
    for (int x = 0; x < k; x++)
        arr[left + x] = temp[x];

    return count;
}

int countInversion(int arr[], int left, int right)
{
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    int count = 0;

    count += countInversion(arr, left, mid);
    count += countInversion(arr, mid + 1, right);

    count += merge(arr, left, mid, right);

    return count;
}

int main()
{
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int inversions = countInversion(arr, 0, n - 1);

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}