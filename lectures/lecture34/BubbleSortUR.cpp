// Bubble Sort  Using Recursion

// Recursion-Day 4

#include <iostream>
using namespace std;


int printArr(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int arr[],int n){

    if (n==0 || n == 1)
    {
        return;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i]>arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }   
    }

    BubbleSort(arr, n - 1);
}

int main(){

    int arr[] = {8, 4, 5, 3, 5, 4, 2, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Sorted:" << endl;
    printArr(arr, n);

    BubbleSort(arr, n);
    cout << "Array After Sorted:" << endl;
    printArr(arr, n);
    return 0;
}