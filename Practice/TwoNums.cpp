// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int num1 = 0;
    int num2 = 1;

    while (num1 > nums.size() || num2 > nums.size())
    {
        if (nums[num1] + nums[num2] == target)
        {
            return { num1, num2 };
        }

        else
        {
            return {};
        }
        num1++;
        num2++;
    }
}

int main()
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;

    return 0;
}
