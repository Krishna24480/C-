//Phone Keyboard Problem Using Recursion

// Recursion-Day 8

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string digits, int index, string current,
           vector<string> &ans, vector<string> &keypad)
{

    // Base case
    if (index == digits.length())
    {
        ans.push_back(current);
        return;
    }

    // Convert character digit to integer
    int digit = digits[index] - '0';

    // Get the string corresponding to the digit
    string letters = keypad[digit];

    // Try every character
    for (char ch : letters)
    {
        current.push_back(ch);

        solve(digits, index + 1, current, ans, keypad);

        // Backtrack
        current.pop_back();
    }
}

int main()
{

    string digits;
    cin >> digits;

    // Phone keypad
    vector<string> keypad = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector<string> ans;

    solve(digits, 0, "", ans, keypad);

    for (string s : ans)
    {
        cout << s << " ";
    }

    return 0;
}