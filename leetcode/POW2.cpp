#include <iostream>
#include <math.h>
using namespace std;

bool IsPow2(int n)
{

 for (int i = 0; i <= 30; i++) //use n in place of 30 is also working
 {
     int ans = pow(2, i);
     
     if (ans == n)
     {
        return true;
     }   
 }
 return false;
}

int main()
{

    int n;
    cout << "Enter The Value : \n";
    cin >> n;

    int ans = IsPow2(n);

    if (ans == true)
    {
        cout << n << " is in Power of 2\n";
    }
    else
    {
        cout << n << " is Not in Power of 2\n";
    }
    
    
    return 0;
}