/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        TreeNode* left_node = root->left;
        TreeNode* right_node = root->right;
        if(left_node&&!left_node->left&&!left_node->right)
            return left_node->val+sumOfLeftLeaves(right_node);
        return sumOfLeftLeaves(left_node) + sumOfLeftLeaves(right_node);
    }
};
// @lc code=end

