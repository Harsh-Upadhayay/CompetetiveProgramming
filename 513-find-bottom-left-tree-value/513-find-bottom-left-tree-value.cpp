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
    
    int ans;
    bool ans_found;
    
    int Treeheight(TreeNode* root) {
        
        return root ? max(Treeheight(root -> right), Treeheight(root -> left)) + 1 : 0;
        
    }
    
    void bottomLeft(TreeNode* root, int height, int level = 1) {
        
        if(!root) return;
        bottomLeft(root->left, height, level + 1);
        if(level == height && !ans_found) ans =  root -> val, ans_found = true;
        bottomLeft(root->right, height, level + 1);
    }
    
public:
    int findBottomLeftValue(TreeNode* root) {
        
        ans_found = false;
        int height = Treeheight(root);
        bottomLeft(root, height);
        return ans;
        
    }
};