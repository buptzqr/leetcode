/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // 我这种笨办法超时了
    // int numDecodings(string s) {
    //     if(s.size()==0)
    //         return 1;
    //     if(s[0]=='0')
    //         return 0;
    //     int res =numDecodings(string(s,1));
    //     if(s.size()>=2){
    //         string tmp(s,0,2);
    //         if(stoi(tmp.c_str())>=10&&stoi(tmp.c_str())<=26)
    //             res+= numDecodings(string(s,2));
    //     }
    //     return res;
    // }
    //记忆化搜索o（n）每次递归操作的时间复杂度为o（1），递归的深度最大是n，所以时间复杂度是o（n）
    // vector<int> dp; //dp[i]代表从s[i...n]的组合总数
    // int numDecodings(string s) {
    //     dp =vector<int>(s.size(),-1);
    //     return dfs(s,0);
    // }
    // int dfs(string s,int start){
    //     if(start>=s.size())
    //         return 1;
    //     if(s[start]=='0')
    //         return 0;
    //     if(dp[start]!=-1)
    //         return dp[start];
    //     int res = dfs(s,start+1);
    //     if(start+1<s.size()&&stoi(string(s,start,2).c_str())<=26)
    //         res+=dfs(s,start+2);
    //     dp[start] = res;
    //     return res;
    // }
    // 动态规划
    // dp[i] 代表从[0,i]的所有组合和上面的dp对比就能发现自底向上和自顶向下思维的差别
    // 如果s[i]=0 此时如果s[i-1]= 1 或者2 那么dp[i] = dp[i-2]否则返回0
    // 如果s[i]!=0 此时如果s[i-1]=1 dp[i] = dp[i-1] + dp[i-2]
    //             此时如果s[i-1]=2且s[i]取1到6 dp[i] = dp[i-1] + dp[i-2]
    //             否则dp[i] = dp[i-1]
    int numDecodings(string s) {
        if(!s.size()||s[0]=='0') return 0;
        int pre_pre =1;
        int pre =1;//dp[0]=1,dp[-1]=1
        for(int i = 1;i<s.size();i++){
            if(s[i]=='0')
                if(s[i-1]=='1'||s[i-1]=='2'){
                    int tmp = pre;
                    pre=pre_pre;
                    pre_pre = tmp;
                }
                else
                    return 0;
            else if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6')){
                int tmp = pre+pre_pre;
                pre_pre = pre;
                pre= tmp;
            }
            else
                pre_pre =pre;

        }
        return pre;
    }

};
// int main(){
//     string s = "1201234";
//     Solution().numDecodings(s);
// }
// @lc code=end

