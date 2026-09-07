#include <iostream>
using namespace std;

void swapAlternate(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, size);

    swapAlternate(arr, size);

    cout << "Swapped Array:  ";
    printArray(arr, size);

    return 0;
}