// Subsets Problem Using Recursion

// Recursion-Day 7

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &nums, int index,
           vector<int> &current, vector<vector<int>> &ans)
{

    // Base case
    if (index == nums.size())
    {
        ans.push_back(current);
        return;
    }

    // Choice 1: Include nums[index]
    current.push_back(nums[index]);
    solve(nums, index + 1, current, ans);

    // Backtrack
    current.pop_back();

    // Choice 2: Exclude nums[index]
    solve(nums, index + 1, current, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> current;

    solve(nums, 0, current, ans);

    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = subsets(nums);

    // Print all subsets
    for (vector<int> subset : ans)
    {
        cout << "[ ";

        for (int x : subset)
        {
            cout << x << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}