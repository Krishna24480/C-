// Bubble Sort using vector

#include <iostream>
#include <vector>
using namespace std;

void BubbleS(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

//Both Functions are Right Just Coding Type is Diiferent
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int swapped = false;
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }     
        }

        if (swapped == false)
        {
            break;
        }
    }
    
}

void PrintArr(vector<int> &arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
   vector<int> arr = {10, 3, 21, 455, -6, 33, 268619, 3, 66};
    //  int arr[] = {1, 7, 9, 2, 3, 0};
    int n = arr.size();

    cout << "InSorted Array: \n";
    PrintArr(arr, n);

   //BubbleS(arr, n); //Both are Same and Right Use any of them
   bubbleSort(arr, n);

    cout << endl;

    cout << "Sorted Array: \n";
    PrintArr(arr, n);
    return 0;
}