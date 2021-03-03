/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口
        if(s.size()<2)  
            return s.size();
        int res = 0;
        int l=0;
        int r=1;
        unordered_set<char> rec;
        rec.insert(s[0]);
        while(r<s.size()&&l<=r){
            if(rec.find(s[r])!=rec.end()){
                while(s[l]!=s[r]){
                    rec.erase(s[l]);
                    l++;
                }
                l++;
        }
            rec.insert(s[r]);
            res = max(res,r-l+1);
            r++;
        }
        return res;
        
    }
};
// @lc code=end

