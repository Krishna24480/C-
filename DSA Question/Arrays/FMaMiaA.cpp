// Find Maximum and Minimum Value in an Array

#include <iostream>
using namespace std;

int MaxValue(int arr[], int n)
{
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int MinValue(int arr[], int n)
{

    int min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

pair<int, int> MinMax(int arr[], int n)
{
    int min = MinValue(arr, n);
    int max = MaxValue(arr, n);

    pair<int, int> p = make_pair(min, max);
    return p;
}

int main()
{
    int arr[] = {33, 6, 12, 32, 44, 555, 6374748, 182737};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> p = MinMax(arr, n);

    int min = p.first;
    int max = p.second;

    cout << "MiniMum Value in an Array is: " << min << endl;
    cout << "MaxiMum Value in an Array is: " << max << endl;

    return 0;
}
