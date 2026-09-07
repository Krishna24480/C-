#include <iostream>
using namespace std;

void PrintArr(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void MSA(int arr1[],int n,int arr2[],int m,int arr3[]){

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m)
    {
        if (arr1[i]<arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }      
    }

    while (i<n)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

int main()
{
    int even[5] = {2,4,6,8,10};
    int odd[5] = {1,3,5,7,9};

    int Numbers[10] = {0};

    MSA(even, 5, odd, 5, Numbers);
    PrintArr(Numbers, 10);

    return 0;
}
