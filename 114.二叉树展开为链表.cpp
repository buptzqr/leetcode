/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // TreeNode * flattenImpl(TreeNode* root){
    //     if(!root||(!root->left&&!root->right))
    //         return root;
    //     TreeNode *left_flatten = flattenImpl(root->left);
    //     TreeNode *right_flatten = flattenImpl(root->right);
    //     root->right = left_flatten;
    //     root->left = nullptr;
    //     TreeNode* cur = root;
    //     while(cur->right)
    //         cur = cur->right;
    //     cur->right = right_flatten;
    //     return root;
    // }
    // void flatten(TreeNode* root) {
    //     // 笨办法就是依次记录先序遍历的节点
    //     // 当前节点的左右子树分别做flatten
    //     // 将左子树flatten的结果接到当前节点的right
    //     // 将右子树flatten的结果接到左子树flatten的结果后
    //     flattenImpl(root);
    // }
    void flatten(TreeNode* root) {
        // 前序遍历，寻找当前节点右子树的前驱节点（即当前节点左子树的最右节点）
        // 将当前节点的右子树挂在找到的前驱节点的right
        // 将当前节点的左子树挂在当前节点的right
        // 将当前节点的left置为null
        while(root){
            if(!root->left){
                root = root->right;
                continue;
            }
            TreeNode * pre = root->left;
            while(pre->right)
                pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            root = root-> right;
        }
    }
    
};
// int main(){
//     TreeNode *node1 = new TreeNode(1);
//     TreeNode *node2 = new TreeNode(2);
//     TreeNode *node3 = new TreeNode(3);
//     TreeNode *node4 = new TreeNode(4);
//     TreeNode *node5 = new TreeNode(5);
//     TreeNode *node6 = new TreeNode(6);
//     node1->left = node2;
//     node1->right = node5;
//     node2->left = node3;
//     node2->right = node4;
//     node5->right=node6;
//     TreeNode* res =Solution().flattenImpl(node1);
//     return 0;
// }
// @lc code=end

