#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main()
{

    int arr[5] = {10, 20, 30, 40, 50};

    cout << arr[0] << endl;
    cout << arr[4] << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;

    int mx = arr[0];
    int mn = arr[0];

    for (int i = 1; i < 5; i++)
    {
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }

    cout << mx << endl;
    cout << mn << endl;

    int target = 30;

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == target)
        {
            cout << i << endl;
            break;
        }
    }

    reverse(arr, arr + 5);

    sort(arr, arr + 5);

    int arr2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.pop_back();

    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.empty() << endl;

    cout << v[0] << endl;
    cout << v.at(0) << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;

    v.push_back(40);
    v.push_back(50);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v.insert(v.begin() + 1, 15);

    v.erase(v.begin() + 1);

    v.resize(10);

    v.clear();

    v.reserve(100);

    vector<int> v1 = {5, 2, 8, 1, 9};

    sort(v1.begin(), v1.end());

    sort(v1.begin(), v1.end(), greater<int>());

    reverse(v1.begin(), v1.end());

    auto it = find(v1.begin(), v1.end(), 8);

    if (it != v1.end())
    {
        cout << "Found" << endl;
    }

    int countValue = count(v1.begin(), v1.end(), 8);
    cout << countValue << endl;

    vector<int> v2 = {1, 2, 3};
    vector<int> v3 = {10, 20};

    v2.swap(v3);

    for (auto it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = v2.rbegin(); it != v2.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> dynamicVector(5, 10);

    for (int x : dynamicVector)
    {
        cout << x << " ";
    }
    cout << endl;

    array<int, 5> a = {10, 20, 30, 40, 50};

    cout << a[0] << endl;
    cout << a.at(1) << endl;
    cout << a.front() << endl;
    cout << a.back() << endl;
    cout << a.size() << endl;

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    return 0;
}