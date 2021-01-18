/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        vector<int> res;
        for (auto e : set1)
        {
            if(set2.find(e) != set2.end())
                res.push_back(e);
        }
        return res;
    }
};
// @lc code=end

