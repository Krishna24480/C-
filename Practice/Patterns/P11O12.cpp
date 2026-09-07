// Pattern 11 or 12

#include <iostream>
using namespace std;

int P11(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (i - j + 1) << " ";
          //  cout << i - j + 1 << " ";   Same
        }
        cout << endl;
    }
}

int P12(int n)
{

    char Ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << Ch<< " ";
        }
        Ch++;
        cout << endl;
    }
}

int main()
{

    int n;
    cout << "Enter The No : " << endl;
    cin >> n;

    cout << "First Pattern : " << endl;
    P11(n);

    cout << endl;
    cout << endl;

    cout << "Second Pattern : " << endl;
    P12(n);
    return 0;
}