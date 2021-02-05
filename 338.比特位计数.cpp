/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    // 人家不要的方法就是对每个数字除以2取余
    // dp+最高有效位(一个数可能和另一个数的各个位都相同，只是最高有效位不同)
    // 比如(1100) 和(11100)以及(101100)等
    // dp[i+2^m] = dp[i]+1 2^m(2^m>i)
    // vector<int> countBits(int num) {
    //     vector<int> ret(num+1,0);
    //     int flag =0;
    //     for(int i=0;i<=num;i++){
    //         if(num==flag)
    //             break;
    //         int b = 1;
    //         while(b<=i)
    //             b<<=1;
    //         while(i+b<=num){
    //             ret[i+b] = ret[i]+1;
    //             b<<=1;
    //             flag++;
    //         }
    //     }
    //     return ret;
    // }
    // dp+最低有效位
    // 一个数只是和另一个数最低有效位相差一或者完全相同
    // 比如（1001）和（100）只是最低有效位相差为1 (1000)和（100）完全相同
    // dp[i] = dp[i/2] + i mod 2
    // 这种思路代码更简洁
    vector<int> countBits(int num) {
        vector<int> ret(num+1,0);
        for(int i=1; i<=num;i++)
            ret[i] = ret[i/2] + i%2;
        return ret;
    }

};
// int main(){
//     for(auto e:Solution().countBits(4))
//         cout<<e<<" ";
// }
// @lc code=end

