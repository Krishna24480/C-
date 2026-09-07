#include <iostream>
using namespace std;

int searchRotated(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Target found
        if (arr[mid] == target)
        {
            return mid;
        }

        // Left half is sorted
        if (arr[start] <= arr[mid])
        {

            // Target lies in left sorted half
            if (arr[start] <= target && target < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        // Right half is sorted
        else
        {

            // Target lies in right sorted half
            if (arr[mid] < target && target <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;
    int target = 0;

    cout << "Index: " << searchRotated(arr, n, target);

    return 0;
}