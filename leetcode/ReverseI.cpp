#include <iostream>
#include <limits.h>
using namespace std;

int ReverseI(int n)
{

    int answer = 0;

    while (n != 0)
    {
        int rem = n % 10;

        if(answer > INT_MAX /10 || answer < INT_MIN/10){
            return 0;
        }
        answer = answer * 10 + rem;
        n = n / 10;
    }
    return answer;
}

int main()
{

    int n;
    cout << "Enter The Value : \n";
    cin >> n;

    int ans = ReverseI(n);

    cout << "The Reverse of " << n << " is : " << ans << endl;
    return 0;
}