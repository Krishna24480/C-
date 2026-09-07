// Reverse String Using Recursion

// Recursion-Day 4

#include <iostream>
using namespace std;

void ReverseS(string &str,int i,int j)
{
    if (i>j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;

    ReverseS(str, i, j);
}

int main()
{
    string name;

    cout << "Enter The String:"<< endl;
    cin >> name;

    int i = 0;
    int j = name.length() - 1;

    cout << "String Before Reverse; " << name << endl;

    ReverseS(name, i, j);

    cout << "String Before Reverse; " << name << endl;

    return 0;
}