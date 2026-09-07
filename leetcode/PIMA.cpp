#include <iostream>
using namespace std;

int peakIndex(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            // We are in the increasing part
            start = mid + 1;
        }
        else
        {
            // We are in the decreasing part
            end = mid;
        }
    }

    return start;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 6, 4, 2};
    int n = 7;

    cout << "Peak Index: " << peakIndex(arr, n);

    return 0;
}