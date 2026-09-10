// Subsequence Problem Using Recursion

// Recursion-Day 7

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string &str, int index,
           string &current, vector<string> &ans)
{

    // Base case
    if (index == str.size())
    {
        ans.push_back(current);
        return;
    }

    // Choice 1: Include str[index]
    current.push_back(str[index]);

    solve(str, index + 1, current, ans);

    // Backtrack
    current.pop_back();

    // Choice 2: Exclude str[index]
    solve(str, index + 1, current, ans);
}

vector<string> subsequences(string str)
{

    vector<string> ans;
    string current;

    solve(str, 0, current, ans);

    return ans;
}

int main()
{

    string str = "abc";

    vector<string> ans = subsequences(str);

    for (string s : ans)
    {
        cout << "\"" << s << "\"" << endl;
    }

    return 0;
}