/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
    // private:
    //     vector<vector<int>> res;
    // public:
    // //当前元素选或者不选，然后加上剩下元素的所有子集
    //     void solution(vector<int> &nums,int cur_idx,vector<int> &before_subset){
    //         if(cur_idx==nums.size()){
    //             res.push_back(before_subset);
    //             return;
    //         }
    //         solution(nums, cur_idx + 1, before_subset);
    //         before_subset.push_back(nums[cur_idx]);
    //         solution(nums, cur_idx + 1, before_subset);
    //         before_subset.pop_back();
    //     }
    //     vector<vector<int>> subsets(vector<int> &nums)
    //     {
    //         vector<int> before_subset;
    //         solution(nums, 0, before_subset);
    //         return res;
    //     }
    //我感觉上面这种思维是从前到后的思维
    // 如果从后向前想的话就是我当前节点可以加入或者不加入后续节点构成的全部子集中去
    public:
    //这里cur_idx是构成子集开始的元素，从该元素一直到nums最后一个元素
        vector<vector<int>> solution(vector<int> &nums,int cur_idx){
            vector<vector<int>> res;
            if(cur_idx==nums.size())
                return res;
            vector<vector<int>> after_res = solution(nums, cur_idx + 1);
            if(after_res.size())
                for(auto e:after_res){
                    res.push_back(e);
                    e.push_back(nums[cur_idx]);
                    res.push_back(e);
                }
            else{
                res.push_back(vector<int>());
                res.push_back(vector<int>(1,nums[cur_idx]));
            }
            return res;
        }
        vector<vector<int>> subsets(vector<int> &nums){
            return solution(nums, 0);
        }
};
// @lc code=end

