#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 99, 3, 4, 5, 6, 7, 8, 9, 10};

    char ch[6] = "abcde";

    char *ptr = &ch[0];

    cout << "Address of First Memory block is: " << arr << endl;

    cout << "Char array value: " << ch << endl;//same
    cout << "Char array value: " << ptr << endl;//same
    cout << "Char array value: " << &ch[0] << endl; // Same

    cout << "Address of First Memory block is: " << &ch << endl;

    cout << "Value Of First Memory block is: " << ptr[0] << endl;//Same
    cout << "Value Of First Memory block is: " << ch[0] << endl;//Same

    
    return 0;
}