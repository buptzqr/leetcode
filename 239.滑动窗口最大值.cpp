/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
// 采用单调队列的方式，单调队列有三个操作push,pop,max,底层容器deque
    class MonotonicQueue{
        public:
            deque<int> mono_queue;
            int max(){//返回队列中最大元素
                return mono_queue.front();
            }
            void push(int n){//每次push时需要将前面比该元素小的值都干掉
            // 这样可以保证形成的队列是不增的
                while(!mono_queue.empty()&&mono_queue.back()<n)
                    mono_queue.pop_back();
                mono_queue.push_back(n);
            }
            void pop(int n){//如果队头元素等于n,则将该元素pop
                if(!mono_queue.empty()&&mono_queue.front()==n)
                    mono_queue.pop_front();
            }
    };
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        MonotonicQueue mqueue;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i<k-1)
                mqueue.push(nums[i]);
            else{
                mqueue.push(nums[i]);
                res.push_back(mqueue.max());
                mqueue.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};
// @lc code=end

