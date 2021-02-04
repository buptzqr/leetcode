/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int max3(int a,int b,int c){
        return max(a,max(b,c));
    }
    int integerBreak(int n) {
        vector<int> memo(n+1,-1);
        memo[1] = 1;
        for(int i=2;i<=n;i++){
            int ret = INT_MIN;
            for(int j=1;j<i;j++)
                ret = max3(ret,j*(i-j),j*memo[i-j]);//这里的一个大坑就是你可以继续向下搜索，也可以此时的两个元素是否构成最大乘积
            memo[i] = ret;
        }     
        return memo[n];    
    }
     // //返回整数n分裂（至少分裂成两个数）以后的最大乘积
    // int maxMulti(int n){
    //     if(n==1)
    //         return 1;
    //     int res = 0;
    //     if(memo[n])
    //         return memo[n];
    //     for (int i = 1;i<n;i++){
    //         if(memo[n-i]==0){
    //             memo[n-i] = maxMulti(n-i);
    //         }
    //         res = max3(res, i*(n-i),i * memo[n-i]);//这个地方要注意，i*(n-i)看看不进行分割n-i
    //     }
    //     return res;
    // }
    // int integerBreak(int n) {
    //     memo = vector<int>(n + 1, 0);
    //     return maxMulti(n);
    // }
};
// int main(){
//     int ret = Solution().integerBreak(10);
//     return 0;
// }
// @lc code=end

