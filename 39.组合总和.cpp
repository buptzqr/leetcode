/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
//这个题目要保持不会重复的做法就是不走回头路
class Solution {
private:
    vector<vector<int>> res;

public:
//index记录当前访问到的candidates元素的下标,每次选取元素只能从index及以后的元素中选择
    void solve(vector<int>& candidates, int target,int index,vector<int>&rec){
        if(target==0){
            res.push_back(rec);
            return;
        }
        for(int i=index; i<candidates.size();i++){
            if(target>=candidates[i]){
                rec.push_back(candidates[i]);
                solve(candidates, target - candidates[i], i, rec);
                rec.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> rec;
        solve(candidates, target, 0, rec);
        return res;
    }
};
// @lc code=end

