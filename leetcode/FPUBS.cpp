#include <iostream>
using namespace std;

int findPivot(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] > arr[end])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 1, 2, 3};
    int n = 7;

    cout << "Pivot Index: " << findPivot(arr, n) << endl;
    cout << "Pivot Element: " << arr[findPivot(arr, n)] << endl;

    return 0;
}