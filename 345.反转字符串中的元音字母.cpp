/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
#include<iostream>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            while(l<s.size()&&tolower(s[l])!='a'&&tolower(s[l])!='e'&&tolower(s[l])!='i'&&tolower(s[l])!='o'&&tolower(s[l])!='u')
                l++;
            while(r>=0&&tolower(s[r])!='a'&&tolower(s[r])!='e'&&tolower(s[r])!='i'&&tolower(s[r])!='o'&&tolower(s[r])!='u')
                r--;
            if(l<r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};
// @lc code=end

