/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 排序O(nlogn)
        // 哈希表，关键的一点是如果你已经知道一个连续序列x，x+1...x+y
        // 那你就不用从x+1，x+2...x+y探索新的序列了
        // 也就是说一个元素要不要跳过，就看nums中有没有他前面的第一个元素
        unordered_set<int> mset;
        for(auto e:nums)
            mset.insert(e);
        int res = 0;
        nums = vector<int>(mset.begin(),mset.end());
        for(int i = 0; i < nums.size();i++){
            if(mset.find(nums[i]-1)!=mset.end())
                continue;
            int j = 0;
            while(mset.find(nums[i]+j)!=mset.end())
                j++;
            res = max(res,j);
        }
        return res;
    }
};
// @lc code=end

