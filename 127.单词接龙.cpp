/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
// #include<iostream>
// #include<queue>
// #include<map>
// #include<vector>
// #include<algorithm>
// #include<unordered_map>
// using namespace std;
/*class Solution {
public:
// 波神这一波操作就是提前建表，因为这个表是一个沿对角线对称的表，所以就省了很多计算量
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         queue<pair<int,int>> q;//索引，距离
//         int begin_idx = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
//         if (begin_idx== wordList.size())
//             wordList.push_back(beginWord);
//         int n = wordList.size();
//         vector<int> book(n,0);
//         vector<vector<int>> con_matrix(n,vector<int>(n,0));
//         q.push(make_pair(begin_idx,1));
//         book[q.front().first] = 1;
//         for (int i = 0; i < n;i++){
//             for (int j = 0; j < i;j++){//这个小于i很精髓的
//                 if(is_connect(wordList[i],wordList[j]))
//                     con_matrix[i][j] = con_matrix[j][i]=1;
//             }
//         }
//             while (!q.empty())
//             {
//                 int src = q.front().first;
//                 int dis = q.front().second;
//                 q.pop();
//                 for (int itr = 0; itr < n; itr++)
//                 {
//                     if (con_matrix[src][itr] && book[itr]==0)
//                     {
//                         book[itr] = 1;
//                         q.push(make_pair(itr, dis + 1));
//                         if (wordList[itr] == endWord)
//                             return dis + 1;
//                     }
//                 }
//             }
//         return 0;
//     }
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // bfs
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        if(wordSet.find(beginWord) != wordSet.end())
            wordSet.erase(beginWord);

        vector<string> visited;

        while(!q.empty()){
            string curWord = q.front().first;
            int curStep = q.front().second;
            q.pop();

            visited.clear();
            for(string word: wordSet)
                if(is_connect(word, curWord)){
                    if(word == endWord)
                        return curStep + 1;
                    q.push(make_pair(word, curStep + 1));
                    visited.push_back(word);
                }

            for(string word: visited)
                wordSet.erase(word);
        }

        return 0;
    }

private:
    bool is_connect(string src,string dst){
        int flag=0;
        for(int i=0;i<src.size();i++){
            if(src[i]!=dst[i]){
                flag++;
            }
        }
        return flag==1;
    }
};
*/

//和我们思路最不同的地方就在于他每个word连接的是虚拟节点，比如hot连接的就是h*t,*ot,ho*,这样搜索的时间复杂度就从o(n^2)降到了o(n*c)，广度优先搜索的时间复杂度就是节点的数目
class Solution {
// public:
//     unordered_map<string, int> wordId;
//     vector<vector<int>> edge;
//     int nodeNum = 0;

//     void addWord(string& word) {
//         if (!wordId.count(word)) {
//             wordId[word] = nodeNum++;
//             edge.emplace_back();
//         }
//     }

//     void addEdge(string& word) {
//         addWord(word);
//         int id1 = wordId[word];
//         for (char& it : word) {
//             char tmp = it;
//             it = '*';
//             addWord(word);
//             int id2 = wordId[word];
//             edge[id1].push_back(id2);
//             edge[id2].push_back(id1);
//             it = tmp;
//         }
//     }

//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         for (string& word : wordList) {
//             addEdge(word);
//         }
//         addEdge(beginWord);
//         if (!wordId.count(endWord)) {
//             return 0;
//         }
//         vector<int> dis(nodeNum, INT_MAX);
//         int beginId = wordId[beginWord], endId = wordId[endWord];
//         dis[beginId] = 0;

//         queue<int> que;
//         que.push(beginId);
//         while (!que.empty()) {
//             int x = que.front();
//             que.pop();
//             if (x == endId) {
//                 return dis[endId] / 2 + 1;
//             }
//             for (int& it : edge[x]) {
//                 if (dis[it] == INT_MAX) {
//                     dis[it] = dis[x] + 1;
//                     que.push(it);
//                 }
//             }
//         }
//         return 0;
//     }
public:
//我自己来一个双向广搜,所谓双向广搜就是一方面从头开始BFS，一方面从尾开始BFS，什么时候这两方面都访问了同一个元素，说明找到了一条通路
//这里还存在一个优化，就是每次我们应该直接广度优先遍历一层，而不是说每次遍历一层的一个元素
    unordered_map<string, int> str2id;//key是string，val是该string的id
    int node_num = 0;
    vector<vector<int>> con_map;//记录各节点连接关系
    void addNode(string str){
        if(str2id.find(str)==str2id.end()){
            str2id[str] = node_num;
            con_map.push_back(vector<int>());
            node_num++;
        }
    }
    void addEdge(string str){
        addNode(str);
        int id1 = str2id[str];
        for (char& itr : str)//auto 其实是复制容器内的元素
        {
            char tmp = itr;
            itr = '*';
            addNode(str);
            int id2 = str2id[str];
            con_map[id1].push_back(id2);
            con_map[id2].push_back(id1);
            itr = tmp;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        addEdge(beginWord);
        for(auto e:wordList)
            addEdge(e);
        if(str2id.find(endWord)==str2id.end())
            return 0;
        vector<int> dis(node_num, 0);
        queue<int> head_q;
        queue<int> tail_q;
        head_q.push(str2id[beginWord]);
        tail_q.push(str2id[endWord]);
        unordered_map<int,bool> head_book;
        unordered_map<int,bool> tail_book;

        while(!head_q.empty()||!tail_q.empty()){
            if(!head_q.empty()){
                int h = head_q.front();
                head_q.pop();
                for(auto e:con_map[h]){
                    if(head_book.find(e)==head_book.end()){
                        int h_dis = dis[h] + 1;
                        if(tail_book.find(e)!= tail_book.end())
                            return (dis[e] + h_dis) / 2+1;
                        head_q.push(e);
                        dis[e] = h_dis;
                        head_book[e] = true;
                    }
                }
            }
            if(!tail_q.empty()){
                int t = tail_q.front();
                tail_q.pop();
                for(auto e:con_map[t]){
                    if(tail_book.find(e)==tail_book.end()){
                        int t_dis = dis[t] + 1;
                        if(head_book.find(e)!= head_book.end())
                            return (dis[e]+t_dis) / 2+1;
                        tail_q.push(e);
                        dis[e] = t_dis;
                        tail_book[e] = true;
                    }
                }

            }

        }
        return 0;
    }
};
// int main(){
//     string a[] = {"hot", "dot", "tog", "cog"};
//     vector<string> s(a, a + sizeof(a) / sizeof(string));
//     string begin = "hit";
//     string end = "cog";
//     cout<<Solution().ladderLength(begin,end,s);
// }
// @lc code=end

