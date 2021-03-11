#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 建立最小堆来看那个会议最早结束
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b)->bool{
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        });
        priority_queue<int,vector<int>,greater<int>> heap;
        for(auto meeting:intervals){
            if(heap.size()!=0&&heap.top()<=meeting[0])
                heap.pop();
            heap.push(meeting[1]);                
        }
        return heap.size();
    }
};