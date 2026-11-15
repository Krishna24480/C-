#include <iostream>
#include<queue>
using namespace std;

int kthSamllest(int arr[],int l,int r,int k){
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i <= r; i++)
    {
        if (arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }  
    }
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[] = {7, 10, 4, 20, 15};
    int r = sizeof(arr) / sizeof(arr[0]);

    int k;
    cout << "Enter The Value of K:" << endl;
    cin >> k;

    int l = 7;

    int ans = kthSamllest(arr, l, r, k);
    cout << k << "th Smallest Element in an Array is: "<<ans<< endl;

    return 0;
}