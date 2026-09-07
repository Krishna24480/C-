#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int choice, a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Result = " << add(a, b);
        break;

    case 2:
        cout << "Result = " << subtract(a, b);
        break;

    case 3:
        cout << "Result = " << multiply(a, b);
        break;

    default:
        cout << "Invalid choice";
    }

    return 0;
}