//Recursion-Day 1

#include<iostream>
using namespace std;

int factorial(int n){ 

if (n == 0)
{
    return 1;
}

int small = factorial(n - 1);
int big = n * small;

return big;

// return n * factorial(n-1);
}

int main(){

    int n;
    cout << "Enter The No.:" << endl;
    cin >> n;

   int ans = factorial(n);

  cout << "The Factorial of " << n << " is: " << ans << endl;
   return 0;
}