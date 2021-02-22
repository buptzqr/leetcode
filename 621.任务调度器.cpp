/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
// 桶思想
// 每个桶的大小为n+1，每个桶里不能放相同的任务，我们所需的桶的个数为次数最多的任务的次数
// 如果我们任务总类很多，那可以直接排在对应桶的后面，所以最终需要的时间就是
// final=(n+1)*(桶的个数-1) + 最后一个桶中的元素（如果任务的size<final）
// 否则为任务的size
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> rec(26);
        for(auto t:tasks)
            rec[t-'A']++;
        sort(rec.begin(), rec.end(),[](int a, int b){return a>b;});
        int max_task = 0;
        for(auto e:rec)
            if(e==rec[0])
                max_task++;
        return tasks.size()>=(n+1)*(rec[0]-1)+max_task?tasks.size():(n+1)*(rec[0]-1)+max_task;        
    }
};
// int main(){
//     vector<char> tasks={'A','A','A','B','B','B'};
//     Solution().leastInterval(tasks,2);
//     return 0;
// }
// @lc code=end

