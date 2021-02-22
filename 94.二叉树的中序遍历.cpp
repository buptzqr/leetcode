/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     //传统方法用栈来实现
    //     //将root压入栈中
    //     // 如果当前栈不为空，将栈顶元素的左节点持续压入栈中
    //     // 弹出栈顶元素，进行操作，如果该栈顶元素有右节点，将该节点入栈，重复上一步骤
    //     if(!root)
    //         return vector<int>();
    //     vector<int> res;
    //     stack<TreeNode*> s;
    //     s.push(root);
    //     while(!s.empty()){
    //         while(s.top()->left)
    //             s.push(s.top()->left);
    //         while(!s.empty()){
    //             TreeNode *node =s.top();
    //             s.pop();
    //             res.push_back(node->val);
    //             if(node->right){
    //                 s.push(node->right);
    //                 break;
    //             }                
    //         }
    //     }
    //     return res;
    // }
    // 波神的思路，对于三种遍历都比较统一，使用栈模拟系统栈
    struct Command{
       string s;//go print
       TreeNode *node;
       Command(string s,TreeNode * node):s(s),node(node){} 
    };
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return vector<int>();
        stack<Command> s;
        vector<int> res;
        s.push(Command("go",root));
        while(!s.empty()){
            auto command = s.top();
            s.pop();
            if(command.s=="print")
                res.push_back(command.node->val);
            else{
                if(command.node->right)
                    s.push(Command("go",command.node->right));
                s.push(Command("print",command.node));
                if(command.node->left)
                    s.push(Command("go",command.node->left));
            
            }
        }
        return res;
    }

};
// @lc code=end

 