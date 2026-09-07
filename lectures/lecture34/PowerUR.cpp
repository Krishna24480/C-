// A ki Power B Using Recursion

// Recursion-Day 4

#include <iostream>
using namespace std;

int Power(int a, int b)
{

    if (b == 0)
    {
        return 1;
    }

    if (b == 1)
    {
        return a;
    }

    int ans = Power(a, b / 2);

    if (b % 2 == 0)
    {
        return ans * ans;
    }

    else
    {
        return a * ans * ans;
    }
}

int main()
{
    int a;
    cout << "Enter First No." << endl;
    cin >> a;

    int b;
    cout << "Enter Second No." << endl;
    cin >> b;

    int ans = Power(a, b);

    cout<<a<<" ki Power "<<b<<" is: "<<ans<<endl;

    return 0;
}