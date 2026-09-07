//Check The Num Prime Or Not For Numbers
#include <iostream>
using namespace std;

int PoN(int n)
{

    for (int i = 2; i < n ; i++)
    {
        if (n % i > 0)
        {
            cout << "Prime For " << i << endl;
        }
        else
        {
            cout << "Not Prime For : " << i << endl;
        }
    }
}

int main (){

    int n;
    cout << "Enter The No : " << endl;
    cin >> n;

     PoN(n);
    return 0;
}