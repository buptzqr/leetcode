/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
    private:
        vector<vector<int>> res;

    public:
        void solution(int begin,int k,int target,vector<int>& cur){//begin代表从哪个数字开始查找
            if(cur.size()==k&&target==0){
                res.push_back(cur);
                return;
            }
            if(target<begin||begin>9)
                return;
            solution(begin + 1, k, target, cur); //不包含当前元素
            cur.push_back(begin);
            solution(begin+1,k,target-begin, cur);
            cur.pop_back();
        }
        vector<vector<int>> combinationSum3(int k, int n)
        {
            vector<int> cur;
            solution(1, k, n, cur);
            return res;
        }
};
// @lc code=end

