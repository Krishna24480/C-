// Pattern 7 or 8

#include <iostream>
using namespace std;

int P7(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int P8(int n)
{
    int count = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << count << " ";
            count++;
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
    P7(n);

    cout << endl;
    cout << endl;

    cout << "Second Pattern : " << endl;
    P8(n);
    return 0;
}