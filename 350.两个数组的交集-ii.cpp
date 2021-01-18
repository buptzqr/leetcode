/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mmap1;
        unordered_map<int,int> mmap2;
        vector<int> res;
        for (auto e : nums1)
            mmap1[e]++;
        for(auto e:nums2)
            mmap2[e]++;
        for(auto e:mmap1){
            if(mmap2.find(e.first)!=mmap2.end()){
                int nums = min(mmap1[e.first],mmap2[e.first]);
                while(nums>0){
                    res.push_back(e.first);
                    nums--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

