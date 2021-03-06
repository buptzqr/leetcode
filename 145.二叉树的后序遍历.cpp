/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.*/
#include<vector>
#include<stack>
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
    // struct Command {
    //     string s;
    //     TreeNode* node;
    //     Command(string s,TreeNode* node):s(s),node(node){}
    // };
    // vector<int> postorderTraversal(TreeNode* root) {
    //     // 波神思路
    //     if(!root)
    //         return vector<int>();
    //     vector<int> res;
    //     stack<Command> command_stack;
    //     command_stack.push(Command("visite",root));
    //     while(!command_stack.empty()){
    //         Command c = command_stack.top();
    //         command_stack.pop();
    //         if(c.s == "visite"){
    //             command_stack.push(Command("print val",c.node));
    //             if(c.node->right)
    //                 command_stack.push(Command("visite",c.node->right));
    //             if(c.node->left)
    //                 command_stack.push(Command("visite",c.node->left));
            
    //         }
    //         if(c.s =="print val")
    //             res.push_back(c.node->val);
    //     }
    //     return res; 

    // }
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return vector<int>();
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *last_node=NULL;
        s.push(root);
        while(!s.empty()){
            while(s.top()->left)
                s.push(s.top()->left);
            while(!s.empty()){
                if(last_node ==s.top()->right||!s.top()->right){
                    //last_node ==s.top()->right是为了让有右节点的元素也可以出栈
                    res.push_back(s.top()->val);
                    last_node = s.top();
                    s.pop();
                }
                else if(s.top()->right){
                    s.push(s.top()->right);
                    break;
                }
            }
        }
        return res;
    }

};
// @lc code=end

