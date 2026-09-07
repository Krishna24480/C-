// Check Palindrome Using Recursion

// Recursion-Day 4

#include <iostream>
using namespace std;

bool CheckPalindrome(string str, int i, int j)
{
    if (i > j)
        return true;

    if (str[i] != str[j])
        return false;

    else
    {
        CheckPalindrome(str, i + 1, j - 1);
    }
}

int main()
{
    string name;

    cout << "Enter The String:" << endl;
    cin >> name;

    int i = 0;
    int j = name.length() - 1;

    bool iSpalindrome = CheckPalindrome(name, i, j);

    if (iSpalindrome)
    {
        cout << "This String is a Palindrome" << endl;
    }
    else
    {
        cout << "This String is Not a Palindrome" << endl;
    }

    return 0;
}