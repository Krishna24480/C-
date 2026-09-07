// Recursion-Day 1

#include <iostream>
using namespace std;

int pow2(int n)
{
    if (n == 0)
        return 1;

    return 2 * pow2(n - 1);

    //    //(
    //      int small = pow2(n - 1);
    //        int big = 2 * small;

    //      return big;   // )  Same
}

int main()
{

    int n;
    cout << "Enter The No.:" << endl;
    cin >> n;

    int ans = pow2(n);

    cout << "The " << n << "th Power of 2 is: " << ans << endl;
    return 0;
}