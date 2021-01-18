/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res =0;
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        return findPath(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
        
    }
    int findPath(TreeNode* root,int sum){
        if(!root)
            return 0;
        int res = 0;
        if (root->val == sum)
            res++;
        res += findPath(root->left, sum - root->val);
        res += findPath(root->right, sum-root->val);
        return res;
    }
};
// @lc code=end

