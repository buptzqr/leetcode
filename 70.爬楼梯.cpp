/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    // vector<int> memo;//用来记录爬n级台阶的所有方式
    // //寻找n阶台阶的爬楼方式总数并返回
    // int findPath(int n){
    //     //先用记忆化搜索来一遍（自顶向下）
    //     if(n==1||n==0){
    //         return 1;
    //     }
    //     if(memo[n]==-1)
    //         memo[n]=findPath(n-1)+findPath(n-2);
    //     return memo[n];
    // }
    // int climbStairs(int n) {
    //     //这个问题就是动规的经典问题了
    //     memo = vector<int>(n + 1, -1);
    //     return findPath(n);
        
    // }
    //动态规划解法
    // int climbStairs(int n) {
    //     vector<int> memo(n+1,-1);
    //     memo[0] = 1;
    //     memo[1] = 1;
    //     for (int i = 2;i<=n;i++){
    //         memo[i] = memo[i - 1] + memo[i - 2];
    //     }
    //     return memo[n];
    // }
    vector<int> memo;//memo[idx]从第0级到第idx级爬楼方式
    int findPath(int idx){
        if(idx<0)
            return 0;
        if(idx==0)
            return 1;
        if(memo[idx]!=-1)
            return memo[idx];
        memo[idx] = findPath(idx-1)+findPath(idx-2);
        return memo[idx];
    }
    int climbStairs(int n) {
        //这个问题就是动规的经典问题了
        memo = vector<int>(n + 1, -1);
        return findPath(n);
    }
};
// int main(){
//     int res=Solution().climbStairs(2);
//     return 0;
// }
// @lc code=end

