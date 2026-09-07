// First and last Occurance in an array using BS

#include <iostream>
using namespace std;

int FirstOcc(int arr[], int n, int key)
{

    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }

        else if (key > arr[mid])
        {
            s = mid + 1;
        }

        else if (key < arr[mid])
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans; 
}

int LastOcc(int arr[], int n, int key)
{

    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }

        else if (key > arr[mid])
        {
            s = mid + 1;
        }

        else if (key < arr[mid])
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int even[11] = {1,1,2,2,3,3,3,4,4,5,5};
    int n = 11;
    int key;

    cout << "Enter The Key\n";
    cin >> key;

    int FO = FirstOcc(even, n, key);
    int LO = LastOcc(even, n, key);
    
    cout << "First occurrence of key is at Index: " << FO << endl;
    cout << "Last occurrence of key is at Index: " << LO << endl;

    return 0;
}