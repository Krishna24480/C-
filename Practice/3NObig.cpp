//Give you three diffrent no. a,b,c 
//Find which no. is the Largest 

#include <iostream>
using namespace std;

int threeNObig(int a, int b, int c)
{

    if (a > b && a > c)
    {
        cout << "a" << endl;
    }
    else if (b > c)
    {
        cout << "b" << endl;
    }
    else
    {
        cout << "c" << endl;
    }
}

int main()
{
    int a;
    int b;
    int c;

    cout << "Enter the value of a" << endl;
    cin >> a;

    cout << "Enter the value of b" << endl;
    cin >> b;

    cout << "Enter the value of c" << endl;
    cin >> c;

    cout << "the biggest no. between a,b,c is: ";
    threeNObig(a, b, c);

    return 0;
}
