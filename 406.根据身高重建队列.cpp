/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool vecIntCmp(vector<int>a, vector<int>b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        else
            return a[1]<b[1];
    }
    //按照身高从大到小排序，身高相同的人k之小的排在前面
    // 然后将这样排序后的元素按约束依次插入到目前已经拍好的队列中
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(),vecIntCmp);
        for(auto e:people)
            if(e[1]>=res.size())
                res.push_back(e);
            else
                res.insert(res.begin()+e[1], e);
        return res;
    }
};
// int main(){
//     vector<vector<int>> input = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
//     Solution().reconstructQueue(input);
//     return 0;
// }
// @lc code=end

