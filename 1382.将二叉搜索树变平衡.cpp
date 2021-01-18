/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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
    // 这道题的思路就是利用中序遍历得到有序的数组，然后该数组的中间元素作为二叉树的根，然后使用左右两个部分的数组
    // 分别构建左右子树，为什么这样做是平衡二叉树，使用数学归纳法证明
    void inorderTraverse(TreeNode* root,vector<int>& vecNode){
        if(!root)
            return;
        inorderTraverse(root->left, vecNode);
        vecNode.push_back(root->val);
        inorderTraverse(root->right, vecNode);
    }
    TreeNode* buildTree(int l, int r,vector<int>& vecNode){
        if(l>r)//这个地方可是得小心，这个不是排序
            return NULL;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(vecNode[mid]);
        root->left = buildTree(l, mid - 1, vecNode);
        root->right = buildTree(mid + 1, r, vecNode);
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        //inorder_traverse
        vector<int> vecNode;
        inorderTraverse(root, vecNode);
        return buildTree(0, vecNode.size() - 1, vecNode);
    }
};
//TODO：手撕AVL树
// @lc code=end

