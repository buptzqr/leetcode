/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>>& res,vector<int>&cur,vector<int>& nums,vector<bool>& visited){
        if(cur.size()==nums.size())
            res.push_back(cur);
        for (int i = 0; i < nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1]&&!visited[i-1])
                continue;
            if (!visited[i])
            {
                visited[i] = true;
                cur.push_back(nums[i]);
                dfs(res, cur, nums, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //这个题还是去重比较关键,同一层不可以重复，不同层可以重复,
        // 如果nums[i]==nums[i-1]&&visited[i-1]=false,说明同层选取，
        // 如果nums[i]==nums[i-1]&&visited[i-1]=true说明异层选取，可以选取
        vector<int> cur;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        dfs(res, cur, nums, visited);
        return res;
    }
};
// @lc code=end

