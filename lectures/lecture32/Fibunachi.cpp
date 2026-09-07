// Fibunachi Series Using Recursion

// Recursion-Day 2

#include <iostream>
using namespace std;

int Fibunachi(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    // int ans = Fibunachi(n - 1) + Fibunachi(n - 2);
    // return ans;

    return Fibunachi(n - 1) + Fibunachi(n - 2); // Same
}

int main()
{
    int n;
    cout << "Enter The No.:" << endl;
    cin >> n;

    int ans = Fibunachi(n);

    cout << "The " << n << "th No. of Fubunachi Series is: " << ans << endl;
    return 0;
}