/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        //普通思路,相当于除2取余法
        // int res =0;
        // while(n){
        //     if(n&1)
        //         res++;
        //     n >>= 1;
        // }
        // return res;
        //这个思路比较好，上面的思路需要遍历每一位，这个思路只需要遍历有1的位
        int res = 0;
        while(n){
            res++;
            n = n & (n - 1);//这步操作就相当于把最低位的1给干掉了
        }
        return res;
    }
};
// @lc code=end

