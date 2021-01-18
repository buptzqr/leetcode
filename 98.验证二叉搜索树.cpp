/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// 还有一个知识点就是二叉树的中序遍历得到的是一个升序序列
class Solution {
public:
    // 这里迭代思路要注意，我们要判断的是每棵子树的节点在一定范围内，比如
    //     2
    //    / \
    //   1   3
    // 对于1节点所代表的左子树而言，他所有节点的范围要小于2，对3代表的右子树而言，他所有的节点范围要大于2
    // bool helper(TreeNode* root,long long low,long long high){
    //     if(!root)
    //         return true;
    //     if(root->val>=high||root->val<=low){//这里还有一个陷阱就是，如果root->val是INT_MAX或者INT_MIN那么就会出问题，所以起始给出的范围要大于int值的取值范围
    //         return false;
    //     }
    //     return helper(root->left, low, root->val) && helper(root->right, root->val, high);
    // }
    // bool isValidBST(TreeNode* root) {
    //     return helper(root, LONG_MIN, LONG_MAX);
    // }
    //思路二就是按照中序遍历的方式，因为二叉树的中序遍历必然是升序，每次记录前一个元素，和当前元素比较，如果不满足升序，那么就不是二叉树
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        //可以用典型的方式实现中序遍历，也可以用stack来实现
        long long last_val = LONG_MIN;
        cout << last_val << endl;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()){
            while(s.top()->left)
                s.push(s.top()->left);
            while(!s.empty()){
                TreeNode *node = s.top();
                s.pop();
                if(node->val<=last_val){
                    return false;
                }
                last_val = node->val;
                if(node->right){
                    s.push(node->right);
                    break;
                }
            }
        }
        return true;
    }
};

/*
    补充一波用栈来实现前中后序列遍历的思路
    前序遍历（中，左，右）
    1.将根节点放入栈中
    2.如果栈不为空，将栈顶节点出栈并输出，将当前节点的右节点压栈，将当前节点的左节点压栈
    void preorderTraverse(TreeNode* root){
        stack<TreeNode *> s;
        if(!root)
            s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            s.pop();
            cout<<node->val<<endl;
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
        }
        
    }
    中序遍历（左，中，右）
    1.将根节点加入stack中
    2.如果stack不为空，将stack顶端节点的左节点一直压入栈中，直到栈顶元素的左节点为空
    3.如果stack不为空, 将栈顶节点出栈并输出;如果此节点的右节点存在，将右节点压入栈中，重复步骤2，否则重复该步骤
    void inorderTraverse(TreeNode * root){
        stack<TreeNode *> s;
        if(!root)
            s.push(root);
        while(!s.empty()){
            while(s.top()->left)
                s.push(s.top()->left);
            while(!s.empty()){
                TreeNode* node = s.pop();
                cout<<node->val;
                if(node->right){
                    s.push(node->right);
                    break;
                }
            }
        }
    }
    后序遍历（左，右，中）
    主要是需要一个变量来记录上一次输出的节点
    1、如果栈顶元素非空且左节点存在，将其入栈，重复该过程。若不存在则进入第2步（该过程和中序遍历一致）
    2、判断上一次出栈节点是否当前节点的右节点，或者当前节点不存在右节点，满足任一条件，将当前节点输出，并出栈。否则将右节点压栈。跳至第1步
    void postorderTraverse(TreeNode* root){
        stack<TreeNode *> s;
        TreeNode lastNode = NULL;
        if(!root)
            s.push(root);
        while(!s.empty()){
            while(s.top()->left)
                s.push(s.top()->left);
            while (!s.empty()) {
            if (lastNode == s.top()->right || s.top()->right == null) {
                TreeNode node = s.pop();
                cout<<node->val<<endl;
                lastNode = node;
            } else if (s.top()->right != null) {
                s.push(s.top()->right);
                break;
            }
        }
            
        }
        
    }
    
*/
// @lc code=end
