#include <iostream>
using namespace std;

void PrintArr(int arr[], int size){

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void SwapAlternate(int arr[], int size){

    for (int i = 0; i < size; i+=2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }       
    }  
}

int main()
{
    int even[8] = {5, 2, 9, 4, 7, 6, 1, 0};
    int odd[5] = {11,33,9,76,43};

    cout << "Before Swap: " << endl;
    PrintArr(even, 8);

    cout << "After Swap: " << endl;
    SwapAlternate(even, 8);
    PrintArr(even, 8);

    cout << endl;

    cout << "Before Swap: " << endl;
    PrintArr(odd, 5);

    cout << "After Swap: " << endl;
    SwapAlternate(odd, 5);
    PrintArr(odd, 5);
    
    return 0;
}