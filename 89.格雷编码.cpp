/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        // 格雷码有自己的特性
        // g(n) = res(n-1)
        // r(n) = (res(n-1)的倒序)最前面再补1
        // res(n) = g(n) 和r(n)取并集
        if(n<1)
            return vector<int>();
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        for(int i=1;i<n;i++){
            int j=res.size()-1;
            int add = 1<<i;
            for(;j>=0;j--){
                res.push_back(add+res[j]);
            }
        }        
        return res;
    }
};
// @lc code=end

