/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
//这里避免重复的方式就是先排序，然后统计每个出现的次数，然后按选择或者不选择当前元素
// 来寻找排列，如果选择当前元素的话，要考虑选择多少个当前元素
class Solution {
private:
    vector<vector<int>> res;
    vector<pair<int, int>> frequency;

public:
    void solve(int target,int index,vector<int>&rec){
        if(target==0){
            res.push_back(rec);
            return;
        }
        if(index==frequency.size()||target<frequency[index].first)
            return;
        solve(target,index+1,rec);
        int max_num = min(target / frequency[index].first, frequency[index].second);
        for (int i = 1; i <= max_num; i++)
        {
            rec.push_back(frequency[index].first);
            solve( target - i * frequency[index].first, index + 1, rec);
        }
        for (int i = 1; i <= max_num; i++)
            rec.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int> rec;
        sort(candidates.begin(), candidates.end());
        for(auto e:candidates){
            if(!frequency.size()||frequency.back().first!=e)
                frequency.push_back(make_pair(e, 1));
            else
                frequency.back().second++;
        }
        solve(target, 0, rec);
        return res;
    }
};
// @lc code=end

