/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    // int hammingDistance(int x, int y) {
    //     int res=0;
    //     while(x>0||y>0) {
    //         if((x&1)^(y&1))
    //             res++;
    //         x>>=1;
    //         y>>=1;
    //     }
    //     return res;
    // }
    // 逻辑很简单，顺着题意，先按位异或，再按位累加1的个数。
    int hammingDistance(int x, int y) {
        x^=y;
        y =0;
        while(x){
            y++;
            x&=(x-1);
        }
        return y;
    }

};
// int main(){
//     Solution().hammingDistance(3,1);
// }
// @lc code=end

