/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mmap;
        unordered_map<char,char> rmmap;
        for(int i = 0; i <s.size();i++){
            if(mmap.size()&&mmap.find(s[i])!=mmap.end()){
                if(mmap[s[i]]!=t[i])
                    return false;
            }
            if(rmmap.size()&&rmmap.find(t[i])!=rmmap.end()){
                if(rmmap[t[i]]!=s[i])
                    return false;
            }
            mmap[s[i]] = t[i];
            rmmap[t[i]] = s[i];
        }
        return true;
    }
};
// int main(){
//     Solution().isIsomorphic("egg","add");
// }
// @lc code=end

