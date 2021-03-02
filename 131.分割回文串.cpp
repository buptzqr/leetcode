/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
// 一个问题需要多个步骤求解，每个步骤又有多种方法，题目要求找出所有方法，
// 此时就要用回溯法,回溯法就是在树形结构中做一个dfs,有两个常规变量
// 一个是res用来记录结果,一个是path用来记录到达该节点的路径,回溯要修改的就是这个path
// 另外需要注意的是dfs是用来对深度层面进行遍历的,dfs中的for循环用来对广度进行遍历
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;
        while(l<=r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(vector<vector<string>>& res,vector<string> path, string& s,int begin){
        if(begin==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=1;i+begin<=s.size();i++){
            string str = string(s,begin,i);
            if(isPalindrome(str)){
                path.push_back(str);        
                dfs(res,path,s,begin+i);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(res,path,s,0);
        return res;
    }
};
// int main(){
//     Solution().partition("aab");
// }
// @lc code=end

