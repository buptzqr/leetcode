/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
// #include<iostream>
// using namespace std;
// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };
 
class Solution {
public:
  //如果该节点只有一个子节点，那就把这个子节点放在该节点的位置，然后删除
  //如果该节点有两个节点，就把左子树的最右节点，或者右子树的最左节点放到该节点位置
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     if(!root)
    //         return root;
    //     TreeNode* delete_node = root;
    //     TreeNode *delete_node_root = NULL;
    //     while (delete_node)
    //     {
    //         if(delete_node->val<key){
    //             delete_node_root = delete_node;
    //             delete_node = delete_node->right;
    //         }
    //         else if(delete_node->val>key){
    //             delete_node_root = delete_node;
    //             delete_node = delete_node->left;
    //         }
    //         else
    //             break;
    //     }
    //     if(!delete_node)
    //         return root;
    //     if(delete_node->left){
    //         TreeNode *tmp = delete_node->left;
    //         TreeNode *tmp_root = delete_node;
    //         bool flag = false;
    //         while(tmp->right){
    //             tmp_root = tmp;
    //             tmp = tmp->right;
    //             flag = true;
    //         }
    //         delete_node->val = tmp->val;
    //         if(flag)
    //             tmp_root->right = tmp->left;
    //         else
    //             delete_node->left = tmp->left;
    //         delete tmp;
    //     }
    //     else if(delete_node->right){
    //         TreeNode *tmp =delete_node->right;
    //         TreeNode* tmp_root = delete_node;
    //         bool flag = false;
    //         while(tmp->left){
    //             flag = true;
    //             tmp_root= tmp;
    //             tmp = tmp->left;
    //         }
    //         delete_node->val = tmp->val;
    //         cout<<tmp->val<<endl;
    //         if(flag)
    //             tmp_root->left=tmp->right;
    //         else
    //             delete_node->right = tmp->right;
    //         delete tmp; 
    //     }
    //     else {
    //         if(!delete_node_root){
    //             delete delete_node;
    //             return NULL;
    //         }
    //         if(delete_node_root->left==delete_node)
    //             delete_node_root->left = NULL;
    //         else
    //             delete_node_root->right = NULL;
    //         delete delete_node;
    //     }
    //     return root;
    // }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val<key)
            root->right = deleteNode(root->right,key);
        else if(root->val>key)
            root->left = deleteNode(root->left,key);
        else{
            if(!root->left){
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            else if(!root->right){
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            else{
                //记录一下交换节点的根节点
                TreeNode *tmp=root->right;
                TreeNode *tmp_root = root;
                bool flag = false;//这个flag很重要，判断是只有右节点还是右节点还有左子树
                while(tmp->left){
                    flag = true;
                    tmp_root = tmp;
                    tmp=tmp->left;
                }
                swap(root->val,tmp->val);
                if(flag)                
                    tmp_root->left = deleteNode(tmp,key);
                else
                    root->right = deleteNode(tmp,key);
            }
        }
        return root;        
    }

};
// int main(){
//     TreeNode * root=new TreeNode(5);
//     TreeNode * node1=new TreeNode(3);
//     TreeNode * node2=new TreeNode(6);
//     TreeNode * node3=new TreeNode(2);
//     TreeNode * node4=new TreeNode(4);
//     TreeNode * node5=new TreeNode(7);
//     root->left = node1;
//     root->right = node2;
//     node1->left = node3;
//     node1->right = node4;
//     node2->right = node5;
//     root = Solution().deleteNode(root,3);
//     return 0;
// }
// @lc code=end

