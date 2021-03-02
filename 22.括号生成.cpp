/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    // 回溯
    // count1代表还有多少左括号未匹配右括号，count2代表还有多少个左括号可以使用
    void dfs(vector<string>& res,string& path,int count1,int count2){
        if(count1==0&&count2==0)
            res.push_back(path);
        if(count1>0){
            path+=')';
            dfs(res,path,count1-1,count2);
            path.pop_back();
        }
        if(count2>0){
            path+='(';
            dfs(res,path,count1+1,count2-1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n<=0)
            return vector<string>();
        string path = "(";
        vector<string> res;
        dfs(res,path,1,n-1);
        return res;
    }
};
// @lc code=end

