/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <map>
// #include <algorithm>
// using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    // {
    //     map<int, vector<int>> indexRecord;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         auto itr = indexRecord.find(nums[i]);
    //         if (itr != indexRecord.end())
    //             indexRecord[nums[i]].push_back(i);
    //         else
    //         {
    //             vector<int> v = {i};
    //             indexRecord[nums[i]] = v;
    //         }
    //     }
    //     sort(nums.begin(), nums.end());
    //     int lPtr = 0;
    //     int rPtr = nums.size() - 1;
    //     while (lPtr < rPtr)
    //     {
    //         if (nums[lPtr] + nums[rPtr] == target)
    //         {
    //             if (nums[lPtr] == nums[rPtr])
    //                 return (vector<int>(indexRecord[nums[lPtr]].begin(), indexRecord[nums[lPtr]].begin() + 2));
    //             else
    //             {
    //                 int res[2] = {indexRecord[nums[lPtr]][0], indexRecord[nums[rPtr]][0]};
    //                 return (vector<int>(res, res + 2));
    //             }
    //         }
    //         else if (nums[lPtr] + nums[rPtr] < target)
    //             lPtr++;
    //         else
    //             rPtr--;
    //     }
    //     return vector<int>();
    // }
    {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            if (record.find(target - nums[i]) != record.end())
            {
                int res[2] = {record[target - nums[i]], i};
                return vector<int>(res, res + 2);
            }
            else
            {
                record[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};
// int main()
// {
//     vector<int> nums = {2, 7, 11, 15};
//     Solution().twoSum(nums, 9);
// }
// @lc code=end
