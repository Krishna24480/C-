#include <iostream>
using namespace std;

int main()
{

    // ==============================
    // 1. BITWISE OPERATORS
    // ==============================

    int a = 5;
    int b = 3;

    cout << "BITWISE OPERATORS" << endl;

    cout << "AND (&)       : " << (a & b) << endl;
    cout << "OR (|)        : " << (a | b) << endl;
    cout << "XOR (^)       : " << (a ^ b) << endl;
    cout << "NOT (~)       : " << (~a) << endl;
    cout << "Left Shift    : " << (a << 1) << endl;
    cout << "Right Shift   : " << (a >> 1) << endl;

    // ==============================
    // 2. VARIABLE SCOPE
    // ==============================

    cout << "\nVARIABLE SCOPE" << endl;

    int x = 10;

    cout << "Outside block: " << x << endl;

    {
        int y = 20;

        cout << "Inside block x: " << x << endl;
        cout << "Inside block y: " << y << endl;
    }

    // y cannot be accessed here
    // cout << y;  // ERROR

    // ==============================
    // 3. FOR LOOP
    // ==============================

    cout << "\nFOR LOOP" << endl;

    // 1 to 5
    for (int i = 1; i <= 5; i++)
    {
        cout << i << " ";
    }

    cout << endl;

    // Even numbers
    for (int i = 2; i <= 10; i += 2)
    {
        cout << i << " ";
    }

    cout << endl;

    // Reverse
    for (int i = 5; i >= 1; i--)
    {
        cout << i << " ";
    }

    cout << endl;

    // ==============================
    // 4. BITWISE + FOR LOOP
    // ==============================

    int number = 5;

    for (int i = 0; i < 6; i++)
    {
        cout << number << " << " << i << " = " << (number << i) << endl;
    }

    return 0;
}