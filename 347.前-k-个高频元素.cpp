/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<queue>
// #include<functional>
// #include <algorithm>
// using namespace std;
//超过k个元素怎么办？那就先pop再push呗，priority_queue的用法和stack一致，只有top没有back和front
class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> mmap;
    //     for(auto e:nums)
    //         mmap[e]++;
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //     for(auto e:mmap){
    //         if(pq.size()<k)
    //             pq.push(make_pair(e.second,e.first));
    //         else if(pq.top().first<e.second){
    //             pq.pop();
    //             pq.push(make_pair(e.second,e.first));
    //         }
    //     }
    //     vector<int> res;
    //     while(!pq.empty()){
    //         res.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     return res;
    // }
    //使用o(nlog(n-k))的思路
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mmap;
        for(auto e:nums)
            mmap[e]++;
        priority_queue<pair<int,int>> pq;//维护最小的n-k个元素,默认是最大堆
        int sz = mmap.size();
        vector<int> res;
        if(sz-k<=0){
            for(auto e:mmap)
                res.push_back(e.first);
            return res;    
        }
            
        for(auto e:mmap){
            if(pq.size()<sz -k)
                pq.push(make_pair(e.second,e.first));
            else if(pq.top().first>e.second){
                pq.pop();
                pq.push(make_pair(e.second,e.first));
            }
        }
        vector<int> pq2vec;
        while(!pq.empty()){
            pq2vec.push_back(pq.top().second);
            pq.pop();
        }
        for(auto e:mmap){
            if(find(pq2vec.begin(),pq2vec.end(),e.first)==pq2vec.end())
                res.push_back(e.first);
                
        }
        return res;
    }
};
// @lc code=end

