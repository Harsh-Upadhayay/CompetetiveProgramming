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
    
    vector<int> traversal;
    
    void preorder(TreeNode* root) {
        
        if(!root) return;
        traversal.push_back(root -> val);
        preorder(root -> left);
        preorder(root -> right);
        
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return traversal;
    }
};