/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
    private:
        map<int, int> frequency;
        vector<vector<int>> res;

    public:
        void solution(map<int,int>&frequency,map<int,int>::iterator& itr,vector<int>& befor_subset){
            if(itr==frequency.end()){
                res.push_back(befor_subset);
                return;
            }
            solution(frequency, ++itr, befor_subset);
            itr--;
            //下面这块也可以用vector模拟
            /*
            solution(vector<int>& nums,int pos,vector<int> before_subset)函数声明变成这样
            int num=0
            int i = idx;
            while(nums[i]==nums[idx])
                i++;
            for(int j = 0;j<i;j++){
                before_subset.push_back(nums[i])
                solution(....)
            }
            for(int j = 0;j<i;j++)
                before_subset.pop_back();
            */
            for (int i = 0; i < itr->second; i++)
            {
                befor_subset.push_back(itr->first);
                solution(frequency, ++itr, befor_subset);
                itr--;
            }
            for (int i = 0; i < itr->second;i++)
                befor_subset.pop_back();
            
        }
        vector<vector<int>> subsetsWithDup(vector<int> &nums)
        {
            //这个和之前遇到的问题很像，还是排序，然后构建map
            sort(nums.begin(), nums.end());
            for(auto e:nums)
                frequency[e]++;
            vector<int> before_subset;
            auto itr = frequency.begin();
            solution(frequency, itr, before_subset);
            return res;
        }
};
// @lc code=end

