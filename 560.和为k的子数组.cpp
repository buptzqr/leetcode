/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //pre[i]表示从[0,i]元素的和,那么要求包括i在内连续子数组和为k，只需要在
        // 0<=j<i的范围内找pre[j] = pre[i] - k的个数即可,所以用map来记录[0,i]
        // 所有pre[i]出现的次数，(pre[i]为键，出现次数为值),然后只要查找map[pre[i]-k]即可
        unordered_map<int,int> mmap;
        int res =0;
        int pre =0;
        mmap[pre] = 1;
        for(auto e:nums){
            pre+=e;
            if(mmap.count(pre-k))//count函数作用：如果键值为指定值的元素存在，返回1否则返回0
                res+=mmap[pre-k];
            mmap[pre]++;
        }
        return res;
    }
};
// @lc code=end

