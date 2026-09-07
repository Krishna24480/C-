#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 99, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = arr;
    int i = 4;
    int k;
    cout << "Address of First Memory block is: " << arr << endl;  // Same
    cout << "Address of First Memory block is: " << ptr << endl; //Same
    cout << "Address of First Memory block is: " << &arr[0] << endl; // Same
    cout << "Address of First Memory block is: " << &arr << endl;    // Same;

    cout << "First Memory block Value is: " << arr[0] << endl;// Same
    cout << "First Memory block Value is: " << *arr << endl;     // Same
    cout << "First Memory block Value is: " << *ptr << endl;     // Same
    cout << "First Memory block Value is: " << *&arr[0] << endl; // Same

    cout << "Address of second Memory block is: " << arr + 1 << endl; // Same
    cout << "Address of second Memory block is: " << ptr + 1 << endl; // Same

    cout << "Address of third Memory block is: " << arr + 2 << endl; // Same
    cout << "Address of third Memory block is: " << ptr + 2 << endl; // Same

    cout << "Second Memory block Value is: " << *(arr + 1) << endl; // Same
    cout << "Second Memory block Value is: " << *(ptr + 1) << endl; // Same

    cout << "Third Memory block Value is: " << *(arr + 2) << endl;//Same
    cout << "Third Memory block Value is: " << *(ptr + 2) << endl;//Same

    cout << "Fifth Memory block Value is: " << i[arr] << endl;//5,Same
    cout << "Fifth Memory block Value is: " << arr[i] << endl;//5,Same

    cout << "Enter The Block no. of Array: \n";
    cin >> k;

    cout << k+1 << "th Block Value of an array: " << arr[k]<<endl;//same
    cout << k+1 << "th Block Value of an array: " << k[arr] << endl;//same

    cout <<"Size Of an Array is: "<< sizeof(arr) <<endl;//40 , 4*10
    cout << "Size Of an Array's Pointer is: " << sizeof(ptr) << endl; //4,32 bit
  
    return 0;
}