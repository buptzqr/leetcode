/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
//这道题就是看有向图是否包括环
//bfs（节点出度为0说明他的所有条件都已经满足，后面所说的都是出度）
// 将度为0的节点依次入队，然后出队，并将与其相连的节点的度减一，然后继续将度为0的节点入队
// 当队列为空时所有节点都已经入队并出队，则可以满足拓扑排序，否则不可以 
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int> degree(numCourses,0);//出度表
    //     // 构建反向邻接表和出度表
    //     vector<vector<int>> table(numCourses,vector<int>());
    //     for(auto vec:prerequisites){
    //         table[vec[1]].push_back(vec[0]);
    //         degree[vec[0]]++;
    //     }
    //     queue<int> q;
    //     for(int i=0;i<numCourses;i++)
    //         if(degree[i]==0)
    //             q.push(i);
    //     while(!q.empty()){
    //         int idx = q.front();
    //         q.pop();
    //         numCourses--;
    //         for(auto i:table[idx]){
    //             degree[i]--;
    //             if(degree[i]==0)
    //                 q.push(i);
    //         }
    //     }
    //     return numCourses==0;
    // }
    // dfs深度优先遍历
    // DFS 流程；
    // 终止条件：(flag为0表示未被访问)
    //      当 flag[i] == -1，说明当前访问节点已被其他节点启动的 DFS 访问，无需再重复搜索，直接返回 True。
    //      当 flag[i] == 1，说明在本轮 DFS 搜索中节点 i 被第 2 次访问，即 课程安排图有环 ，直接返回 False。
    // 将当前访问节点 i 对应 flag[i] 置 1，即标记其被本轮 DFS 访问过；
    // 递归访问当前节点 i 的所有邻接节点 j，当发现环直接返回 FalseFalse；
    // 当前节点所有邻接节点已被遍历，并没有发现环，则将当前节点 flag 置为 -1−1 并返回 TrueTrue。
    // 若整个图 DFS 结束并未发现环，返回 True。
    bool dfs(vector<vector<int>>& table,vector<int>& flag,int idx){
        if(flag[idx]==-1)
            return true;
        if(flag[idx]==1)
            return false;
        flag[idx]=1;
        // 深度优先遍历
        for(auto e:table[idx]){
            if(!dfs(table,flag,e))
                return false;
        }
        flag[idx] = -1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> table(numCourses);
        for(auto vec:prerequisites)
            table[vec[0]].push_back(vec[1]);
        vector<int> flag(numCourses);
        for(int i = 0;i<numCourses;i++)//必须对所有节点走一次，防止图有两个部分
            if(!dfs(table,flag,i))
                return false;
        return true;
    }
    
};
// int main(){
//     vector<vector<int>> input={{1,0}};
//     Solution().canFinish(2,input);
// }
// @lc code=end

