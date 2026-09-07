//Painter Partition Problem

#include <iostream>
using namespace std;

bool Ispossible(int arr[], int n, int m, int mid)
{
    int Painters = 1;
    int Paint = 0;

    for (int i = 0; i < n; i++)
    {
        if (Paint + arr[i] <= mid)
        {
            Paint = Paint + arr[i];
        }
        else
        {
            Painters++;
            if (Painters > m || arr[i] > mid)
            {
                return false;
            }
            Paint = arr[i];
        }
    }
    return true;
}

int PPP(int arr[],int n,int m){
    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (Ispossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[4] = {5,5,5,5};
    int n = 4;
    int m = 2;

    int ans = PPP(arr,n,m);

    cout << "Given Board for each Painter is: " << ans << endl;
    return 0;
}