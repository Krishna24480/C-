//Linear Search 

#include <iostream>
using namespace std;

int LinearSearch(int arr[], int key,int n)
{
    for (int i = 0; i < n; i++)
    {
       if (arr[i] == key)
       {
           return i;
       }
    }
    return -1;
}

int main()
{
    int arr[7] = {2,5,4,6,8,7,9};
    int n = 7;
    int key;

    cout << "Enter Your Key" << endl;
    cin >> key;

   int ans = LinearSearch(arr, key,n);

    if (ans != -1)
    {
        cout << "Key Present at array index : " << ans << endl;
    }
    else
    {
        cout << "Key is not present in array" << endl;
    }
   
    return 0;
} 