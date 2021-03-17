/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string res = strs[0];
        for(int i = 1; i < strs.size();i++){
            int sz = min(res.size(),strs[i].size());
            int j = 0;
            for(;j<sz&&res[j]==strs[i][j];)
                j++;
            res = string(res,0,j);
        }
        return res;
    }
};
// @lc code=end

