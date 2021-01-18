/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
// #include <iostream>
// #include <vector>
// #include<queue>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(!root->right&&!root->left)
            if(root->val == sum)
                return true;
            else
                return false;
            // return root->val == sum;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};
// TreeNode* build_tree(int arr[],int n){
//     if(!n)
//         return NULL;
//     TreeNode* head = new TreeNode(arr[0]);
//     //层序建树,当然也可以按照前/中/后序建树，但是一定要注意
//     queue<TreeNode*> q;
//     q.push(head);
//     int cur_idx = 1;
//     while(!q.empty()){
//         TreeNode* cur_node = q.front();
//         q.pop();
//         //NULL用0表示
//         if(arr[cur_idx]==0)
//              cur_node->left == NULL;
//         else{
//              cur_node->left = new TreeNode(arr[cur_idx]);
//              q.push(cur_node->left);
//             }
//         cur_idx++;
//         if(arr[cur_idx]==0)
//              cur_node->right == NULL;
//         else{
//              cur_node->right = new TreeNode(arr[cur_idx]);
//              q.push(cur_node->right);
//             }
//         cur_idx++;
//     }
// }
// @lc code=end
