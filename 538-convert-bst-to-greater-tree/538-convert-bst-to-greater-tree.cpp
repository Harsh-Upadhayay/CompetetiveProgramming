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
    
    int sum = 0;
    void traverse(TreeNode *root) {
        if(!root) return;
        traverse(root -> right);
        sum = root -> val += sum;
        traverse(root -> left);        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        traverse(root);
        return root;
    }
};