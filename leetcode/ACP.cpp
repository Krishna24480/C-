#include <bits/stdc++.h>
using namespace std;

bool canPlace(int stalls[], int n, int cows, int minDist)
{
    int count = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPos >= minDist)
        {
            count++;
            lastPos = stalls[i];

            if (count >= cows)
                return true;
        }
    }

    return false;
}

int aggressiveCows(int stalls[], int n, int cows)
{
    sort(stalls, stalls + n);

    int low = 0;
    int high = stalls[n - 1] - stalls[0];
    int answer = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, n, cows, mid))
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return answer;
}

int main()
{
    int stalls[] = {1, 2, 4, 8, 9};
    int n = 5;
    int cows = 3;

    cout << aggressiveCows(stalls, n, cows);

    return 0;
}