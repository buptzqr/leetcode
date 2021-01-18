/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {

    public:
        vector<vector<int>> permute(vector<int> &nums,map<int,bool>& visited,int& visited_num){
            vector<vector<int>> res;
            if(visited_num==nums.size())
                return vector<vector<int>>();
            for (auto e : nums)
            {
                if (!visited[e])
                {
                    visited[e] = true;
                    visited_num++;
                    vector<vector<int>> res_before = permute(nums, visited, visited_num);
                    if (res_before.size())
                        for (auto ret : res_before)
                        {
                            ret.insert(ret.begin(), e);
                            res.push_back(ret);
                        }
                    else
                        res.push_back(vector<int>(1,e));
                    visited_num--;
                    visited[e] = false;
                }
            }
            return res;
        }
        vector<vector<int>> permute(vector<int> &nums)
        {
            map<int, bool> visited;
            for (auto e:nums)
                visited[e] = false;
            int visited_num = 0;
            return permute(nums, visited,visited_num);
        }
};
// @lc code=end

