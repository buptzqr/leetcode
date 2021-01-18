/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
class Solution {
public:
    int res = 0;
    //还是用dfs,我这样做就不用还原现场了，因为我这里用的不是引用
    void dfs (TreeNode *root,int x){
        if(!root)
            return;
        x = x*10 + root->val;
        if(!root->left&&!root->right)
            res+=x;
        dfs(root->left,x);
        dfs(root->right,x);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};
// @lc code=end

