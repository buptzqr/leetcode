/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> rec;
        for(auto c:p)
            rec[c]++;
        int l = 0;
        int r = 0;
        int sz = p.size();
        vector<int> res;
        while(r<s.size()){
            if(r-l==sz){
                res.push_back(l);
                rec[s[l]]++;
                l++;
            }
            // 遇到不在模式串中的字符直接跳过
            if(rec.find(s[r])==rec.end()){
                while(l<r){
                    rec[s[l]]++;
                    l++;
                }
                l= r+1;
                r= r+1;
            }
            // 如果发现重复元素
            else if(rec[s[r]]<=0){
                while(s[l]!=s[r]){
                    rec[s[l]]++;
                    l++;
                }
                l++;
                r++;
            }
            else{
                rec[s[r]]--;
                r++;
            }

        }
        if(r - l ==sz)//这个地方一定注意，是为了让尾部的匹配串也进来
            res.push_back(l);
        return res;        
    }
};
// int main(){
//     string s = "abab";
//     string p = "ab";
//     Solution().findAnagrams(s,p);
//     return 0;
// }
// @lc code=end

