// Permutation in a String Problem Using Recursion

// Recursion-Day 9

#include <iostream>
#include <string>
using namespace std;

void permutation(string &s, int index)
{

    // Base case
    if (index == s.length())
    {
        cout << s << endl;
        return;
    }

    // Try every character
    for (int i = index; i < s.length(); i++)
    {

        // Choose
        swap(s[index], s[i]);

        // Recursion
        permutation(s, index + 1);

        // Backtrack
        swap(s[index], s[i]);
    }
}

int main()
{

    string s;

    int index = 0;
    cout << "Enter a string: ";
    cin >> s;

    permutation(s, index);

    return 0;
}