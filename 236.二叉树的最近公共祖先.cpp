/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include<iostream>
// #include<map>
// #include<vector>
// #include<algorithm>
// using namespace std;
// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
 
class Solution {
    //这个是二叉树的最近公共祖先，之前是二分搜索树的最近公共祖先
    //树从一个节点到达另一个节点只有一条路径，这条路径上的其他节点是他的祖先节点，我们从p，q这两个节点的祖先节点中找最早的公共祖先节点即可
    //上述思路我就给每个节点记录一下他的父节点是谁,然后遍历一遍节点，完成parent数组
    //然后向上追溯得到pq两个节点的祖先节点
private:
        map<TreeNode *, TreeNode *> parent;
public:
        void inorderTraverse(TreeNode* root){
            if(!root)
                return;
            inorderTraverse(root->left);
            if(root->left)
                parent[root->left] = root;
            if(root->right)
                parent[root->right] = root;
            inorderTraverse(root->right);
        }
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
        {
            parent[root] = NULL;
            inorderTraverse(root);
            vector<TreeNode *> vector_q;
            vector<TreeNode *> vector_p;
            //这个tmp是我踩的一个坑，后续要使用的变量，一点小心不能随便更改值呀
            TreeNode *tmp_p = p;
            TreeNode *tmp_q = q;
            while (parent[tmp_p])
            {
                if(parent[tmp_p]==q)
                    return q;
                vector_p.push_back(parent[tmp_p]);
                tmp_p = parent[tmp_p];
            }
            while(parent[tmp_q]){
                if(parent[tmp_q]==p)
                    return p;
                vector_q.push_back(parent[tmp_q]);
                tmp_q = parent[tmp_q];
            }
            for(auto e:vector_q){
                if(find(vector_p.begin(),vector_p.end(),e)!= vector_p.end())
                    return e;
            }
            return NULL;
        }
        //思路二就是用递归的方法来实现了，对于二叉树来说深度优先遍历就是后序遍历，有个傻逼说错了，这里在做dfs的时候捎带
        // 判断了root这个节点代表的树是否包含p节点或者q节点
        /*
        public:
            TreeNode* ans;
            bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
                if (root == nullptr) return false;
                bool lson = dfs(root->left, p, q);
                bool rson = dfs(root->right, p, q);
                if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
                    ans = root;
                } 
                return lson || rson || (root->val == p->val || root->val == q->val);
            }
            TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                dfs(root, p, q);
                return ans;
            }
        */
};
// int main(){
//     TreeNode *root = new TreeNode(3);
//     TreeNode *node1 = new TreeNode(5);
//     TreeNode *node2 = new TreeNode(1);
//     TreeNode *node3 = new TreeNode(6);
//     TreeNode *node4 = new TreeNode(2);
//     TreeNode *node5 = new TreeNode(0);
//     TreeNode *node6 = new TreeNode(8);
//     TreeNode *node7 = new TreeNode(7);
//     TreeNode *node8 = new TreeNode(4);
//     root->left = node1;
//     root->right = node2;
//     node1->left = node3;
//     node1->right = node4;
//     node2->left = node5;
//     node2->right = node6;
//     node4->left = node7;
//     node4->right = node8;
//     TreeNode *ans = Solution().lowestCommonAncestor(root, node1, node8);
//     return 0;
// }
// @lc code=end

