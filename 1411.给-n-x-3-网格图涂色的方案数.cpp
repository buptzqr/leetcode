/*
 * @lc app=leetcode.cn id=1411 lang=cpp
 *
 * [1411] 给 N x 3 网格图涂色的方案数
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
private:
    static constexpr int mod = 1000000007;
public:
    int numOfWays(int n) {
        // 将i-1的情况分成abc，aba两种（分别有六种）
        // 第i行的情况只取决于上一行的涂色情况
        // f[i][0]=2∗f[i−1][0]+2∗f[i−1][1]
        // f[i][1]=2∗f[i−1][0]+3∗f[i−1][1]

        int fi0 = 6, fi1 = 6;
        for (int i = 2; i <= n; ++i) {
            int new_fi0 = (2LL * fi0 + 2LL * fi1) % mod;
            int new_fi1 = (2LL * fi0 + 3LL * fi1) % mod;
            fi0 = new_fi0;
            fi1 = new_fi1;
        }
        return (fi0 + fi1) % mod;
    }
};
// @lc code=end

