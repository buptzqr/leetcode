/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
// memo代表s[index,s.size())的字符串是否可以由wordDict组成
//     vector<int> memo;
// // 检查s[index,s.size())的字符串是否可以由wordDict组成
//     bool wordSearch(string s,int index,vector<string>& wordDict){
//         if(index == s.size())
//             return true;
//         if(memo[index]!=-1)
//             return memo[index];
//         bool flag =false;
//         for(auto word:wordDict){
//             if(s.size()-index>=word.size()&&s.substr(index,word.size())==word)
//                 if(wordSearch(s,index+word.size(),wordDict)){
//                     flag = true;
//                     break;
//                 }
//         }
//         memo[index]= flag?1:0;
//         return memo[index];        
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         memo = vector<int> (s.size(),-1);
//         bool ret= wordSearch(s,0,wordDict);
//         return ret;       
//     }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size()+1,0);//memo[i]表示s[0,i)是否可以由wordDict组成
        memo[0] =1;
        for(int i=0;i<=s.size();i++){
            //判断[0,j) [j,i)这两个字符串是否可以由wordDict组成
            for(int j=0;j<i;j++){
                if(memo[j]&&find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                    memo[i]=1;
                    break;
                }
            }
        }
        return memo[s.size()];
    }
    
};
// int main(){
//     vector<string> input = {"a","abc","b","cd"};
//     Solution().wordBreak("abcd",input);
// }
// @lc code=end

