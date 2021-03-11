/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> splitstr(string& s){
        string str;
        vector<string> res;
        while(s.find(' ')!=string::npos){
            str=string(s.begin(),s.begin()+s.find(' '));
            s = string(s,s.find(' ')+1);
            res.push_back(str);
        }
        res.push_back(s);
        return res;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mmap;
        unordered_map<string,char> rmmap;
        vector<string> vecs = splitstr(s);
        if(pattern.size()!=vecs.size())
            return false;
        for(int i=0;i<vecs.size();i++){
            if(mmap.size()==0||mmap.find(pattern[i])== mmap.end())
                mmap[pattern[i]] = vecs[i];
            if(rmmap.size()==0||rmmap.find(vecs[i])== rmmap.end())
                rmmap[vecs[i]] = pattern[i];
            
            if(mmap[pattern[i]]!= vecs[i]||rmmap[vecs[i]]!=pattern[i])
                return false;
            
        }
        return true;
    }
};
// int main(){
//     Solution().wordPattern("abba","dog cat cat fish");
// }
// @lc code=end

