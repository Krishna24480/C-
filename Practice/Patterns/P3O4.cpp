// Pattern 3 or 4

#include <iostream>
using namespace std;

int P3(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

int P4(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << n-j+1;
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
    P3(n);

    cout << endl;
    cout << endl;
    
    cout << "Second Pattern : " << endl;
    P4(n);
    return 0;
}