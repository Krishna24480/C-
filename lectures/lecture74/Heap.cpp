#include <iostream>
#include<queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;

        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void DeleteFH()
    {
        if (size == 0)
        {
            cout << "Nothing to Delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;

        while (i <= size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            int largest = i;

            if (leftIndex <= size && arr[largest] < arr[leftIndex])
            {
                largest = leftIndex;
            }

            if (rightIndex <= size && arr[largest] < arr[rightIndex])
            {
                largest = rightIndex;
            }

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void HeapilyFyFMaH(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        HeapilyFyFMaH(arr, n, largest);
    }
}

void HeapilyFyFMiH(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }

    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        HeapilyFyFMiH(arr, n, smallest);
    }
}

void Print(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void HeapSortMaH(int arr[], int n)
{

    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        HeapilyFyFMaH(arr, size, 1);
    }
};

void HeapSortMiH(int arr[], int n)
{
    int i = 1;
    while (n > 1)
    {
        swap(arr[n], arr[i]);
        n--;
        i++;
        HeapilyFyFMaH(arr, n, i);    
    }
    
};

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int arr2[6] = {-1, 54, 53, 55, 52, 50};

    int n = 5;

    cout << "Printing the Array Before Convert into Max Heap:" << endl;
    Print(arr, n);

    for (int i = n / 2; i >= 1; i--)
    {
        HeapilyFyFMaH(arr, n + 1, i);
    }

    cout << "Printing the Array After Convert into Max Heap:" << endl;
    Print(arr, n);

    cout << "Printing the Array Before Convert into Min Heap:" << endl;
    Print(arr2, n);

    for (int i = n / 2; i >= 1; i--)
    {
        HeapilyFyFMiH(arr2, n + 1, i);
    }

    cout << "Printing the Array After Convert into Min Heap:" << endl;
    Print(arr2, n);

    cout << "Printing the Array After Sort:" << endl;
    HeapSortMaH(arr, n);
    Print(arr, n);

    cout << "Printing the Array2 After Sort:" << endl;
    HeapSortMiH(arr2, n);
    Print(arr2, n);

    cout << endl;

    cout << "Using Priority Queue Here:" << endl;
    cout << endl;

    cout << "Creating MaxHeap: " << endl;

    // Max Heap Defaul;
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Element At Top: " << pq.top() << endl;
    pq.pop();
    cout << "Element At Top: " << pq.top() << endl;
    cout << "Size is: " << pq.size() << endl;

    if (pq.empty()) 
    {
        cout << "PQ is Empty" << endl;
    }
    else
    {
        cout << "PQ is not Empty" << endl;
    }

    cout << endl;

    cout << "Creating MinHeap: " << endl;
    // Min Heap Craetion
    priority_queue<int, vector<int>, greater<int>>
        MinHeap;

    MinHeap.push(4);
    MinHeap.push(2);
    MinHeap.push(5);
    MinHeap.push(3);

    cout << "Element At Top: " << MinHeap.top() << endl;
    MinHeap.pop();
    cout << "Element At Top: " << MinHeap.top() << endl;
    cout << "Size is: " << MinHeap.size() << endl;
    if (MinHeap.empty())
    {
        cout << "MinHeap is Empty" << endl;
    }
    else
    {
        cout << "MinHeap is not Empty" << endl;
    }

    return 0;
}
