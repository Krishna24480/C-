#include <iostream>
using namespace std;

int FindUnique(int arr[],int size){

    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[7] = {2,3,1,1,3,6,2};

    int ans = FindUnique(arr, 7);

    cout << "The Unique No. In an Array is: " << ans << "\n";

    return 0;
}
