/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.*/
#include<limits.h>
#include<iostream>
using namespace std;
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
    int findMaxSum(TreeNode* node,int& res){
        if(!node->left&&!node->right){
            res = max(res,node->val);
            return node->val;
        }
        int left_val= INT_MIN;
        int right_val= INT_MIN;
        if(node->left)
            left_val = findMaxSum(node->left,res);
        if(node->right)
            right_val = findMaxSum(node->right,res);
        int ret = INT_MIN;
        if(left_val>0 &&right_val>0){
            ret = node->val+ (left_val>right_val?left_val:right_val);
            res = max(res,node->val+left_val+right_val);
        }
        else{
            ret =node->val+(left_val>0?left_val:0)+(right_val>0?right_val:0);
            res = max(res,ret);
        }
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        findMaxSum(root,res);
        return res;
    }
    /*
     int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
*/
};
// int main(){
//     TreeNode* node1 = new TreeNode(1);
//     TreeNode* node2 = new TreeNode(2);
//     // TreeNode* node3 = new TreeNode(3);
//     node1->left = node2;
//     // node1->right = node3;
//     int res = Solution().maxPathSum(node1);
//     return res;
// }
// @lc code=end

