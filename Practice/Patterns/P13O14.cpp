// Pattern 13 or 14

#include <iostream>
using namespace std;

int P13(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {        
         char Ch = 'A' + j - 1;
            cout << Ch << " ";
        }
        cout << endl;
    }
}

int P14(int n)
{
    char Ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << Ch << " ";
        }
        Ch = Ch + 1;
        cout << endl;
    }
}

int main()
{

    int n;
    cout << "Enter The No : " << endl;
    cin >> n;

    cout << "First Pattern : " << endl;
    P13(n);

    cout << endl;
    cout << endl;

    cout << "Second Pattern : " << endl;
    P14(n);
    return 0;
}