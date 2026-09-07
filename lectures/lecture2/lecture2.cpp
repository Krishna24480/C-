#include <iostream>
using namespace std;

int main()
{

    int a = 123;
    cout << a << endl;

    char b = 'v'; //118 in ascii table
    cout << b << endl;

    bool bl = true;
    cout << bl << endl;

    float f = 1.2;
    cout << f << endl;

    double d = 1.23;
    cout << d << endl;

    int size = sizeof(b);
    cout << "Size of a is: " << size << endl;

    unsigned int u = 122; //store positive no. only 
    cout << u << endl;

    signed int s = -122; //store positive and negetive both the int that we use normally
    cout << s << endl;

    // module operator = %;
    // arthmetic operators = +,-,*,/;
    // relational operators = =,<,>,>=,<=,!= ;
    // logical operators = &&,||,!;

    cout << "Hello World" << endl;
    return 0;
}

// compilation
// first program "Hello World"
// Line
// Data types & Variables
// postive & negative No. ,Signed and unsigned
// Operators = module , arthmetic, relational ,logical