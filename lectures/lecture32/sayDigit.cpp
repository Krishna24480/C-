// Recursion-Day 2

#include <iostream>
using namespace std;

void SayDigit(int n,string arr[])
{
    if (n == 0)
        return;

    int Digit = n % 10;
    n = n / 10;

    SayDigit(n, arr);

    cout << arr[Digit] << " ";

}

int main()
{
    string arr[10] = {"zero", "one", "two", "three","four","five","six","seven","eight","nine"};
    int n;
    cout << "Enter The No.:" << endl;
    cin >> n;

    cout << endl;
    SayDigit(n,arr);
    cout << endl;

    return 0;
}