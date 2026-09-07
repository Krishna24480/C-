#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// 1. O(1) — CONSTANT TIME
// ============================================================

void constantTime(int n)
{
    cout << n << endl;
}

// ============================================================
// 2. O(n) — LINEAR TIME
// ============================================================

void linearTime(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
}

// ============================================================
// 3. O(n) — LINEAR SPACE
// ============================================================

void linearSpace(int n)
{
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

// ============================================================
// 4. O(n²) — QUADRATIC TIME
// ============================================================

void quadraticTime(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << i << " " << j << endl;
        }
    }
}

// ============================================================
// 5. O(n²) — QUADRATIC SPACE
// ============================================================

void quadraticSpace(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

// ============================================================
// 6. O(log n) — LOGARITHMIC TIME
// ============================================================

void logarithmicTime(int n)
{
    while (n > 1)
    {
        n = n / 2;
    }
}

// ============================================================
// 7. O(n log n) — LINEARITHMIC TIME
// ============================================================

void nLogN(int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = n;

        while (x > 1)
        {
            x = x / 2;
        }
    }
}

// ============================================================
// 8. O(1) SPACE
// ============================================================

int constantSpace(int n)
{
    int a = 10;
    int b = 20;

    return a + b + n;
}

// ============================================================
// 9. O(n) SPACE
// ============================================================

void arraySpace(int n)
{
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    delete[] arr;
}

// ============================================================
// 10. RECURSION — O(n) TIME AND O(n) SPACE
// ============================================================

void recursion(int n)
{
    if (n <= 0)
        return;

    recursion(n - 1);
}

// ============================================================
// 11. BINARY SEARCH — O(log n) TIME, O(1) SPACE
// ============================================================

int binarySearch(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// ============================================================
// 12. LINEAR SEARCH — O(n) TIME, O(1) SPACE
// ============================================================

int linearSearch(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

// ============================================================
// 13. FACTORIAL RECURSION
// O(n) TIME
// O(n) SPACE because of recursion stack
// ============================================================

long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

// ============================================================
// 14. FIBONACCI — O(2^n) TIME
// O(n) SPACE because of recursion stack
// ============================================================

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// ============================================================
// 15. TWO NESTED LOOPS — O(n²) TIME
// ============================================================

void nestedLoops(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

// ============================================================
// 16. THREE NESTED LOOPS — O(n³) TIME
// ============================================================

void threeNestedLoops(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << i << j << k << endl;
            }
        }
    }
}

// ============================================================
// 17. TWO SEPARATE LOOPS — O(n) TIME
// ============================================================

void separateLoops(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }

    for (int j = 0; j < n; j++)
    {
        cout << j << " ";
    }
}

// ============================================================
// 18. LOOP + NESTED LOOP — O(n²) TIME
// ============================================================

void mixedLoops(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << i << j << endl;
        }
    }
}

// ============================================================
// MAIN
// ============================================================

int main()
{
    int n = 10;

    constantTime(n);

    linearTime(n);

    linearSpace(n);

    quadraticTime(n);

    quadraticSpace(n);

    logarithmicTime(n);

    nLogN(n);

    constantSpace(n);

    arraySpace(n);

    recursion(n);

    vector<int> arr = {1, 2, 3, 4, 5};

    binarySearch(arr, 3);

    linearSearch(arr, 3);

    factorial(5);

    fibonacci(5);

    nestedLoops(n);

    threeNestedLoops(n);

    separateLoops(n);

    mixedLoops(n);

    return 0;
}