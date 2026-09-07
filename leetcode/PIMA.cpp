#include <iostream>
using namespace std;

int PIMA(int arr[], int n)
{

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return mid;
    // return start;
    // return end ;  // All have same and right Answer;
}

int main()
{

    int even[8] = {1, 3, 5, 6, 7, 4, 3, 1};
    int n = 8;

    int ans = PIMA(even, n);

    cout << "Peak Index in an Mountain Array Is: " << ans << endl;
    return 0;
}