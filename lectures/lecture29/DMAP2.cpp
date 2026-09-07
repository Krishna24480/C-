// Dynamic Memory Alloction Part-02

#include <iostream>
using namespace std;

int main()
{
    int *arr1D = new int[7]; // 1D array;
    
    //(
    int row;
    int col;
    cout << "Taking input for How Many size of 2D array\n";
    cin >> row;
    cin >> col;

    cout << "Creating 2D array\n";
    int **arr = new int *[row];

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    //) 2D Array

    // Input in 2D Array
    cout << "Taking input for 2D array\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    // Printing 2D Array

    cout << "Printing 2D array\n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Relese Memory
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    cout << "Thats How You Create 2D Array Dynamically and take,print, relese Memory" << endl;
    return 0;
}