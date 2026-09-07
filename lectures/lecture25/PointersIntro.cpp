#include <iostream>
using namespace std;

int main()
{  
    int num = 5; //integer
    int *ptr = &num; //pointer of integer
    int *qtr = &num; //Second Poinrt of integer 
    int **p = &ptr;// pointer of integer's pointer
    char ch = 'a';
    char *cch = &ch;// use same datatype in a pointer as a variabale

    cout<< ptr << endl; //integer address by pointer
    cout << qtr << endl;  // integer address by second pointer 
    cout << &num << endl; // integer address by address of operator(&)
    cout << *ptr << endl; //value of integer by dreffrence operator(*)
    cout << num << endl;  // value of integer
    cout << &ptr << endl; // integer's pointer address by address of operator(&)
    cout<< p << endl; // address of integer's pointer by integer's pointer pointer
    cout<< **p << endl; // value of integer by integer's pointer pointer
    cout << *p << endl; // integer address by integer's pointer pointer

    (*ptr)++; //increament operator by pointer
    cout << num << endl;
    num++; // increament operator by value
    cout << num << endl;

    // *ptr++;  // Don't use increament operator by pointer like this 
    // cout << *ptr << endl; if you use like this than your pointer point to a random garbage value

    cout << ch << endl;
    cout << *cch << endl;

    cout << &ch << endl;
    cout << cch << endl;

    cout << sizeof(num) << endl; //Size of integer
    cout << sizeof(ptr) << endl; // Size of integer'pointer
    cout << sizeof(p) << endl; // Size of integer'pointer pointer
    

    cout << sizeof(void*) << endl; //In 32 bit(my compiler) sizeof a pointer is 4 byte
    // And in 64 bit sizeof a pointer is 8 byte
    return 0;
}