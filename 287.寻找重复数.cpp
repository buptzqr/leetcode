/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
//这个题目用unordered_map也是o(1)的时间复杂度,空间复杂度o(n)
    // int findDuplicate(vector<int>& nums) {
    //     unordered_map<int,int> nums_map;
    //     for(auto e:nums)
    //         if(++nums_map[e]>1)
    //             return e;
    //     return 0;
    // }
    // 快慢指针时空复杂度都是O(1)
    // 可以这样理解这一个数组链表
    /*
     ---------       ---------
     |  i    |------>|k      |   k = nums[i]
     |nums[i]|       |nums[k]|
     ---------       ---------
     */
    // 那么该链表必然有环，且环的入口点就是那个重复的数字
    int findDuplicate(vector<int>& nums) {
        int fast =0;
        int slow =0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        fast = 0;
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    
};
// @lc code=end

