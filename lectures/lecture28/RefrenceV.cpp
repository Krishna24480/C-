#include <iostream>
using namespace std;

void update(int &k)
{
    k = k * 2;
};

int main()
{

    /*
    int i = 5;
    int &j = i;

    cout << "In Reffrence Variable same variable have multiple name\n";

    cout << "The Value Of i is: "<< i << endl; // i name Variable
    cout << "The Value Of j is: " << j << endl; // Reffrence Variable of i

    i++;
    cout << "The Value Of i after increment i is: " << i << endl;
    cout << "The Value Of j after increment i is: " << j << endl;

    j++;
    cout << "The Value Of i after increment j is: " << i << endl;
    cout << "The Value Of j after increment j is: " << j << endl;
    */

    int C = 66;

    cout << "The Value Of C Before Update is: " << C << endl;

    update(C);

    cout << "The Value Of C After Update is: " << C << endl;
    return 0;
}