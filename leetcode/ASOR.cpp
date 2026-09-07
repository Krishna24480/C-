#include <iostream>
using namespace std;

bool ASOR(int arr[], int n)
{
    int count = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i-1]>arr[i])
        {
            count++;
        }      
    }

    if (arr[n-1] > arr[0])
    {
        count++;
    }
    return count <= 1;
}

int main(){
    int arr[] = {1, 3, 7, 8, 9, 11};
    int arr1[] = {7,8,9,11,1,3};
    int arr2[] = {1,4,5,3,4,2,5,3,7,2};
    int n = sizeof(arr) / sizeof(arr[0]);

if (ASOR(arr2,n))
{
    cout << "Array is Sortrd Or Rotated \n";
}
else{
    cout << "Not Array is Sortrd Or Rotated \n";
}
    return 0;
}