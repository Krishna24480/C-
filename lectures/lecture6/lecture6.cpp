#include <iostream>
#include <math.h>
using namespace std;

// Covert Decimal into Binary
int DiB(int n)
{
    int i = 0;
    int ans = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;

        n = n >> 1;
        i++;
    }
    return ans;
}

//Convert Binary into Decimal 
int BiD(int m){
    int i = 0, ans = 0;
    while (m != 0)
    {
        int digit = m % 10;

        if (digit == 1)
        {
            ans = ans + pow(2, i);
        }
        m = m / 10;
        i++;
    }

    return ans;
}

int main()
{
    cout << "How to convert Decimal Into Binary \n";
    cout << "Step 1: Divide By 2 \n";
    cout << "Step 2: Store Remender in Answer \n";
    cout << "Step 3:Repeat Until n=! 0 \n";
    cout << "Step 4:Reverse Answer That was Your Remender\n";

    int n;
    cout << "Enter The Value \n";
    cin >> n;

    int ans = DiB(n);

    cout << "Binary Number of The Decimal number  is : " << ans << endl;

    int m;
    cout << "Enter The Value \n";
    cin >> m;

    int answer = BiD(m);
    cout << "Decimal Number of The Binary number is : " << answer << endl;
    return 0;
}