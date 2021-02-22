/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(int i=0; i<intervals.size();){
            int begin = intervals[i][0];
            int j = i;
            int end = intervals[i][1];
            while(j+1<intervals.size()&&end>=intervals[j+1][0]){
                j++;
                end = max(end,intervals[j][1]);
            }
            vector<int> tmp;
            tmp.push_back(begin);
            tmp.push_back(end);
            res.push_back(tmp);
            i = ++j;
        }
        return res;   
    }
};
// @lc code=end

