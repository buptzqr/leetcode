/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
//直观方法我就直接遍历一遍，然后输出就行，空间复杂度,这个时间和空间复杂度都是o(n)
//可以用栈来实现中序遍历，这样时间和空间复杂度都是o(h+k)h是树的高度
class Solution {
// public:
    // vector<int> nodeVec;
    // void inorderTraverse(TreeNode * root){
    //     if(!root)
    //         return;
    //     inorderTraverse(root->left);
    //     nodeVec.push_back(root->val);
    //     inorderTraverse(root->right);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     inorderTraverse(root);
    //     return nodeVec[k - 1];
    // }
    // solution2
    // int kthSmallest(TreeNode* root, int k) {
    //     if(!root)
    //         throw "the tree is empty";
    //     stack<TreeNode *> s;
    //     int idx = 0;
    //     s.push(root);
    //     while (!s.empty())
    //     {
    //         while(s.top()->left)
    //             s.push(s.top()->left);
    //         while(!s.empty()){
    //             idx++;
    //             TreeNode *node = s.top();
    //             if(idx == k)
    //                 return node->val;
    //             s.pop();
    //             if(node->right){
    //                 s.push(node->right);
    //                 break;
    //             }
    //         }
    //     }
    //     throw "error";
    // }
    //波神的思路：本质就是中序遍历，idx就是记录当前遍历到第几个元素，这样就比较好了解了
    private:
    int index;

    public:
        int kthSmallest(TreeNode* root, int k) {
            index = 0;
            return kthSmallestNode(root, k)->val;
        }

    private:
        TreeNode* kthSmallestNode(TreeNode* node, int k){

            if(node == NULL)
                return NULL;

            TreeNode* res = kthSmallestNode(node->left, k);
            if(res) return res;

            index ++;
            if(index == k)
                return node;

            return kthSmallestNode(node->right, k);
    }
};
// @lc code=end

