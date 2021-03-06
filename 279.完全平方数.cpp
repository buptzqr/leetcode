/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
// 这是一个最短路径问题，思路就是说一个正整数如果和另一个正整数，相差为某个完全平方数，
// 则这两个数相连，最后问题就变成这个节点到0这个节点的最短距离
#include <iostream>
#include <queue>
#include <math.h>
#include <string.h>
#include <limits.h>
using namespace std;
// 用vector做二维数组，以及在堆上开二维数组
//https://blog.csdn.net/a819825294/article/details/52088732
// 如果编译时数组元素个数不确定，但是要在栈上开辟数组，https://stackoverflow.com/questions/3082914/c-compile-error-variable-sized-object-may-not-be-initialized
// 不要建图，尤其不要用邻接矩阵，实在是太费空间了
// 这里不需要建图是因为连接关系可以计算得到
class Solution {
public:
    // int numSquares(int n) {
    //     int book[n+1];
    //     memset(book, 0,(n+1)*sizeof(int));
    //     queue<pair<int,int>> q;
    //     q.push(make_pair(n,0));
    //     book[n]=1;
    //     while(!q.empty()) {
    //         int num = q.front().first;
    //         int dis = q.front().second;
    //         q.pop();
    //         for(int i=0;num-i*i>=0;i++){
    //             if(book[num-i*i]==0){
    //                 q.push(make_pair(num-i*i,dis+1));
    //                 book[num-i*i]=1;
    //             }
    //             if(num-i*i==0){
    //                 return dis+1;
    //             }
    //         }
    //     }
    //     return 0;
    // }
    // 动态规划，每一个数的最少平方数，等于与他相差平方数的其他数的最少平方数的最小值+1
    // int numSquares(int n) {
    //     vector<int> rec(n+1,-1);
    //     rec[0] = 0;
    //     rec[1] = 1;
    //     for(int i=2;i<=n;i++){
    //         int min_path = INT_MAX;
    //         for(int j=1;i-j*j>=0;j++)
    //             min_path = min(rec[i-j*j],min_path);
    //         rec[i] = min_path+1;
    //     }
    //     return rec[n];
    // }
    //bfs
    int numSquares(int n) {
        vector<bool> visited(n+1,false);
        vector<int> q;
        q.push_back(n);
        visited[n] = true;
        int ret = 0;
        while(!q.empty()){
            ret++;
            vector<int> tmp;
            for(auto e:q){
                for(int i=1;e-i*i>=0;i++){
                    if(!visited[e-i*i]){
                        if(e-i*i==0)
                            return ret;
                        tmp.push_back(e-i*i);
                        visited[e-i*i]=true;
                    }
                }
            }
            q=tmp;
        }
        return 0;
    }

};
// int main(){
//     cout<<Solution().numSquares(12)<<endl;
// }
// @lc code=end

