/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
//记忆化搜索
    // map<pair<int,int>,int> memo;//memo[i,j]代表从i到j可以构成的搜索二叉树的数量
    // int findTreeNum(int begin,int end){//寻找从begin到end可以构成的搜索二叉树的数量
    //     if(begin>end)
    //         return 0;
    //     if(begin == end) 
    //         return 1;
    //     if(memo.find(make_pair(begin,end))== memo.end()){
    //         int res = 0;
    //         for(int i=begin;i<=end;i++){
    //             int l=findTreeNum(begin,i-1)==0?1:findTreeNum(begin,i-1);
    //             int r=findTreeNum(i+1,end)==0?1:findTreeNum(i+1,end);
    //             res += l*r;
    //         }
    //         memo[make_pair(begin,end)]=res;
    //     }
        
    //     return  memo[make_pair(begin,end)];
                   
    // }
    // int numTrees(int n) {
    //     return findTreeNum(1,n);        
    // }
    // 动态规划
    // G(n): 长度为 n 的序列能构成的不同二叉搜索树的个数。
    // F(i, n): 以 i 为根、序列长度为 n 的不同二叉搜索树个数(1≤i≤n)。
    // G(n)= ∑F(i,n)  (1<=i<=n)
    // F(i,n)=G(i−1)⋅G(n−i)
    // G(n)=∑G(i−1)⋅G(n−i)   (1<=i<=n)
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;//注意，这个dp[0]=1
        dp[1] =1;
        for(int i=2;i<=n;i++)
            for(int j =1;j<=i;j++)
                dp[i]+= dp[j-1]*dp[i-j];
        return dp[n];
    }
    
};
// int main(){
//     int res=Solution().numTrees(3);
//     return 0;
// }
// @lc code=end

