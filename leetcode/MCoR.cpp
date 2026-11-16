#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long minCost(long long arr[], long long n)
{

    // Create Min Heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    // Insert all rope lengths
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long cost = 0;

    // Connect ropes
    while (pq.size() > 1)
    {

        // Get two smallest ropes
        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        // Calculate cost
        long long sum = first + second;

        cost += sum;

        // Insert new rope
        pq.push(sum);
    }

    return cost;
}

int main()
{

    long long n;

    cout << "Enter number of ropes: ";
    cin >> n;

    long long arr[n];

    cout << "Enter rope lengths: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Minimum Cost = " << minCost(arr, n) << endl;

    return 0;
}