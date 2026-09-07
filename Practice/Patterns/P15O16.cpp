// Pattern 15 or 16

#include <iostream>
using namespace std;

int P15(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {        
         char Ch = 'A' + i + j - 2;
            cout << Ch << " ";
        }
        cout << endl;
    }
}

int P16(int n)
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
    P15(n);

    cout << endl;
    cout << endl;

    cout << "Second Pattern : " << endl;
    P16(n);
    return 0;
}