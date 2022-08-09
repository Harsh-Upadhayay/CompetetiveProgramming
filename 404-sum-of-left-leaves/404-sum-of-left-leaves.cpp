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
    
public:    
    int sumOfLeftLeaves(TreeNode* node, bool isleft = false) {
        
        if(!node) return 0;
        if(isleft && !node->right && !node->left) 
            return node->val;
        
        return sumOfLeftLeaves(node->right, false) +  sumOfLeftLeaves(node->left, true);
    }
    
};