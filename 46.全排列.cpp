/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {

    public:
        // vector<vector<int>> permute(vector<int> &nums,map<int,bool>& visited,int& visited_num){
        //     vector<vector<int>> res;
        //     if(visited_num==nums.size())
        //         return vector<vector<int>>();
        //     for (auto e : nums)
        //     {
        //         if (!visited[e])
        //         {
        //             visited[e] = true;
        //             visited_num++;
        //             vector<vector<int>> res_after = permute(nums, visited, visited_num);
        //             if (res_after.size())
        //                 for (auto ret : res_after)
        //                 {
        //                     ret.insert(ret.begin(), e);
        //                     res.push_back(ret);
        //                 }
        //             else
        //                 res.push_back(vector<int>(1,e));
        //             visited_num--;
        //             visited[e] = false;
        //         }
        //     }
        //     return res;
        // }
        // vector<vector<int>> permute(vector<int> &nums)
        // {
        //     map<int, bool> visited;
        //     for (auto e:nums)
        //         visited[e] = false;
        //     int visited_num = 0;
        //     return permute(nums, visited,visited_num);
        // }
        void dfs(vector<vector<int>>& res,vector<int>& path,unordered_map<int,bool>& visited){
            if(path.size()==visited.size())
                res.push_back(path);
            for(auto& e:visited)
                if(e.second == false){
                    path.push_back(e.first);
                    e.second = true;
                    dfs(res,path,visited);
                    path.pop_back();
                    e.second = false;
                }
        }
        // 思路更连贯一点的方式
        vector<vector<int>> permute(vector<int> &nums){
            vector<vector<int>> res;
            unordered_map<int,bool> visited;
            for(auto e:nums)
                visited[e] = false;
            vector<int> path;
            dfs(res,path,visited);
            return res;
        }

};
// @lc code=end

