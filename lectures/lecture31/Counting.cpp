// Recursion-Day 1

#include <iostream>
using namespace std;

void counting(int n)
{
    if (n == 0)
        return;

    counting(n - 1);

    cout << n << endl;
}

int main()
{

    int n;
    cout << "Enter The No.:" << endl;
    cin >> n;
    cout << "Print Counting:" << endl;
    counting(n);

    return 0;
}