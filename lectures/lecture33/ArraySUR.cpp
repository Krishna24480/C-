// Array Sum Using Recursion

// Recursion-Day 3

#include <iostream>
using namespace std;

int ArrayS(int arr[],int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }

    int sum = arr[0] + ArrayS(arr + 1, n - 1);
    return sum;

    // return arr[0] + ArrayS(arr + 1, n - 1); //Same
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = ArrayS(arr, n);

    cout << "Sum Of An Array is: " << sum << endl;
    return 0;
}