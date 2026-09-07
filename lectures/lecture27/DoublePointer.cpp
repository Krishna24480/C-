#include <iostream>
using namespace std;

void update(int** p)
{

    // p = p + 1; //No Change

   //*p = *p + 1; Change ptr address

    **p = **p + 1; //Change value + 1
}

int main()
{

    int value = 484;
    int* ptr = &value;
    int** p = &ptr;

    cout << &value << endl; // Same
    cout << ptr << endl; // Same
    cout << *p << endl; //Same

    cout << endl;

    cout << value << endl;    // Same
    cout << *ptr << endl; // Same
    cout << **p << endl;     // Same

    cout << endl;

    cout << &ptr << endl; // Same
    cout << *p << endl;  // Same

    cout << "Before: " << value << endl;
    cout << "Before: " << ptr << endl;
    cout << "Before: " << p << endl;

    update(p);

    cout << "After: " << value << endl;
    cout << "After: " << ptr << endl;
    cout << "After: " << p << endl;

    return 0;
}