/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
//方法一：排序，将每个元素排序后的结果作为键，对应的每一元素作为值
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> unmap;
        for(auto str:strs) {
            string val = str;
            sort(str.begin(), str.end());
            unmap[str].push_back(val);
        }
        vector<vector<string>> res;
        for(auto e:unmap)
            res.push_back(e.second);
        return res;
    }
    /*方法二质数相乘：质数相乘结果必然不相同
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map <double,vector<string> > m;
        double a[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        for(string& s : strs)
        {
            double t = 1;
            for(char c : s)
                t *= a[c - 'a'];
            m[t].push_back(s);          //t为单词对应的质数乘积，m[t]则为该单词的异位词构成的vector
        }
        for(auto& n : m)                //n为键和值组成的pair
            res.push_back(n.second);
        return res;
    }

    */ 
};
// @lc code=end

