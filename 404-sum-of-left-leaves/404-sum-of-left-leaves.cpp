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
    int sum;
    void fun(TreeNode *node, bool isleft = false)
    {
        if(!node) return;
        if(isleft && !node->right && !node->left) { 
            sum += node->val;
            return;
        }
        fun(node->right, false);
        fun(node->left, true);
    }
public:
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        fun(root);
        return sum;
    }
    
};