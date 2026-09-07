// Pattern 9 or 10

#include <iostream>
using namespace std;

int P9(int n)
{
    
    for (int i = 1; i <= n; i++)
    {
        int value = i;
        for (int j = 1; j <= i; j++)
        {
            cout << value<<" ";
            value++;
        }
        cout << endl;
    }
}

int P10(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i + j - 1 << " ";
            
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cout << "Enter The No : " << endl;
    cin >> n;

    cout << "First Pattern : " << endl;
    P9(n);

    cout << endl;
    cout << endl;

    cout << "Second Pattern : " << endl;
    P10(n);
    return 0;
}